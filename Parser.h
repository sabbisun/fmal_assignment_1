#ifndef PARSER_H
#define PARSER_H
#include "Lexer.h"
#include "Token.h"
#include <iostream>
/**
* Syntax analyzer(parser)
* A top-down recursive-decent parser for the grammar G.
*
* Statements -> Statement; Statements | end
* Statement  -> id = Expr | print id
* Expr       -> Term | Term + Expr | Term - Expr
* Term       -> Factor | Factor * Term
* Factor     -> int | id | ( Expr )
*
* Non-terminals: Statements(starting symbol), Statement, Expr, Term and Factor.
* Terminals(tokens): ; end id print + - * int ( )
*
* Stack-based intermediate code or S.
*
* PUSH op // pushes the operand op onto the stack
* ADD     // pops the two top elements from the stack, adds their values and pushes the result back onto the stack
* SUB     // pops the two top elements from the stack, subtracts the first value retrieved from the second value and pushes the result back onto the stack
* MULT    // pops the two top elements from the stack, multiplies their values and pushes the result back onto the stack
* ASSIGN  // pops the two top elements from the stack, assigns the first element (a value) to the second element (a variable)
* PRINT   // prints the value currently on top of the stack
*
* The output of the parser is the stack-based intermediate code S, corresponding to the given program, written to stdout.
* If an expression is not in the language(or if ERROR token is returned by the Lexer) then parser outputs error msg "Syntax error!"
* at the point when the error is recognized and immediately quit.
*/
class Parser
{
    public:
        Parser();
        Parser(Lexer lex);
        void parse(); /// To initiate the parse
        void outputErrorMsg();

        /// Other methods are private
    private:
        Lexer lex;
        Token currToken; ///for the current token
        vector<string> output;
        bool error = false;

        void Statements();
        void Statement();
        void Expr();
        void Term();
        void Factor();

};

#endif // PARSER_H
