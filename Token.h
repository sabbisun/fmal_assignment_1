#ifndef TOKEN_H
#define TOKEN_H
#include<string>

//using namespace std;



class Token
{
    public:
        enum TokenCode { ID, ASSIGN, SEMICOL, INT, ADD, SUB, MULT, LPAREN, RPAREN, PRINT, END, ERROR };
        Token(){};
        Token(TokenCode tCode, std::string lexeme) {
            this->tCode = tCode;
            this->lexeme = lexeme;
        };
        TokenCode getTokenCode() {
            return tCode;
        };
        void setTokenCode(TokenCode tCode) {
            this->tCode = tCode;
        };
        std::string getLexeme() {
            return lexeme;
        };
        void setLexeme(std::string lexeme) {
            this->lexeme = lexeme;
        };

    private:
        std::string lexeme;
        TokenCode tCode;

};

#endif // TOKEN_H
