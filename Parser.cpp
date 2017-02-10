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
    //cout << "Syntax error!" << endl;

    output.push_back("Syntax error!\n");
    error = true;
    return;
}

void Parser::parse() {

    //cout << "using parse function " << endl;
	currToken = lex.nextToken();
	//cout << "calling statements" << endl;
	Statements();
	for(unsigned int i = 0; i < output.size(); i++)
    {
        cout << output[i];
        if(output[i] == "Syntax error!\n")
        {
            break;
        }
    }
}
void Parser::Statements() {

    if(currToken.getTokenCode() == Token::ERROR || error)
    {
        outputErrorMsg();
        return;
    }

    //cout << "inside statements" << endl;
	if(currToken.getTokenCode() == Token::END)
	{
	    //cout << "END" << endl;
	    //output.push_back("END\n");
	    //cout << "Token is END, returning" << endl;
		return;
	}
    //cout << "calling statement" << endl;
	Statement();

	if(error)
    {
        outputErrorMsg();
        return;
    }

	if(currToken.getTokenCode() == Token::SEMICOL)
	{   //cout << "Token is SEMICOL" << endl;
		currToken = lex.nextToken();;
	}
	else
	{
	    //cout << "ERROR in Statements" << endl;
		outputErrorMsg();
		return;
	}
	//cout << "calling statements" << endl;
	Statements();
}
void Parser::Statement() {

    if(currToken.getTokenCode() == Token::ERROR || error)
    {
        outputErrorMsg();
        return;
    }

    //cout << "inside statement" << endl;
	if(currToken.getTokenCode() == Token::PRINT)
	{

	    //cout << "Token is PRINT" << endl;
		currToken = lex.nextToken();

		if(currToken.getTokenCode() == Token::ID)
		{   //cout << "Token is ID" << endl;
		    //cout << "PUSH " << currToken.getLexeme() << endl;
		    output.push_back("PUSH " + currToken.getLexeme() +"\n");
			currToken = lex.nextToken();
		}
		else
		{   //cout << "ERROR in Statement" << endl;
			outputErrorMsg();
			return;
		}

		output.push_back("PRINT\n");
		//cout << "PRINT" << endl;
	}
	else if(currToken.getTokenCode() == Token::ID)
	{
        //cout << "PUSH " << currToken.getLexeme() << endl;
        output.push_back("PUSH " + currToken.getLexeme() +"\n");
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
            return;
		}
		Expr();
		if(currToken.getTokenCode() == Token::ERROR  || error)
        {
            outputErrorMsg();
            return;
        }
		output.push_back("ASSIGN\n");
		//cout << "ASSIGN" << endl;
	}
}
void Parser::Expr() {

    if(currToken.getTokenCode() == Token::ERROR  || error)
    {
        outputErrorMsg();
        return;
    }

    //cout << "Inside Expr" << endl;
	Term();

	if(error)
    {
        outputErrorMsg();
        return;
    }

	if(currToken.getTokenCode() == Token::ADD)
	{

	    //cout << "Token is ADD" << endl;
		currToken = lex.nextToken();
		Expr();

		if(error)
        {
            outputErrorMsg();
            return;
        }
		//cout << "ADD" << endl;
		output.push_back("ADD\n");
	}
	else if(currToken.getTokenCode() == Token::SUB)
	{

	    //cout << "Token is SUB" << endl;
		currToken = lex.nextToken();
		Expr();

		if(error)
        {
            outputErrorMsg();
            return;
        }

		output.push_back("SUB\n");
		//cout << "SUB" << endl;
	}
}
void Parser::Term() {

    if(currToken.getTokenCode() == Token::ERROR  || error)
    {
        outputErrorMsg();
        return;
    }

    //cout << "Inside Term" << endl;
	Factor();

	if(error)
    {
        outputErrorMsg();
        return;
    }

	if(currToken.getTokenCode() == Token::MULT)
	{

	    //cout << "Token is MULT" << endl;
        currToken = lex.nextToken();
		Term();
		output.push_back("MULT\n");
		//cout << "MULT" << endl;
	}
}
void Parser::Factor() {

    if(currToken.getTokenCode() == Token::ERROR  || error)
    {
        outputErrorMsg();
        return;
    }

    //cout << "Inside Factor" << endl;
    //cout << "tokencode " << currToken.getTokenCode()<< endl;
	if(currToken.getTokenCode() == Token::INT)
	{
	    //cout << "PUSH " << currToken.getLexeme() << endl;
	    output.push_back("PUSH " + currToken.getLexeme() +"\n");
	    //cout << "Token is INT" << endl;
		currToken = lex.nextToken();
	}
	else if(currToken.getTokenCode() == Token::ID)
	{
	    //cout << "PUSH " << currToken.getLexeme() << endl;
	    output.push_back("PUSH " + currToken.getLexeme() +"\n");
	    //cout << "Token is ID" << endl;
		currToken = lex.nextToken();
	}
	else if (currToken.getTokenCode() == Token::LPAREN)
	{   //cout << "Token is LPAREN" << endl;
		currToken = lex.nextToken();
		Expr();

		if(error)
        {
            outputErrorMsg();
            return;
        }

		if (currToken.getTokenCode() == Token::RPAREN)
		{   ////cout << "Token is RPAREN" << endl;
			currToken = lex.nextToken();
		}
		else
		{   //cout << "Error in Factor, missing RPAREN after LPAREN" << endl;
			outputErrorMsg();
			return;
		}
	}
	else
    {
        outputErrorMsg();
        return;
    }
}
