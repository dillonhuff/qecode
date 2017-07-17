module Formula where

import Data.List

data Arith =
  Times Arith Arith |
  Plus Arith Arith |
  Minus Arith Arith |
  Pow Arith Arith |
  NEQ Arith Arith |
  GEQ Arith Arith |
  LEQ Arith Arith |
  EQL Arith Arith |
  GREATER Arith Arith |
  LESS Arith Arith |
  And Arith Arith |
  Or Arith Arith |
  Neg Arith |
  Num Double |
  Var String deriving (Eq, Ord, Show)

commaList [] = ""
commaList (a:[]) = a ++ " "
commaList (a:as) = a ++ ", " ++ (commaList as)


replace a b s@(x:xs) = if isPrefixOf a s

                     -- then, write 'b' and replace jumping 'a' substring
                     then b++replace a b (drop (length a) s)

                     -- then, write 'x' char and try to replace tail string
                     else x:replace a b xs

replace _ _ [] = []

preprocessFormulaString a =
  replace ". " "" $ replace "**" "^" (filter (\c -> c /= '\n') a)

