module ExParse where

import CppOut
import Formula
import Parser

import Data.List
import System.Process
import Text.Parsec
import Text.Parsec.Expr

replace a b s@(x:xs) = if isPrefixOf a s

                     -- then, write 'b' and replace jumping 'a' substring
                     then b++replace a b (drop (length a) s)

                     -- then, write 'x' char and try to replace tail string
                     else x:replace a b xs

replace _ _ [] = []


preprocessFormulaString a =
  replace ". " "" $ replace "**" "^" (filter (\c -> c /= '\n') a)

--qeString = "load redlog;\nrlset ofsf;\nin \"shape_formulas.red\";\nphi := ex( x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(c, d, l) and (l > 0) and (r > 0) ) );\nval := rlqe phi;\nin \"output.red\"$\nwriteFormula(val);"

--qeString = "load redlog;\nrlset ofsf;\nin \"shape_formulas.red\";\nphi := ex( x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(a, b, l) and (l > 0) and (r > 0) ) );\nval := rlqe phi;\nin \"output.red\"$\nwriteFormula(val);"

qePrefix = "load redlog;\nrlset ofsf;\nin \"shape_formulas.red\";\n"
qeSuffix = "val := rlqe phi;\nin \"output.red\"$\nwriteFormula(val);"

qeFormula = "ex( x, ex( y, ex( z, inSphereFormula(a, b, c, r) and inCubeFormula(f, g, h, l) and (l > 0) and (r > 0) ) ) )"

qeString = qePrefix ++ "\nphi := " ++ qeFormula ++ ";\nval := rlqe phi;\n" ++ qeSuffix

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
