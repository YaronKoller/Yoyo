//
//  token.cpp
//  Yoyo
//
//  Created by Yaron Koller on 2017-04-09.
//  Copyright © 2017 Yaron Koller. All rights reserved.
//

#include <sstream>
#include "token.hpp"

Token::Token(TokenType type, const std::string & lexeme) : type(type), lexeme(lexeme) {}

std::string Token::toString()
{
    std::ostringstream oss;
    oss << '{';
    
    switch (type)
    {
        case TokenType::UINT:
            oss << "UINT";
            break;
            
        case TokenType::ID:
            oss << "ID";
            break;
            
        case TokenType::ELSE:
            oss << "ELSE";
            break;
            
        case TokenType::IF:
            oss << "IF";
            break;
            
        case TokenType::INT:
            oss << "INT";
            break;
            
        case TokenType::PRINT:
            oss << "PRINT";
            break;
            
        case TokenType::WHILE:
            oss << "WHILE";
            break;
            
        case TokenType::PLUS:
            oss << "PLUS";
            break;
            
        case TokenType::MINUS:
            oss << "MINUS";
            break;
            
        case TokenType::MULTIPLY:
            oss << "MULTIPLY";
            break;
            
        case TokenType::DIVIDE:
            oss << "DIVIDE";
            break;
            
        case TokenType::MOD:
            oss << "MOD";
            break;
            
        case TokenType::ASSIGN:
            oss << "ASSIGN";
            break;
            
        case TokenType::COMPARE:
            oss << "COMPARE";
            break;
            
        case TokenType::PAREN_L:
            oss << "PAREN_L";
            break;
            
        case TokenType::PAREN_R:
            oss << "PAREN_R";
            break;
            
        case TokenType::SEMICOLON:
            oss << "SEMICOLON";
            break;
    }
    
    oss << ", \"" << lexeme << "\"}";
    return oss.str();
}
