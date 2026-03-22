#include<iostream>
#include"../include/lexer.h"
#include"../include/parser.h"

#define LEXER_TEST 0

int main()
{
    std::vector<std::string> outputHistory;
    std::string input = "";
    while(input != "quit") // Implementation of Read Evaluate Print Loop "REPL"
    {
        input = "";
        std::cout << "Math parser - Throw your equasion here: ";
        std::getline(std::cin, input); // Getline needed in order to not ignore spaces
        if(input == "quit")
        {
            break;
        }
        if(input == "history")
        {
            if(!outputHistory.empty())
            {
                for(int i = 0; i < outputHistory.size(); i++)
                {
                    std::cout << "Output " << i << ": " << outputHistory[i] << std::endl;
                }
                continue;
            }
            else
            {
                std::cout << "There is no history of operations. " << std::endl;
                continue;
            }
        }
        try
        {
            lexer Lex(input);
            std::vector<Token> output = Lex.getTokenList();
            #ifdef LEXER_TEST
            std::cout << "\nPrinting tokens lexed by lexer: " << std::endl;
            for(int i = 0; i<output.size();i++)
            {
                std::cout << tokenTypeToString(output[i].Type) << std::endl;
            }
            #else
            std::cout << "\n";
            #endif
            
            parser Par(output);
            std::string finalOutput = "= " + std::to_string(Par.exec());
            std::cout << finalOutput << std::endl;
            std::string historyInput = input + " " + finalOutput;
            outputHistory.push_back(historyInput);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    return 0;
}
