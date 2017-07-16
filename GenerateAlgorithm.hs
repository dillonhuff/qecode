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
polynomialFunction var vars p = "polynomial make_polynomial() {\n" ++ (buildPolynomialCpp var vars p) ++ "\n\treturn result_polynomial_21393;\n}"

algoPolysCpp var vars fm =
  let ps = L.filter (\s -> not $ isNum s) $ collectPolys fm in
   L.concatMap (polynomialFunction var vars) ps

varsAsRationals vars = commaList $ L.map (\s -> "{" ++ s ++ "}") vars

shapesIntersectBodyCpp vars =
  "\tpolynomial p = make_polynomial();\n\tvector<rational> rs{" ++ (varsAsRationals vars) ++ "};\n\tpolynomial p_univariate = evaluate_at(rs, p);\n\treturn test_formula_at_sample_points(" ++ (commaList vars) ++ ", p_univariate);"

shapesIntersect var@(Var s) vars =
  let varList = vars in
   "bool shapes_intersect( " ++ (commaList $ L.map (\s -> "const double " ++ s) varList) ++ ") {\n" ++ (shapesIntersectBodyCpp vars) ++ "\n}"

testFormulaPointsBody vars = "rational max_width(0.0001);\n\tvector<interval> roots = isolate_roots(p_univariate, max_width);\n\tvector<rational> points;\n\trational two(2);\n\t for (auto& it : roots) {\n\t\t points.push_back((it.start.value + it.end.value) / two);\n\t }\n\n\tif (test_points.size() == 0) {\n\t\treturn formula(" ++ (commaList vars) ++ ", 0.0);\n\t }\n\n\tfor (auto& pt : test_points) { double test_x = pt.to_double();\n\t bool fm_true = formula(" ++ (commaList vars) ++ ", test_x);\n\t cout << \"At x = \" << test_x << \" the formula is \" << fm_true << endl;\n\t if (fm_true) {\n\t\treturn true;\n\t }\n\t}\n\treturn false;\n\t"

testFormulaPoints vars = "bool test_formulas_at_sample_points(" ++ (commaList $ L.map (\s -> "const double " ++ s) vars) ++ ", const polynomial& p_univariate) {" ++ (testFormulaPointsBody vars) ++ "\n}"

evaluationCode var vars fm =
  (testFormulaPoints vars) ++ "\n\n" ++ (shapesIntersect var vars)

algorithmTextCpp :: Arith -> Arith -> String
algorithmTextCpp var@(Var s) fm =
  let eps = 0.0001
      vars = L.delete s $ L.sort $ varStrs fm in
   (algoPrefixCpp eps var vars fm) ++ "\n\n" ++ (algoPolysCpp var vars fm) ++ "\n\n" ++ (evaluationCode var vars fm)

fm = EQL (Minus (Minus (Plus (Times (Var "a") (Var "x")) (Var "b")) (Times (Var "c") (Var "x"))) (Var "d")) (Num 0.0)

main :: IO ()
main = putStrLn $ algorithmTextCpp (Var "x") fm
