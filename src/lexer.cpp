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
        else if(isblank(prompt[i]))
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
        else if(prompt[i] == '*')
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
        else if(prompt[i] == 's' || prompt[i] == 'S')
        {
            if((prompt[i+1] == 'i' || prompt[i+1] == 'I') && (prompt[i+2] == 'n' || prompt[i+2] == 'N'))
            {
                Token_s.Type = TokenType::SIN;
                tokenList.push_back(Token_s);
                i+=2;
            }
            else if((prompt[i+1] == 'q' || prompt[i+1] == 'Q'))
            {
                if((prompt[i+2] == 'r' || prompt[i+2] == 'R') && (prompt[i+3] == 't' || prompt[i+3] == 'T'))
                {
                    Token_s.Type = TokenType::SQRT;
                    tokenList.push_back(Token_s);
                    i+=3;
                }
            }
        }
        else if (prompt[i] == 'l' || prompt[i] == 'L')
        {
            if(prompt[i+1] == 'n' || prompt[i+1] == 'N')
            {
                Token_s.Type = TokenType::LN;
                tokenList.push_back(Token_s);
                i++;
            }
            else if (((prompt[i+1] == 'o' || prompt[i+1] == 'O') && (prompt[i+2] == 'g' || prompt[i+2] == 'G')))
            {
                Token_s.Type = TokenType::LOG;
                tokenList.push_back(Token_s);
                i+=2;
            }
        }
        else if((prompt[i] == 'c' || prompt[i] == 'C'))
        {
            if(((prompt[i+1] == 'o' || prompt[i+1] == 'O') && (prompt[i+2] == 's' || prompt[i+2] == 'S')))
            {
                Token_s.Type = TokenType::COS;
                tokenList.push_back(Token_s);
                i+=2;
            }
        }
        else if((prompt[i] == 't' || prompt[i] == 'T'))
        {
            if(((prompt[i+1] == 'a' || prompt[i+1] == 'A') && (prompt[i+2] == 'n' || prompt[i+2] == 'N')))
            {
                Token_s.Type = TokenType::TAN;
                tokenList.push_back(Token_s);
                i+=2;
            }
        }
        else if(prompt[i] == '=')
        {
            Token_s.Type = TokenType::EQUALS;
            tokenList.push_back(Token_s);
        }
        else if(prompt[i] == 'x' || prompt[i] == 'y' || prompt[i] == 'z')
        {
            Token_s.Type = TokenType::VARIABLE;
            Token_s.numb = prompt[i];
            Token_s.name = std::string(1, prompt[i]); // Set the name as string 
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
    if(type == TokenType::SIN) return "SIN";
    if(type == TokenType::COS) return "COS";
    if(type == TokenType::TAN) return "TAN";
    if(type == TokenType::SQRT) return "SQRT";
    if(type == TokenType::LOG) return "LOG";
    if(type == TokenType::LN) return "LN";
    else return " ";
}

