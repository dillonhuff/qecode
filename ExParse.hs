module ExParse where

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
          , [binary "**" Pow AssocLeft]
          , [binary "*" Times AssocLeft] --, binary "/" (div) AssocLeft ]
          , [binary "+" Plus AssocLeft, binary "-" Minus AssocLeft ]
          , [binary "!=" NEQ AssocLeft, binary ">=" GEQ AssocLeft]
          , [binary "&&" And AssocLeft]
          ]

binary  name fun assoc = Infix (do{ reservedOp name; return fun }) assoc
prefix  name fun       = Prefix (do{ reservedOp name; return fun })
postfix name fun       = Postfix (do{ reservedOp name; return fun })

res = runParser expr () "expr" "2+a"

main :: IO ()
main = do
  a <- readFile "val_example_no_newlines.txt"
  putStrLn $ show $ runParser expr () "expr" a
