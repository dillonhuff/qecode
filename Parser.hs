module Parser where

import Data.List
import Data.Char
import Text.Parsec
import Text.Parsec.Expr

import Formula

parens :: (Monad m) => ParsecT String u m a -> ParsecT String u m a
parens p = do
  spaces
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
  front <- many1 digit
  char '.'
  back <- many1 digit
  --f <- floating
  return $ (Num . read) $ (front ++ "." ++ back)
  --fmap (Num . read) $ many1 digit

variable = do
  spaces
  chars <- many1 (alphaNum <|> (char '.'))
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
          , [binary "<>" NEQ AssocLeft, binary ">=" GEQ AssocLeft,
             binary "<=" LEQ AssocLeft, binary "=" EQL AssocLeft,
             binary ">" LESS AssocLeft, binary "<" GREATER AssocLeft]
          , [binary "and" And AssocLeft, binary "or" Or AssocLeft]
          ]

binary  name fun assoc = Infix (do{ reservedOp name; return fun }) assoc
prefix  name fun       = Prefix (do{ reservedOp name; return fun })
postfix name fun       = Postfix (do{ reservedOp name; return fun })

res = runParser expr () "expr" "2+a"

