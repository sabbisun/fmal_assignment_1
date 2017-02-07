#ifndef TOKEN_H
#define TOKEN_H
#include<string>

class Token
{
    public:
        Token();
        virtual ~Token();

    protected:

    private:

        enum TokenCode { ID, ASSIGN, SEMICOL, INT, ADD, SUB, MULT, LPAREN, RPAREN, PRINT, END, ERROR }
        String lexeme;
        TokenCode tCode;

};

#endif // TOKEN_H
