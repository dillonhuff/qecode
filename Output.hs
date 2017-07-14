module Output where

import Text.Parsec.Combinator
import Text.Parsec.Expr
import Text.Parsec.Token
import Text.ParserCombinators.Parsec.Combinator
import Text.Parsec (ParseError)
import Text.ParserCombinators.Parsec
import Text.Parsec.String

data Expr = Expr deriving (Eq, Ord, Show)

data Comparator = EQL | NEQ | GEQ | LEQ deriving (Eq, Ord, Show)

data Formula = 
  And [Formula] |
  Or [Formula] |
  Term Comparator Expr Expr deriving (Eq, Ord, Show)

expr    = buildExpressionParser table term
         <?> "expression"

term    =  parens expr 
          <|> natural
          <?> "simple expression"

table   = [ [prefix "-" negate, prefix "+" id ]
            , [postfix "++" (+1)]
            , [binary "*" (*) AssocLeft, binary "/" (div) AssocLeft ]
            , [binary "+" (+) AssocLeft, binary "-" (-)   AssocLeft ]
            ]
         
binary  name fun assoc = Infix (do{ reservedOp name; return fun }) assoc
prefix  name fun       = Prefix (do{ reservedOp name; return fun })
postfix name fun       = Postfix (do{ reservedOp name; return fun })
                          
main :: IO ()
main = do
  a <- readFile "val_example.txt"
  putStrLn a
  -- case parseFormula a of
  --  Left e -> putStrLn $ show e
  --  Right f -> putStrLn $ show f
