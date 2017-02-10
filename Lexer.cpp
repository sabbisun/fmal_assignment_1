#include "Lexer.h"

Lexer::Lexer()
{
    //ctor
    //ourToken = Token(Token::ADD, "here");
}

/*Lexer::~Lexer()
{
    //dtor
}*/
Token Lexer::nextToken()
{
    if(ourTokens.empty())
    {
        addToOurTokens();
        Token curr_token =  ourTokens.front();
        ourTokens.pop();
        //cout << " token " << curr_token.getTokenCode() << " lexeme " << curr_token.getLexeme() << endl;
        return curr_token;
    }
    else
    {
        Token curr_token =  ourTokens.front();
        ourTokens.pop();
        //cout << " token " << curr_token.getTokenCode() << " lexeme " << curr_token.getLexeme() << endl;
        return curr_token;
    }
}

void Lexer::addToOurTokens()
{
    string str = "";
    cin >> str;

    int stringBegin = 0;
    int stringLength = 0;
    bool isId = false;
    bool isInt = false;
    //cout << "before for loop" << endl;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        //cout << "at char " << stringBegin  << endl;
        //cout << "with length " << stringLength  << endl;
        if(symbol(str[i]) != -1)
        {
            //cout << "Is a symbol " << str[i]  << endl;
            if(isInt)
            {
                //cout << "insert Int lexeme " << str.substr(stringBegin,stringLength)  << endl;
                ourTokens.push(Token(returnTokenCode(3),str.substr(stringBegin,stringLength)));
                stringBegin += stringLength;
                stringLength = 0;
            }
            else if(isId)
            {
                string isPOE = str.substr(stringBegin,stringLength);
                int index = isPrintOrEnd(isPOE);
                if(index != -1)
                {
                    ourTokens.push(Token(returnTokenCode(index),isPOE));
                    //cout << "insert print/end lexeme " << isPOE << endl;
                }
                else
                {
                    ourTokens.push(Token(returnTokenCode(0),isPOE));
                    //cout << "insert id lexeme " << isPOE  << endl;
                }
                stringBegin += stringLength;
                stringLength = 0;
            }
            //else
            {
                stringBegin++;
            }

            int index = symbol(str[i]);
            ourTokens.push(Token(returnTokenCode(index),str.substr(i,1)));
            //cout << "insert symbol lexeme " << str.substr(i,1)  << endl;

            isInt = false;
            isId = false;
        }
        else if( isdigit(str[i]) )
        {
            //cout << "Is not a symbol " << str[i]<< endl;
            if(isId)
            {
                ourTokens.push(Token(returnTokenCode(-1),""));
                return;
            }
            else
            {
                isInt = true;
                stringLength++;
            }
        }
        else if( isalpha(str[i]) )
        {
            //cout << "Is not a symbol " << str[i]<< endl;
            if(isInt)
            {
                ourTokens.push(Token(returnTokenCode(-1),""));
                return;
            }
            else
            {
                isId = true;
                stringLength++;
            }
        }

        ourTokens.push(Token(returnTokenCode(-1),""));
    }
    //cout << "after for loop" << endl;

    if(stringLength <= 0)
    {
        return;
    }

    string lastStr = str.substr(stringBegin,stringLength);

    if(isInt)
    {
        //cout << "insert Int lexeme " << lastStr  << endl;
        ourTokens.push(Token(returnTokenCode(3), lastStr));
        return;
    }

    int index = isPrintOrEnd(lastStr);
    if(index != -1)
    {
        //cout << "insert print/end lexeme " << lastStr  << endl;
        ourTokens.push(Token(returnTokenCode(index),lastStr));
        return;
    }
    else
    {
        //cout << "insert ID lexeme " << lastStr  << endl;
        ourTokens.push(Token(returnTokenCode(0),lastStr));
        return;
    }
}

//enum TokenCode { ID, ASSIGN, SEMICOL, INT, ADD, SUB, MULT, LPAREN, RPAREN, PRINT, END, ERROR };

int Lexer::symbol(char c)
{
    if (c == '+')
    {
        return 4;
    }
    else if(c == '-')
    {
        return 5;
    }
    else if(c == '*')
    {
        return 6;
    }
    else if(c == '(')
    {
        return 7;
    }
    else if(c == ')')
    {
        return 8;
    }
    else if(c == '=')
    {
        return 1;
    }
    else if(c == ';')
    {
        return 2;
    }

    return -1;
}

int Lexer::isPrintOrEnd(string str)
{
    if(str == "end")
    {
        return 10;
    }
    else if (str == "print")
    {
        return 9;
    }
    return -1;
}

Token::TokenCode Lexer::returnTokenCode(int n)
{
    if(n == 0) {return Token::ID;}
    else if( n == 1) {return Token::ASSIGN;}
    else if( n == 2) {return Token::SEMICOL;}
    else if( n == 3) {return Token::INT;}
    else if( n == 4) {return Token::ADD;}
    else if( n == 5) {return Token::SUB;}
    else if( n == 6) {return Token::MULT;}
    else if( n == 7) {return Token::LPAREN;}
    else if( n == 8) {return Token::RPAREN;}
    else if( n == 9) {return Token::PRINT;}
    else if( n == 10) {return Token::END;}
    return Token::ERROR;
}

