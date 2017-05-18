module ExParse where

import Text.Parsec
import Text.Parsec.Expr

--import Text.Parsec.Token (parens)

data Arith =
  Times Arith Arith |
  Plus Arith Arith |
  Minus Arith Arith |
  Neg Arith deriving (Eq, Ord, Show)
  
parens :: (Monad m) => ParsecT String u m a -> ParsecT String u m a
parens p = do
    char '('
    e <- p
    char ')'
    return e

reservedOp :: (Monad m) => String -> ParsecT String u m ()
reservedOp s = do
    string s
    notFollowedBy letter

natural = fmap read $ many1 digit

expr    = buildExpressionParser table term

term    =  parens expr 
           <|> natural
           <?> "simple expression"

table   = [ [prefix "-" negate, prefix "+" id ]
          , [postfix "++" (+1), postfix "--" (subtract 1)]
          , [binary "**" (*) AssocLeft]
          , [binary "*" (*) AssocLeft, binary "/" (div) AssocLeft ]
          , [binary "+" (+) AssocLeft, binary "-" (-)   AssocLeft ]
          ]

binary  name fun assoc = Infix (do{ reservedOp name; return fun }) assoc
prefix  name fun       = Prefix (do{ reservedOp name; return fun })
postfix name fun       = Postfix (do{ reservedOp name; return fun })

res = runParser expr () "expr" "(3**1)"

main :: IO ()
main = putStrLn $ show res
