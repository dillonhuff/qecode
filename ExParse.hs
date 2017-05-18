module ExParse where

import Data.List
import Data.Char
import Text.Parsec
import Text.Parsec.Expr

data Arith =
  Times Arith Arith |
  Plus Arith Arith |
  Minus Arith Arith |
  Pow Arith Arith |
  NEQ Arith Arith |
  GEQ Arith Arith |
  LEQ Arith Arith |
  EQL Arith Arith |
  And Arith Arith |
  Or Arith Arith |
  Neg Arith |
  Num Int |
  Var String deriving (Eq, Ord, Show)

showCppBinop str a b = "( " ++ (showCpp a) ++ " " ++ str ++ " " ++ (showCpp b) ++ " )"

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
varNames (Var i) = if all (\c -> isDigit c) i then [] else [i]
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
showCpp (Times a b) = showCppBinop "*" a b --(showCpp a) ++ " + " ++ (showCpp b)
showCpp (Minus a b) = showCppBinop "-" a b
showCpp (Plus a b) = showCppBinop "+" a b
showCpp (Pow a b) = "pow( " ++ (showCpp a) ++ ", " ++ (showCpp b) ++ " )"
showCpp (Var r) = r

showCpp a = error $ show a

parens :: (Monad m) => ParsecT String u m a -> ParsecT String u m a
parens p = do
    char '('
    spaces
    e <- p
    spaces
    char ')'
    spaces
    return e

reservedOp :: (Monad m) => String -> ParsecT String u m ()
reservedOp s = do
    string s
    return ()
--    notFollowedBy letter

natural = do
  spaces
  fmap (Num . read) $ many1 digit

variable = do
  spaces
  chars <- many1 alphaNum
  spaces
  return $ Var chars

expr    = buildExpressionParser table term

term    =  parens expr
           <|> variable
           <|> natural
           <?> "simple expression"

table   = [ [prefix "-" Neg, prefix "+" id ]
          , [binary "^" Pow AssocLeft]
          , [binary "*" Times AssocLeft] --, binary "/" (div) AssocLeft ]
          , [binary "+" Plus AssocLeft, binary "-" Minus AssocLeft ]
          , [binary "!=" NEQ AssocLeft, binary ">=" GEQ AssocLeft,
             binary "<=" LEQ AssocLeft, binary "==" EQL AssocLeft]
          , [binary "&&" And AssocLeft, binary "||" Or AssocLeft]
          ]

binary  name fun assoc = Infix (do{ reservedOp name; return fun }) assoc
prefix  name fun       = Prefix (do{ reservedOp name; return fun })
postfix name fun       = Postfix (do{ reservedOp name; return fun })

res = runParser expr () "expr" "2+a"

main :: IO ()
main = do
  a <- readFile "val_example_no_newlines_caret.txt"
  case runParser expr () "expr" a of
   Left err -> putStrLn $ show err
   Right expr -> putStrLn $ (showCppDecl expr) ++ " { return " ++ (showCpp expr) ++ "; }"
