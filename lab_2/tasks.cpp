#include "tasks.h"

uint32_t calculate_checksum(string input)
{
    uint32_t result = 0;

    std::stringstream iss(input);
    std::vector<std::string> tokens;
    string token;

    while (std::getline(iss, token, '.')) 
    {
        if (!token.empty())
        {
            tokens.push_back(token);
        }
    }

    for(unsigned int i = 0;i < tokens.size();i++)
    {
        result += stoi(tokens[i]);
    }

    return result;
}

uint32_t calculate_checksum(uint32_t input)
{
    uint32_t result = input;

    

    return result;
}


