module Output where

import Text.Parsec.Combinator
import Text.ParserCombinators.Parsec.Combinator
import Text.Parsec (ParseError)
import Text.ParserCombinators.Parsec
import Text.Parsec.String

data Expr = Expr deriving (Eq, Ord, Show)

data Comparator = EQ | NEQ | GEQ | LEQ deriving (Eq, Ord, Show)

data Formula = 
  And [Formula] |
  Or [Formula] |
  Term Comparator Expr Expr deriving (Eq, Ord, Show)


pFormula = do
  char '('
  a <- many1 (char 'a')
  char ')'
  return (Or [])

  -- do
  -- char '('
  -- a <- many1 "abcdefghijklmnopqrstuvwxyz123456789-+=<*"
  -- char ')'
  -- return (Or [])

parseFormula :: String -> Either ParseError Formula
parseFormula input = parse pFormula "(unknown)" input

main :: IO ()
main = do
  a <- readFile "val_example.txt"
  putStrLn a
