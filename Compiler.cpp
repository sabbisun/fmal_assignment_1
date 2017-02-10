#include <iostream>
#include "Lexer.h"
#include "Parser.h"

using namespace std;

int main()
{
    Lexer myLexer = Lexer();
    Parser myParser = Parser(myLexer);
    myParser.parse();
    return 0;
}
