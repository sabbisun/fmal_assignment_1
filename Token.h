#ifndef TOKEN_H
#define TOKEN_H
#include<string>

using namespace std;

enum TokenCode { ID, ASSIGN, SEMICOL, INT, ADD, SUB, MULT, LPAREN, RPAREN, PRINT, END, ERROR };

class Token
{
    public:
        Token();
        Token(TokenCode tCode, string lexeme) {
            this->tCode = tCode;
            this->lexeme = lexeme;
        };
        virtual ~Token();
        TokenCode getTokenCode() {
            return tCode;
        };
        void setTokenCode(TokenCode tCode) {
            this->tCode = tCode;
        };
        string getLexeme() {
            return lexeme;
        };
        void setLexeme(string lexeme) {
            this->lexeme = lexeme;
        };

    protected:

    private:


        string lexeme;
        TokenCode tCode;

};

#endif // TOKEN_H
