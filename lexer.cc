#include "lexer.h"
#include <sstream>
#include <iostream>
#include <map>

const static std::map<std::string, tokType_t> RESERVED =
{
    {"let", tokType_t::LET},
};

void print_toks(const std::string& line, const std::vector<tok_t>& vk)
{
    const static char* desc[] = 
    {
        "Number",
        "Identifier",
        "Equals",
        "Open_Parentesis",
        "Close_Parentesis",
        "BinaryOperator",
        "Let [Reserved KW]",
    };

    std::cout << "{\n\t{Raw_Text, \"" << line << "\"}\n";
    for(std::size_t i{0}; i < vk.size(); i++)
    {
        std::cout << "\t{" << desc[static_cast<int>(vk[i].type)] << ", " << vk[i].content << "}\n";
    }
    std::cout << "}\n" << std::endl;

}

std::vector<tok_t> tokenize(const std::string& line)
{

    std::vector<tok_t> tokens;

    for(std::size_t i{0}; i < line.length();)
    {
        if(line[i] == '(')
        {
            tokens.push_back(tok_t{tokType_t::OPENPAREN, "("});
            i++;
        } else if(line[i] == ')')
        {
            tokens.push_back(tok_t{tokType_t::CLOSEPARE, ")"});
            i++;
        } else if(line[i] == '=')
        {   
            tokens.push_back(tok_t{tokType_t::EQUALS, "="});
            i++;
        } else if(line[i] == '+' || line[i] == '-' || line[i] == '*'|| line[i] == '/')
        {
            std::string c_content;
            c_content.push_back(line[i]);
            tokens.push_back(tok_t{tokType_t::BINARYOPERATOR, c_content});
            i++;
        } else
        {
            if(std::isdigit(line[i]))
            {
                std::string num;

                while(i < line.length() && std::isdigit(line[i]))
                {
                    num.push_back(line[i]);
                    i++;
                }

                tokens.push_back(tok_t{tokType_t::NUMBER, num});

            } else if(std::isalpha(line[i]))
            {
                std::string idnt;

                while(i < line.length() && std::isalpha(line[i]))
                {
                    idnt.push_back(line[i]);
                    i++;
                }

                if(RESERVED.find(idnt) == RESERVED.end())
                {
                    tokens.push_back(tok_t{tokType_t::IDENTIFIER, idnt});
                } else
                {
                    tokens.push_back(tok_t{RESERVED.at(idnt), idnt});
                }

            } else if(line[i] == ' ' || line[i] == ',' || line[i] == '\n')
            {
                i++;
                continue;
            } else
            {
                std::cerr << "Unrecognized token: " << line[i] << std::endl;
                i++;
            }
        }

    }

    print_toks(line, tokens);

    return tokens;

}