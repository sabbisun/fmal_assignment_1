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

	currToken = lex.nextToken();
	Statements();
}
void Parser::Statements() {

	if(currToken.getTokenCode() == Token::END)
	{
		return;
	}

	Statement();

	if(currToken.getTokenCode() == Token::SEMICOL)
	{
		currToken = lex.nextToken();;
	}
	else
	{
		outputErrorMsg();
	}
	Statements();

}
void Parser::Statement() {

	if(currToken.getTokenCode() == Token::PRINT)
	{
		currToken = lex.nextToken();

		if(currToken.getTokenCode() == Token::ID)
		{
			currToken = lex.nextToken();
		}
		else
		{
			outputErrorMsg();
		}
	}
	else if(currToken.getTokenCode() == Token::ID)
	{


		currToken = lex.nextToken();

		if(currToken.getTokenCode() == Token::ASSIGN)
		{
			currToken = lex.nextToken();
		}
			else
		{
				outputErrorMsg();
		}
		Expr();
	}
	else
	{
		outputErrorMsg();
	}

}
void Parser::Expr() {

	Term();

	if(currToken.getTokenCode() == Token::ADD)
	{
		currToken = lex.nextToken();
		Expr();
	}
	else if(currToken.getTokenCode() == Token::SUB)
	{
		currToken = lex.nextToken();
		Expr();
	}
}
void Parser::Term() {

	Factor();

	if(currToken.getTokenCode() == Token::MULT)
	{
		Term();
	}
}
void Parser::Factor() {

	if(currToken.getTokenCode() == Token::INT)
	{
		currToken = lex.nextToken();
	}
	else if(currToken.getTokenCode() == Token::ID)
	{
		currToken = lex.nextToken();
	}
	else if (currToken.getTokenCode() == Token::LPAREN)
	{
		currToken = lex.nextToken();
		Expr();

		if (currToken.getTokenCode() == Token::RPAREN)
		{
			currToken = lex.nextToken();
		}
		else
		{
			outputErrorMsg();
		}
	}
}
