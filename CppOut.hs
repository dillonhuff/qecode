module CppOut where

import Formula

import Data.Char
import Data.List

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

cppTestString expr = "#include <cmath>\n\n" ++ (showCppDecl expr) ++ " { return " ++
                     (showCpp expr) ++ "; }"
