#include "Parser.h"

Parser::Parser()
{
    //ctor
}
Parser::Parser(Lexer luthor)
{
    this->lex = lex;

}
/*Parser::~Parser()
{
    //dtor
}*/

void Parser::outputErrorMsg()
{
    cout << "Syntax error!" << endl;
    return;
}

void Parser::parse() {

    //cout << "using parse function " << endl;
	currToken = lex.nextToken();
	//cout << "calling statements" << endl;
	Statements();
}
void Parser::Statements() {

    //cout << "inside statements" << endl;
	if(currToken.getTokenCode() == Token::END)
	{
	    //cout << "Token is END, returning" << endl;
		return;
	}
    //cout << "calling statement" << endl;
	Statement();

	if(currToken.getTokenCode() == Token::SEMICOL)
	{   //cout << "Token is SEMICOL" << endl;
		currToken = lex.nextToken();;
	}
	else
	{
	    //cout << "ERROR in Statements" << endl;
		outputErrorMsg();
	}
	//cout << "calling statements" << endl;
	Statements();

}
void Parser::Statement() {
    //cout << "inside statement" << endl;
	if(currToken.getTokenCode() == Token::PRINT)
	{   //cout << "Token is PRINT" << endl;
		currToken = lex.nextToken();

		if(currToken.getTokenCode() == Token::ID)
		{   //cout << "Token is ID" << endl;
			currToken = lex.nextToken();
		}
		else
		{   //cout << "ERROR in Statement" << endl;
			outputErrorMsg();
		}
	}
	else if(currToken.getTokenCode() == Token::ID)
	{

        //cout << "Token is ID" << endl;
		currToken = lex.nextToken();

		if(currToken.getTokenCode() == Token::ASSIGN)
		{   //cout << "Token is ASSIGN" << endl;
			currToken = lex.nextToken();
		}
        else
		{
            //cout << "ERROR in ID ASSIGN" << endl;
            outputErrorMsg();
		}
		Expr();
	}
	else
	{   //cout << "ERROR in Statement" << endl;
		outputErrorMsg();
	}

}
void Parser::Expr() {
    //cout << "Inside Expr" << endl;
	Term();

	if(currToken.getTokenCode() == Token::ADD)
	{   //cout << "Token is ADD" << endl;
		currToken = lex.nextToken();
		Expr();
	}
	else if(currToken.getTokenCode() == Token::SUB)
	{   //cout << "Token is SUB" << endl;
		currToken = lex.nextToken();
		Expr();
	}
}
void Parser::Term() {
    //cout << "Inside Term" << endl;
	Factor();

	if(currToken.getTokenCode() == Token::MULT)
	{   //cout << "Token is MULT" << endl;
        currToken = lex.nextToken();
		Term();
	}
}
void Parser::Factor() {
    //cout << "Inside Factor" << endl;
	if(currToken.getTokenCode() == Token::INT)
	{   //cout << "Token is INT" << endl;
		currToken = lex.nextToken();
	}
	else if(currToken.getTokenCode() == Token::ID)
	{   //cout << "Token is ID" << endl;
		currToken = lex.nextToken();
	}
	else if (currToken.getTokenCode() == Token::LPAREN)
	{   //cout << "Token is LPAREN" << endl;
		currToken = lex.nextToken();
		Expr();

		if (currToken.getTokenCode() == Token::RPAREN)
		{   //cout << "Token is RPAREN" << endl;
			currToken = lex.nextToken();
		}
		else
		{   //cout << "Error in Factor, missing RPAREN after LPAREN" << endl;
			outputErrorMsg();
		}
	}
}
