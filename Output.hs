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

-- parseTerm = do
--   spaces
--   char '('
  
--   char ')'
--   return (Term EQL Expr Expr)

-- parseClause str = return $ Or []
--   -- char '('
--   -- --fms <- sepBy pFormula (symbol str)
--   -- char ')'
--   -- case str of
--   --  "||" -> return $ Or []
--   --  "&&" -> return $ And []

-- pFormula = do
--   char '('
--   newline
--   spaces
--   a <- (parseClause "||") <|> (parseClause "&&") <|> parseTerm
--   char ')'
--   return a

  -- do
  -- char '('
  -- a <- many1 "abcdefghijklmnopqrstuvwxyz123456789-+=<*"
  -- char ')'
  -- return (Or [])

-- parseFormula :: String -> Either ParseError Formula
-- parseFormula input = parse pFormula "(unknown)" input

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
