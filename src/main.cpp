#include<iostream>
#include"../include/lexer.h"
#include"../include/parser.h"

int main()
{
    std::string input = "";
    std::cout << "Math parser - Throw your equasion here: ";
    std::getline(std::cin, input); // Needed in order to not ignore spaces
    lexer Lex(input);
    std::vector<Token> output = Lex.getTokenList();
    for(int i = 0; i<output.size();i++)
    {
        std::cout << tokenTypeToString(output[i].Type) << std::endl;
    }
    parser Par(output);
    std::cout << "= " << Par.exec() << std::endl;

    return 0;
}
