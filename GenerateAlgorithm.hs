module GenerateAlgorithm where

import Data.Char
import Data.List as L
import Data.List.Split

import System.Process

import Text.Parsec
import Text.Parsec.Expr

import ExParse
import Formula
import Parser
import ReduceParser

within_eps_def = "bool within_eps(const double a, const double b, const double eps) {\n\treturn fabs(a - b) < eps;\n}"

test_points_from_roots_def = "std::vector<rational> test_points_from_roots(const std::vector<rational>& roots) {\nif (roots.size() == 0) { return {};\n } vector<rational> sorted_roots = roots;\n sort(begin(sorted_roots), end(sorted_roots));\n rational one(1);\n rational two(2);\n rational neg_inf = sorted_roots.front() - 1;\n rational pos_inf = sorted_roots.back() + 1;\n vector<rational> test_points;\n test_points.push_back(neg_inf);\n for (int i = 0; i < sorted_roots.size(); i++) {\ntest_points.push_back(sorted_roots[i]);\n if (i < sorted_roots.size() - 1) { rational mid = (sorted_roots[i] + sorted_roots[i + 1]) / two;\n test_points.push_back(mid);\n } } test_points.push_back(pos_inf);\n return test_points;\n }"
  
algoPrefixCpp eps var vars fm = "#include <ralg/root_counting.h>\n\nusing namespace std;\nusing namespace ralg;\n\n#define EPSILON " ++ show eps ++ "\n\n" ++ within_eps_def ++ "\n\n" ++ test_points_from_roots_def ++ "\n\n" ++ (formulaFunctionCpp var vars fm)

fmCppBinop op a b = "( " ++ (formulaCpp a) ++ " " ++ op ++ " " ++ (formulaCpp b) ++ " )"

formulaCpp (Var x) = x
formulaCpp (EQL a b) = "within_eps( " ++ (commaList $ map formulaCpp [a, b]) ++ ", EPSILON )"
formulaCpp (LEQ a b) = fmCppBinop "<=" a b
formulaCpp (GEQ a b) = fmCppBinop ">=" a b
formulaCpp (Plus a b) = fmCppBinop "+" a b
formulaCpp (Times a b) = fmCppBinop "*" a b
formulaCpp (Minus a b) = fmCppBinop "-" a b
formulaCpp (Or a b) = fmCppBinop "||" a b
formulaCpp (Pow a b) = "pow( " ++(formulaCpp a) ++ ", " ++ formulaCpp b ++ " )"
formulaCpp (And a b) = fmCppBinop "&&" a b
formulaCpp (Formula.NEQ a b) = "!within_eps( " ++ (commaList $ map formulaCpp [a, b]) ++ ", EPSILON )"
formulaCpp (Num x) = show x
formulaCpp e = error $ "formulaCpp = " ++ show e

varStrings (Var x) = [x]
varStrings (EQL a b) = (varStrings a) ++ (varStrings b)
varStrings (LEQ a b) = (varStrings a) ++ (varStrings b)
varStrings (GEQ a b) = (varStrings a) ++ (varStrings b)
varStrings (Plus a b) = (varStrings a) ++ (varStrings b)
varStrings (Minus a b) = (varStrings a) ++ (varStrings b)
varStrings (Times a b) = (varStrings a) ++ (varStrings b)
varStrings (Formula.NEQ a b) = (varStrings a) ++ (varStrings b)
varStrings (Or a b) = (varStrings a) ++ (varStrings b)
varStrings (And a b) = (varStrings a) ++ (varStrings b)
varStrings (Num _) = []
varStrings (Pow a b) = (varStrings a) ++ (varStrings b)
varStrings fm = error $ "varStrings cannot process = " ++ (show fm)

varStrs fm = L.nub $ varStrings fm

formulaFunctionCpp var@(Var s) vars fm =
  let varStr = commaList $ L.map (\s -> "const double " ++ s) (vars ++ [s]) in
   "bool formula(" ++ varStr ++ ") {\n" ++ "\treturn " ++ (formulaCpp fm) ++ ";\n}\n"

collectPolys (EQL a b) = [a, b]
collectPolys (LEQ a b) = [a, b]
collectPolys (GEQ a b) = [a, b]
collectPolys (Formula.NEQ a b) = [a, b]
collectPolys (Or a b) = (collectPolys a) ++ (collectPolys b)
collectPolys (And a b) = (collectPolys a) ++ (collectPolys b)
collectPolys fm = error $ "collectPolys = " ++ show fm

