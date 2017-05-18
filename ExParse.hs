module ExParse where

import Formula
import Parser

import Data.List
import Data.Char
import System.Process
import Text.Parsec
import Text.Parsec.Expr

replace a b s@(x:xs) = if isPrefixOf a s

                     -- then, write 'b' and replace jumping 'a' substring
                     then b++replace a b (drop (length a) s)

                     -- then, write 'x' char and try to replace tail string
                     else x:replace a b xs

replace _ _ [] = []

showCppBinopNoParens str a b = (showCpp a) ++ " " ++ str ++ " " ++ (showCpp b)
showCppBinop str a b = "( " ++ (showCppBinopNoParens str a b) ++ " )"

cppVarList :: [String] -> String
cppVarList [] = ""
cppVarList (a:[]) = "const double " ++ a
cppVarList (a:as) = "const double " ++ a ++ ", " ++ (cppVarList as)

varNamesBinop a b = (varNames a) ++ (varNames b)

varNames :: Arith -> [String]
varNames (Times a b) = varNamesBinop a b
varNames (Plus a b) = varNamesBinop a b
varNames (Minus a b) = varNamesBinop a b
varNames (GEQ a b) = varNamesBinop a b
varNames (LEQ a b) = varNamesBinop a b
varNames (EQL a b) = varNamesBinop a b
varNames (NEQ a b) = varNamesBinop a b
varNames (Pow a b) = varNamesBinop a b
varNames (Or a b) = varNamesBinop a b
varNames (And a b) = varNamesBinop a b
varNames (Var i) = if all (\c -> (isDigit c) || (c == '.')) i then [] else [i]
varNames (Num i) = []
varNames e = error $ show e

varNamesUnique expr = nub $ varNames expr

showCppDecl :: Arith -> String
showCppDecl expr = "bool test( " ++ (cppVarList $ varNamesUnique $ expr) ++ " )"

showCpp :: Arith -> String
showCpp (Or a b) = showCppBinop "||" a b
showCpp (And a b) = showCppBinop "&&" a b
showCpp (NEQ a b) = showCppBinop "!=" a b
showCpp (GEQ a b) = showCppBinop ">=" a b
showCpp (LEQ a b) = showCppBinop "<=" a b
showCpp (EQL a b) = showCppBinop "==" a b
showCpp (Times a b) = showCppBinopNoParens "*" a b
showCpp (Minus a b) = showCppBinopNoParens "-" a b
showCpp (Plus a b) = showCppBinopNoParens "+" a b
showCpp (Pow a b) = "pow( " ++ (showCpp a) ++ ", " ++ (showCpp b) ++ " )"
showCpp (Var r) = r

showCpp a = error $ show a

cppTestString expr = "#include<cmath>\n\n" ++ (showCppDecl expr) ++ " { return " ++
                     (showCpp expr) ++ "; }"

preprocessFormulaString a =
  replace ". " "" $ replace "**" "^" (filter (\c -> c /= '\n') a)

--qeString = "load redlog;\nrlset ofsf;\nin \"shape_formulas.red\";\nphi := ex( x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(c, d, l) and (l > 0) and (r > 0) ) );\nval := rlqe phi;\nin \"output.red\"$\nwriteFormula(val);"

--qeString = "load redlog;\nrlset ofsf;\nin \"shape_formulas.red\";\nphi := ex( x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(a, b, l) and (l > 0) and (r > 0) ) );\nval := rlqe phi;\nin \"output.red\"$\nwriteFormula(val);"

qePrefix = "load redlog;\nrlset ofsf;\nin \"shape_formulas.red\";\n"
qeSuffix = "val := rlqe phi;\nin \"output.red\"$\nwriteFormula(val);"

qeString = qePrefix ++ "\nphi := ex( x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(a, b, l) and (l > 0) and (r > 0) ) );\nval := rlqe phi;\n" ++ qeSuffix

main :: IO ()
main = do
  writeFile "qe_input.red" qeString
  pr <- runCommand "/Volumes/x86_64-mac_10.11_elcapitan-darwin15.0.0_svn3258/reduce.app/Contents/Resources/reduce qe_input.red"
  waitForProcess pr
  a <- readFile "formula_file"
  putStrLn $ preprocessFormulaString a
  let fmStr = preprocessFormulaString a in
   case runParser expr () "expr" fmStr of
    Left err -> putStrLn $ show err
    Right expr -> putStrLn $ cppTestString expr
