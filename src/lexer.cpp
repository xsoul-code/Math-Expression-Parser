#include"../include/lexer.h"

lexer::lexer(std::string input)
{
    prompt = input;
}

std::vector<Token> lexer::getTokenList()
{
    Token Token_s;
    for(int i = 0; i<prompt.size(); i++)
    {
        Token Token_s;
        index = i;
        if(isdigit(prompt[i]))
        {
            Token_s.Type = TokenType::NUMBER;
            std::string numStr = "";
            double result = 0;
            while(i < prompt.size() && (isdigit(prompt[i]) || prompt[i] == '.'))
            {
                numStr += prompt[i];
                i++;
            }
            i--;
            result = stod(numStr);
            Token_s.numb = result;
            tokenList.push_back(Token_s);
        }
        else if(isspace(prompt[i]))
        {
            continue;
        }
        else if(prompt[i] == '+')
        {
            Token_s.Type = TokenType::PLUS;
            Token_s.numb = 0.0;
            tokenList.push_back(Token_s);
        }
        else if(prompt[i] == '-')
        {
            Token_s.Type = TokenType::MINUS;
            tokenList.push_back(Token_s);
        }
        else if(prompt[i] == '*' || prompt[i] == 'x')
        {
            Token_s.Type = TokenType::MULTIPLY;
            tokenList.push_back(Token_s);
        }
        else if(prompt[i] == '/')
        {
            Token_s.Type = TokenType::DIVIDE;
            tokenList.push_back(Token_s);

        }
        else if(prompt[i] == '^')
        {
            Token_s.Type = TokenType::POWER;
            tokenList.push_back(Token_s);
        }
        else if(prompt[i] == '(')
        {
            Token_s.Type = TokenType::LPAREN;
            tokenList.push_back(Token_s);

        }
        else if(prompt[i] == ')')
        {
            Token_s.Type = TokenType::RPAREN;
            tokenList.push_back(Token_s);
        }
    }
    return tokenList;
}


std::string tokenTypeToString(TokenType type) // For troubleshooting tokenization
{
    if(type == TokenType::NUMBER) return "NUMBER";
    if(type == TokenType::MINUS) return "MINUS";
    if(type == TokenType::PLUS) return "PLUS";
    if(type == TokenType::MULTIPLY) return "MULTIPLY";
    if(type == TokenType::DIVIDE) return "DIVIDE";
    if(type == TokenType::POWER) return "POWER";
    if(type == TokenType::LPAREN) return "LAPAREN";
    if(type == TokenType::RPAREN) return "RPAREN";
    else return " ";
}


