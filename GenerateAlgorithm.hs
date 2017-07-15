module GenerateAlgorithm where

import Formula

within_eps_def = "bool within_eps(const double a, const double b, const double eps) {\n\treturn fabs(a - b) < eps;\n}"

algoPrefixCpp eps = "#include <ralg/root_counting.h>\nusing namespace std;\nusing namespace ralg;\n\n" ++ within_eps_def

algorithmTextCpp =
  let eps = 0.0001 in
   algoPrefixCpp eps

main :: IO ()
main = putStrLn $ algorithmTextCpp