collectPolynomials fm = L.nub $ collectPolys fm

isNum (Num _) = True
isNum (Var a) = isNumberStr a
isNum _ = False

varZeros nVars varNum =
  let zeroIndexVarNum = varNum - 1
      start = L.replicate zeroIndexVarNum 0
      end = L.replicate (nVars - zeroIndexVarNum - 1) 0 in
   L.map show $ start ++ [1] ++ end

declareMonomial nVars varNum s =
  "\tmonomial m_" ++ s ++ "(1, {" ++ (commaList $ varZeros nVars varNum) ++ "}, " ++ show nVars ++ ");\n"

declareMonomials varList =
  let varNums = [1..(length varList)] in
   L.concatMap (\(v, n) -> declareMonomial (length varList) n v) $ L.zip varList varNums

declarePolynomial nVars var =
  "\tpolynomial " ++ var ++ "({m_" ++ var ++ "}, " ++ show nVars ++ ");\n"

declarePolynomials varList p =
   L.concatMap (declarePolynomial (length varList)) $ varList 

constructPolynomial p = formulaCpp p

constructPolynomialCpp p =
  "\tpolynomial result_polynomial_21393 = " ++ (constructPolynomial p) ++ ";"

buildPolynomialCpp :: Arith -> [String] -> Arith -> String
buildPolynomialCpp var@(Var s) vars p =
  let varList = vars ++ [s] in
   (declareMonomials varList) ++ "\n\n" ++ (declarePolynomials varList p) ++ "\n\n" ++ (constructPolynomialCpp p)

-- TODO: Make functions names unique
polynomialFunction polyNum var vars p = "polynomial make_polynomial_" ++ show polyNum ++ "() {\n" ++ (buildPolynomialCpp var vars p) ++ "\n\treturn result_polynomial_21393;\n}"

algoPolysCpp ps var vars fm =
   L.concatMap (\(s, polyNum) -> (polynomialFunction polyNum var vars s) ++ "\n\n") $ L.zip ps $ [1..(length ps)]

varsAsRationals vars = commaList $ L.map (\s -> "{" ++ s ++ "}") vars

polynomialConstructionCalls numPolys =
  commaList $ L.map (\n -> "make_polynomial_" ++ show n ++ "()") $ [1..numPolys]

shapesIntersectBodyCpp vars numPolys = 
  "\tvector<polynomial> polys{" ++ (polynomialConstructionCalls numPolys) ++ "};\n\t" ++
  "vector<rational> rs{" ++ varsAsRationals vars ++ "};\n\t" ++ --{a}, {b}, {c}, {d}, {f} };\n\t" ++ 
  "vector<polynomial> upolys;\n\t" ++
  "for (auto& p : polys) {\n\t" ++
    "\tpolynomial p_univariate = evaluate_at(rs, p);\n\t" ++
    "\tupolys.push_back(p_univariate);\n\t" ++
  "}\n\t" ++
  "return test_formula_at_sample_points(" ++ commaList vars ++ ", upolys);\n" --a, b, c, d, f , upolys);\n"

shapesIntersect var@(Var s) vars numPolys =
  let varList = vars in
   "bool shapes_intersect( " ++ (commaList $ L.map (\s -> "const double " ++ s) varList) ++ ") {\n" ++ (shapesIntersectBodyCpp vars numPolys) ++ "\n}"

testFormulaPointsBody vars =
  "\n\trational max_width(0.0001);\n\tvector<interval> roots;\n\t" ++
  "for (auto& p_univariate : upolys) {\n\t" ++
  "\tconcat(roots, isolate_roots(p_univariate, max_width));\n\t" ++
  "}\n\t" ++
  "vector<rational> points;\n\trational two(2);\n\t for (auto& it : roots) {\n\t\t points.push_back((it.start.value + it.end.value) / two);\n\t }\n\n\t vector<rational> test_points = test_points_from_roots(points);\n\tif (test_points.size() == 0) {\n\t\treturn formula(" ++ (commaList vars) ++ ", 0.0);\n\t }\n\n\tfor (auto& pt : test_points) { double test_x = pt.to_double();\n\t bool fm_true = formula(" ++ (commaList vars) ++ ", test_x);\n\t cout << \"At x = \" << test_x << \" the formula is \" << fm_true << endl;\n\t if (fm_true) {\n\t\treturn true;\n\t }\n\t}\n\treturn false;\n\t"

