module ReduceParser where

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

data BBinOp = RAnd | ROr deriving (Show)

data RBinOp = Greater | Less | NEQ | Equal deriving (Show)

data AExpr = RVar String
            | IntConst Integer
            | FloatConst Double
            | Neg AExpr
            | RPow AExpr
            | ABinary ABinOp AExpr AExpr
              deriving (Show)

data ABinOp = Add
             | Subtract
             | Multiply
             | Divide
             | Exp
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
            , Token.reservedOpNames = ["+", "-", "*", "/", "=", "<>", "^",
                                       ">=", "<="
                                      , "<", ">", "and", "or", "not"
                                      ]
            }

lexer = Token.makeTokenParser languageDef

identifier = Token.identifier lexer -- parses an identifier
reserved   = Token.reserved   lexer -- parses a reserved name
reservedOp = Token.reservedOp lexer -- parses an operator
parens     = Token.parens     lexer -- parses surrounding parenthesis:
                                     --   parens p
                                     -- takes care of the parenthesis and
                                     -- uses p to parse what's inside them
integer    = Token.integer    lexer -- parses an integer
float      = Token.float      lexer -- Parses a floating point number
semi       = Token.semi       lexer -- parses a semicolon
whiteSpace = Token.whiteSpace lexer -- parses whitespace

aExpression :: Parser AExpr
aExpression = buildExpressionParser aOperators aTerm
 
bExpression :: Parser BExpr
bExpression = buildExpressionParser bOperators bTerm

aOperators = [ [Prefix (reservedOp "-"   >> return (Neg             ))          ,
                Infix (reservedOp "^" >> return (ABinary Exp)) AssocLeft]
              , [Infix  (reservedOp "*"   >> return (ABinary Multiply)) AssocLeft,
                 Infix  (reservedOp "/"   >> return (ABinary Divide  )) AssocLeft]
              , [Infix  (reservedOp "+"   >> return (ABinary Add     )) AssocLeft,
                 Infix  (reservedOp "-"   >> return (ABinary Subtract)) AssocLeft]
               ]
bOperators = [ [Prefix (reservedOp "not" >> return (Not             ))          ]
              , [Infix  (reservedOp "and" >> return (BBinary RAnd     )) AssocLeft,
                 Infix  (reservedOp "or"  >> return (BBinary ROr      )) AssocLeft]
              ]             

aTerm =  parens aExpression
      <|> liftM RVar identifier
      <|> liftM IntConst integer
      <|> liftM FloatConst float

bTerm =  parens bExpression
      <|> (reserved "true"  >> return (BoolConst True ))
      <|> (reserved "false" >> return (BoolConst False))
      <|> rExpression


rExpression =
   do a1 <- aExpression
      op <- relation
      a2 <- aExpression
      return $ RBinary op a1 a2
 
relation =   (reservedOp ">" >> return Greater)
             <|> (reservedOp ">=" >> return Equal)
             <|> (reservedOp "<=" >> return Equal)
             <|> (reservedOp "<" >> return Less)
             <|> (reservedOp "<>" >> return NEQ)
             <|> (reservedOp "=" >> return Equal)


