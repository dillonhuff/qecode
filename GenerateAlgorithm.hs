module GenerateAlgorithm where

import Data.List as L

import Formula

within_eps_def = "bool within_eps(const double a, const double b, const double eps) {\n\treturn fabs(a - b) < eps;\n}"

test_points_from_roots_def = "std::vector<rational> test_points_from_roots(const std::vector<rational>& roots) {\nif (roots.size() == 0) { return {};\n } vector<rational> sorted_roots = roots;\n sort(begin(sorted_roots), end(sorted_roots));\n rational one(1);\n rational two(2);\n rational neg_inf = sorted_roots.front() - 1;\n rational pos_inf = sorted_roots.back() + 1;\n vector<rational> test_points;\n test_points.push_back(neg_inf);\n for (int i = 0; i < sorted_roots.size(); i++) {\ntest_points.push_back(sorted_roots[i]);\n if (i < sorted_roots.size() - 1) { rational mid = (sorted_roots[i] + sorted_roots[i + 1]) / two;\n test_points.push_back(mid);\n } } test_points.push_back(pos_inf);\n return test_points;\n }"
  
algoPrefixCpp eps var vars fm = "#include <ralg/root_counting.h>\n\nusing namespace std;\nusing namespace ralg;\n\n#define EPSILON " ++ show eps ++ "\n\n" ++ within_eps_def ++ "\n\n" ++ test_points_from_roots_def ++ "\n\n" ++ (formulaFunctionCpp var vars fm)

fmCppBinop op a b = "( " ++ (formulaCpp a) ++ " " ++ op ++ " " ++ (formulaCpp b) ++ " )"

formulaCpp (Var x) = x
formulaCpp (EQL a b) = "within_eps( " ++ (commaList $ map formulaCpp [a, b]) ++ ", EPSILON )"
formulaCpp (Plus a b) = fmCppBinop "+" a b
formulaCpp (Times a b) = fmCppBinop "*" a b
formulaCpp (Minus a b) = fmCppBinop "-" a b
formulaCpp (Num x) = show x

varStrings (Var x) = [x]
varStrings (EQL a b) = (varStrings a) ++ (varStrings b)
varStrings (Plus a b) = (varStrings a) ++ (varStrings b)
varStrings (Minus a b) = (varStrings a) ++ (varStrings b)
varStrings (Times a b) = (varStrings a) ++ (varStrings b)
varStrings (Num _) = []

varStrs fm = L.nub $ varStrings fm

formulaFunctionCpp var@(Var s) vars fm =
  let varStr = commaList $ L.map (\s -> "const double " ++ s) (vars ++ [s]) in
   "bool formula(" ++ varStr ++ ") {\n" ++ "\treturn " ++ (formulaCpp fm) ++ ";\n}\n"

collectPolys (EQL a b) = [a, b]

isNum (Num _) = True
isNum _ = False

declareMonomial nVars varNum s = "\tmonomial " ++ s ++ "(1, {}, " ++ show nVars ++ ");\n"

declareMonomials varList =
  let varNums = [1..(length varList)] in
   L.concatMap (\(v, n) -> declareMonomial (length varList) n v) $ L.zip varList varNums

declarePolynomials varList = ""

buildPolynomialCpp :: Arith -> [String] -> Arith -> String
buildPolynomialCpp var@(Var s) vars p =
  let varList = vars ++ [s] in
   (declareMonomials varList) ++ "\n\n" ++ (declarePolynomials varList)

-- TODO: Make these unique
polynomialFunction var vars p = "polynomial make_polynomial() {\n" ++ (buildPolynomialCpp var vars p) ++ ";\n\treturn p;\n}"

algoPolysCpp var vars fm =
  let ps = L.filter (\s -> not $ isNum s) $ collectPolys fm in
   L.concatMap (polynomialFunction var vars) ps

algorithmTextCpp :: Arith -> Arith -> String
algorithmTextCpp var@(Var s) fm =
  let eps = 0.0001
      vars = L.delete s $ L.sort $ varStrs fm in
   (algoPrefixCpp eps var vars fm) ++ "\n\n" ++ (algoPolysCpp var vars fm)

fm = EQL (Minus (Minus (Plus (Times (Var "a") (Var "x")) (Var "b")) (Times (Var "c") (Var "x"))) (Var "d")) (Num 0.0)

main :: IO ()
main = putStrLn $ algorithmTextCpp (Var "x") fm
