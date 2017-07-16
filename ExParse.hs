module ExParse where

import CppOut
import Formula
import Parser

import Data.List
import System.Process
import Text.Parsec
import Text.Parsec.Expr

--qeString = "load redlog;\nrlset ofsf;\nin \"shape_formulas.red\";\nphi := ex( x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(c, d, l) and (l > 0) and (r > 0) ) );\nval := rlqe phi;\nin \"output.red\"$\nwriteFormula(val);"

--qeString = "load redlog;\nrlset ofsf;\nin \"shape_formulas.red\";\nphi := ex( x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(a, b, l) and (l > 0) and (r > 0) ) );\nval := rlqe phi;\nin \"output.red\"$\nwriteFormula(val);"

qePrefix = "load redlog;\nrlset ofsf;\nin \"shape_formulas.red\";\n"
qeSuffix = "val := rlqe phi$\nin \"output.red\"$\nwriteFormula(val)$"

-- Note: Should add triangle, cuboid, ellipsoid, (quadrialateral?)
circleFm a b r = "inCircleFormula( " ++ a ++ ", " ++ b ++ ", " ++ r ++ " )"
squareFm a b l = "inSquareFormula( " ++ a ++ ", " ++ b ++ ", " ++ l ++ " )"
rectangleFm a b c d = "inRectangleFormula( " ++ (commaList [a, b, c, d]) ++ " )"
onLineFm2D a b = "onLineFormula2D( " ++ a ++ ", " ++ b ++ " )"
ellipseFm a b h k = "inEllipseFormula( " ++ a ++ ", " ++ b ++ ", " ++ h ++ ", " ++ k ++ " )"

sphereFm a b c r = "inSphereFormula( " ++ (commaList [a, b, c, r]) ++ " )"
onPlaneFm a b c d = "onPlaneFormula( " ++ (commaList [a, b, c, d]) ++ " )"
belowPlaneFm a b c d = "belowPlaneFormula( " ++ (commaList [a, b, c, d]) ++ " )"
abovePlaneFm a b c d = "abovePlaneFormula( " ++ (commaList [a, b, c, d]) ++ " )"
cubeFm a b c l = "inCubeFormula( " ++ (commaList[a, b, c, l]) ++ " )"

circleSquareFm = "ex( x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(c, d, l) and (l > 0) and (r > 0) ) )"

circleEllipseFm = "ex( x, ex( y, inCircleFormula(a, b, r) and inEllipseFormula(c, d, h, k) ) )"

sphereCubeFm = "ex( x, ex( y, ex( z, inSphereFormula(a, b, c, r) and inCubeFormula(f, g, h, l) and (l > 0) and (r > 0) ) ) )"

intersectionFm2D a b =
  "ex( x, ex( y, " ++ a ++ " and " ++ b ++ " ) )"

intersectionFm3D a b =
  "ex( x, ex( y, ex( z, " ++ a ++ " and " ++ b ++ " ) ) )"

qeString3D sa sb =
  qePrefix ++ "\nphi := " ++ (intersectionFm3D sa sb) ++ ";\n" ++ qeSuffix

qeString2D sa sb =
  qePrefix ++ "\nphi := " ++ (intersectionFm2D sa sb) ++ ";\n" ++ qeSuffix

main :: IO ()
main = do
  writeFile "qe_input.red" $ qeString3D (sphereFm "a" "b" "c" "r") (cubeFm "j" "k" "l" "m")
  pr <- runCommand "/Volumes/x86_64-mac_10.11_elcapitan-darwin15.0.0_svn3258/reduce.app/Contents/Resources/reduce qe_input.red"
  waitForProcess pr
  a <- readFile "formula_file"
  putStrLn $ preprocessFormulaString a
  let fmStr = preprocessFormulaString a in
   case runParser expr () "expr" fmStr of
    Left err -> putStrLn $ show err
    Right expr -> putStrLn $ cppTestString expr
