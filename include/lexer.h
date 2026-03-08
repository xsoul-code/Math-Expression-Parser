#pragma once
#include<string>
#include<vector>
#include<ctype.h>

enum class TokenType
{
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    POWER,
    LPAREN,
    RPAREN,
    EMPTY,
    SIN,
    COS,
    TAN,
    SQRT,
    LOG,
    LN
};

struct Token 
{
    TokenType Type;        // Token type
    double    numb = 0.0;  // Value of token
};

std::string tokenTypeToString(TokenType type);

class lexer
{
    public:
        lexer(std::string input);
        std::vector<Token> getTokenList();
    private:
        std::string prompt;
        std::vector<Token> tokenList;
        size_t index; // Index of the iterated prompt array
};

