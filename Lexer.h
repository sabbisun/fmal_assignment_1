#ifndef LEXER_H
#define LEXER_H
#include "Token.h"
#include <iostream>

using namespace std;

class Lexer
{
    public:
        Lexer();
        /**
        * @brief nextToken
        * Scans the standard input (stdin), looking for patterns that match one of the tokens from the Token class i.e. ID, INT, ADD etc.
        * lexemes corresponding to the tokens ADD, SUB, MULT, LPAREN, RPAREN, ASSIGN, SEMICOL contain only a single letter.
        * pattern for other tokens:
        *   INT   = [0-9]+
        *   ID    = [A-Za-z]+
        *   END   = end
        *   PRINT = print
        *
        *   Lexical analyzer returns a token with TokenCode = ERROR if it finds an illegal lexeme.
        */
        void nextToken();

    protected:

    private:

        Token ourToken;


};

#endif // LEXER_H
