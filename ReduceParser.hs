import System.IO
import Control.Monad
import Text.ParserCombinators.Parsec
import Text.ParserCombinators.Parsec.Expr
import Text.ParserCombinators.Parsec.Language
import qualified Text.ParserCombinators.Parsec.Token as Token

data BExpr = BoolConst Bool
            | Not BExpr
            | BBinary BBinOp BExpr BExpr
            | RBinary RBinOp AExpr AExpr
             deriving (Show)

data BBinOp = And | Or deriving (Show)

data RBinOp = Greater | Less deriving (Show)

data AExpr = Var String
            | IntConst Integer
            | Neg AExpr
            | ABinary ABinOp AExpr AExpr
              deriving (Show)

data ABinOp = Add
             | Subtract
             | Multiply
             | Divide
               deriving (Show)

data Stmt = Seq [Stmt]
           | Assign String AExpr
           | If BExpr Stmt Stmt
           | While BExpr Stmt
           | Skip
             deriving (Show)

languageDef =
   emptyDef { Token.commentStart    = "/*"
            , Token.commentEnd      = "*/"
            , Token.commentLine     = "//"
            , Token.identStart      = letter
            , Token.identLetter     = alphaNum
            , Token.reservedNames   = [ "if"
                                      , "then"
                                      , "else"
                                      , "while"
                                      , "do"
                                      , "skip"
                                      , "true"
                                      , "false"
                                      , "not"
                                      , "and"
                                      , "or"
                                      ]
            , Token.reservedOpNames = ["+", "-", "*", "/", ":=", "=", "<>", "^"
                                      , "<", ">", "and", "or", "not"
                                      ]
            }

lexer = Token.makeTokenParser languageDef