testFormulaPoints vars = "bool test_formula_at_sample_points(" ++ (commaList $ L.map (\s -> "const double " ++ s) vars) ++ ", const std::vector<polynomial>& upolys) {" ++ (testFormulaPointsBody vars) ++ "\n}"

evaluationCode var vars fm numPolys =
  (testFormulaPoints vars) ++ "\n\n" ++ (shapesIntersect var vars numPolys)

isNumberStr :: String -> Bool
isNumberStr f =
  isNumber $ f !! 0

algorithmTextCpp :: Arith -> Arith -> String
algorithmTextCpp var@(Var s) fm =
  let eps = 0.0001
      vars = L.filter (\v -> not $ isNumberStr v) $ L.delete s $ L.sort $ varStrs fm
      ps = L.filter (\s -> not $ isNum s) $ collectPolynomials fm in
   (algoPrefixCpp eps var vars fm) ++ "\n\n" ++ (algoPolysCpp ps var vars fm) ++ "\n\n" ++ (evaluationCode var vars fm (L.length ps))

fm = EQL (Minus (Minus (Plus (Times (Var "a") (Var "x")) (Var "b")) (Times (Var "c") (Var "x"))) (Var "d")) (Num 0.0)

extractExpLocations :: String -> [(Int, Char)]
extractExpLocations [] = []
extractExpLocations expLine =
  let nextExpLoc = L.findIndex (\c -> not $ isSpace c) expLine in
   case nextExpLoc of
    Nothing -> []
    Just loc ->
      let power = expLine !! loc
          rest = L.drop (loc + 1) expLine in
       (loc, power):(extractExpLocations rest)

truncateExps expLoc locs =
  L.map (\(loc, power) -> (loc - expLoc, power)) locs

mergeExps a [] = a
mergeExps a ((expLoc, power):locs) =
  let aBefore = L.take (expLoc + 1) a
      aAfter = L.drop (expLoc + 1) a in
   aBefore ++ "^" ++ [power] ++ (mergeExps aAfter locs)

mergeExpAndArithLines a b =
  let expLocations = extractExpLocations a in
   mergeExps b expLocations

groupExpsAndArith [] = ""
groupExpsAndArith (a:b:as) = (mergeExpAndArithLines a b) ++ " " ++ (groupExpsAndArith as)

preprocessedReduceString a =
  groupExpsAndArith $ L.filter (\s -> s /= "") $ splitOn "\n" a

aExprToFm (RVar s) = (Var s)
aExprToFm (ABinary Multiply a b) = Times (aExprToFm a) (aExprToFm b)
aExprToFm (ABinary Subtract a b) = Minus (aExprToFm a) (aExprToFm b)
aExprToFm (ABinary Add a b) = Plus (aExprToFm a) (aExprToFm b)
aExprToFm (ABinary Exp a b) = Pow (aExprToFm a) (aExprToFm b)
aExprToFm (IntConst s) = (Num $ fromInteger s)
aExprToFm a = error $ "aExprToFm = " ++ show a

bExprToFm (RBinary Equal a b) = EQL (aExprToFm a) (aExprToFm b)
bExprToFm (RBinary GreaterEqual a b) = GEQ (aExprToFm a) (aExprToFm b)
bExprToFm (RBinary LessEqual a b) = LEQ (aExprToFm a) (aExprToFm b)
bExprToFm (RBinary ReduceParser.NEQ a b) = Formula.NEQ (aExprToFm a) (aExprToFm b)
bExprToFm (BBinary RAnd a b) = And (bExprToFm a) (bExprToFm b)
bExprToFm (BBinary ROr a b) = Or (bExprToFm a) (bExprToFm b)
bExprToFm fm = error $ show fm

main :: IO ()
main = do
  writeFile "qe_input.red" $ qeString3D (sphereFm "a" "b" "c" "r") (cubeFm "j" "k" "l" "m")
  pr <- runCommand "./run_reduce.txt qe_input.red"
  waitForProcess pr
  a <- readFile "fresh_file"
  putStrLn $ preprocessedReduceString a
  let fmStr = preprocessedReduceString a in
   case runParser bExpression () "expr" fmStr of
    Left err -> putStrLn $ show err
    Right expr -> putStrLn $ algorithmTextCpp (Var "x") $ bExprToFm expr

l1 = "                       2    2            2"
l2 = "(c <> 0 and (d = 0 or c  - h  + 2*h*x - x  >= 0) and ((b - k <= 0 and "
  
