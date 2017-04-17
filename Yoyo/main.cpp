//
//  main.cpp
//  Yoyo
//
//  Created by Yaron Koller on 2017-03-05.
//  Copyright © 2017 Yaron Koller. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "token.hpp"
#include "lexer.hpp"

int interpret(std::istream & input)
{
    std::vector<Token> * tokens;
    std::string line;
    Lexer lexer;
    
    while (std::getline(input, line))
    {
        try
        {
            lexer.tokenize(line);
            tokens = lexer.removeTokens();
            
            for (auto token : *tokens)
            {
                std::cout << token.toString() << std::endl;
            }
            
            delete tokens;
        }
        catch (LexicalError & e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[])
{
    if (argc == 1)
    {
        return interpret(std::cin);
    }
    else if (argc == 2)
    {
        std::ifstream file(argv[1]);
        
        if (file)
        {
            int ret = interpret(file);
            file.close();
            return ret;
        }
        else
        {
            std::cerr << "Error: unable to open file " << argv[1] << std::endl;
            return -1;
        }
    }
    else
    {
        std::cerr << "Usage: " << argv[0] << " [file]" << std::endl;
        return -1;
    }
}
