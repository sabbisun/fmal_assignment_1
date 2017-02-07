#ifndef PARSER_H
#define PARSER_H
#include "Lexer.h"
#include "Token.h"
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
* PUSH
* ADD
* SUB
* MULT
* ASSIGN
* PRINT
*
* The output of the parser is the stack-based intermediate code S, corresponding to the given program, written to stdout.
* If an expression is not in the language(or if ERROR token is returned by the Lexer) then parser outputs error msg "Syntax error!"
* at the point when the error is recognized and immediately quit.
*/
class Parser
{
    public:
        Parser();
        virtual ~Parser();
        void parse(); /// To initiate the parse

    protected:
        /// Other methods are private
    private:
        Lexer luthor;
        Token black; ///for the current token



};

#endif // PARSER_H
