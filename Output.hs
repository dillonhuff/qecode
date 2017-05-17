module Output where

data Expr = Expr deriving (Eq, Ord, Show)

data Comparator = EQ | NEQ | GEQ | LEQ deriving (Eq, Ord, Show)

data Formula =
  And Formula Formula |
  Or Formula Formula |
  Term Comparator Expr Expr deriving (Eq, Ord, Show)

main :: IO ()
main = putStrLn "Hello"
