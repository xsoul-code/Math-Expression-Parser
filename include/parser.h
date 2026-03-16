#pragma once

#include<vector>
#include<string>
#include<ctype.h>
#include"lexer.h"

/*
    This class recieves token list from lexer
    and processes the math given equasion to a
    arithmetically correct result. (with compliance to order of operation etc.)
*/

class parser
{
    public:
        parser(std::vector<Token> tokenList);
        double exec();       // Public method that executes the pipeline
        double Expression(); // This will govern + - operations                   
        double Term();       // This will govern * / operations
        double Power();      // This will govern ^ operation
        double Function();   // This will govern sin cos tan ln log and sqrt math functions
        double Primary();    // This will govern numbers and dots
    private:
        std::vector<Token> data;
        size_t current;         // Current index in vector
};