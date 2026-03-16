#include"../include/parser.h"
#include"../include/lexer.h"
#include<cmath>
#include<stdexcept>

#define PI 3.14159265

parser::parser(std::vector<Token> tokenList)
{
    data = tokenList;
    current = 0;
}

double parser::exec()
{
    return Expression();
}

double parser::Expression() // + and -
{
    double result = Term();
    while(data[current].Type == TokenType::PLUS || data[current].Type == TokenType::MINUS)
    {
        if(data[current].Type == TokenType::PLUS)
        {
            current++;
            result = result + Term();
        }
        else
        {
            current++;
            result = result - Term();
        }
    }
    return result;
}        

double parser::Term()       // * and / and ()
{
    double result = Power();
    while(data[current].Type == TokenType::MULTIPLY || data[current].Type == TokenType::DIVIDE) 
    {
        if(data[current].Type == TokenType::MULTIPLY)
        {
            current++;
            result = result * Power();
        }
        else
        {
            current++;
            result = result / Power();
        }
    }
    return result;
}      

double parser::Power()      // ^
{
    double result = Function();
    while(data[current].Type == TokenType::POWER)
    {
        current++;
        result = std::pow(result, Primary());
    }
    return result;
}     

double parser::Function()
{
    double result;
    if(data[current].Type == TokenType::SIN || data[current].Type == TokenType::COS||
            data[current].Type == TokenType::TAN || data[current].Type == TokenType::LN ||
            data[current].Type == TokenType::LOG || data[current].Type == TokenType::SQRT)
    {
        if(data[current].Type == TokenType::SIN)
        {
            current++;
            double param;
            param = Primary();
            result = sin(param * PI /180);
        }
        else if(data[current].Type == TokenType::COS)
        {
            current++;
            double param;
            param = Primary();
            result = cos(param * PI /180);
        }
        else if(data[current].Type == TokenType::TAN)
        {
            current++;
            double param;
            param = Primary();
            result = tan(param * PI /180);
        }
        else if(data[current].Type == TokenType::LN)
        {
            current++;
            result = log(Primary());
        }
        else if(data[current].Type == TokenType::LOG)
        {
            current++;
            result = log10(Primary());
        }
        else if(data[current].Type == TokenType::SQRT)
        {
            current++;
            result = sqrt(Primary());
        }
    }
    else
    {
        result = Primary();
    }
    return result;
}

double parser::Primary()    //Numbers and dots
{
    if(data[current].Type == TokenType::LPAREN)
    { 
        current++;
        double result = Expression();
        current++;
        return result;
    }
    else if(data[current].Type == TokenType::NUMBER)
    {
        current++;
        return data[current-1].numb;
    }
    else
    {
        throw std::runtime_error("Unexpected token in Primary");
    }
} 