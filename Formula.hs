module Formula where

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
  Num Double |
  Var String deriving (Eq, Ord, Show)

commaList [] = ""
commaList (a:[]) = a ++ " "
commaList (a:as) = a ++ ", " ++ (commaList as)

