//
//  lexer.cpp
//  Yoyo
//
//  Created by Yaron Koller on 2017-03-11.
//  Copyright © 2017 Yaron Koller. All rights reserved.
//

#include <cctype>
#include "lexer.hpp"

enum class Lexer::DfaState
{
    ERROR,
    START,
    
    UINT,
    ID,
    
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MOD,
    
    ASSIGN,
    LESS,
    GREATER,
    NOT,
    COMPARE,
    
    PAREN_L,
    PAREN_R,
    SEMICOLON,
};

Lexer::Lexer()
{
    tokens = new std::vector<Token>();
}

Lexer::~Lexer()
{
    delete tokens;
}

void Lexer::tokenize(const std::string & str)
{
    DfaState currState = DfaState::START;
    
    auto startIt = str.begin();
    auto currIt = startIt;
    
    while (currIt != str.end())
    {
        if (isspace(*startIt))
        {
            ++startIt;
            currIt = startIt;
        }
        else
        {
            DfaState nextState = getNextState(currState, *currIt);
            
            if (nextState == DfaState::ERROR)
            {
                appendToTokens(currState, std::string(startIt, currIt));
                currState = DfaState::START;
                startIt = currIt;
            }
            else
            {
                currState = nextState;
                ++currIt;
            }
        }
    }
    
    if (currState != DfaState::START)
    {
        appendToTokens(currState, std::string(startIt, currIt));
    }
}

std::vector<Token> * Lexer::removeTokens()
{
    std::vector<Token> * ret = tokens;
    tokens = new std::vector<Token>();
    return ret;
}

Lexer::DfaState Lexer::getNextState(DfaState state, char c)
{
    switch (state)
    {
        case DfaState::START:
            if (isdigit(c))
            {
                return DfaState::UINT;
            }
            else if (isalpha(c) || c == '_')
            {
                return DfaState::ID;
            }
            else if (c == '+')
            {
                return DfaState::PLUS;
            }
            else if (c == '-')
            {
                return DfaState::MINUS;
            }
            else if (c == '*')
            {
                return DfaState::MULTIPLY;
            }
            else if (c == '/')
            {
                return DfaState::DIVIDE;
            }
            else if (c == '%')
            {
                return DfaState::MOD;
            }
            else if (c == '=')
            {
                return DfaState::ASSIGN;
            }
            else if (c == '<')
            {
                return DfaState::LESS;
            }
            else if (c == '>')
            {
                return DfaState::GREATER;
            }
            else if (c == '!')
            {
                return DfaState::NOT;
            }
            else if (c == '(')
            {
                return DfaState::PAREN_L;
            }
            else if (c == ')')
            {
                return DfaState::PAREN_R;
            }
            else if (c == ';')
            {
                return DfaState::SEMICOLON;
            }
            break;
            
        case DfaState::UINT:
            if (isdigit(c))
            {
                return DfaState::UINT;
            }
            break;
            
        case DfaState::ID:
            if (isdigit(c) || isalpha(c) || c == '_')
            {
                return DfaState::ID;
            }
            break;
            
        case DfaState::ASSIGN:
        case DfaState::LESS:
        case DfaState::GREATER:
        case DfaState::NOT:
            if (c == '=')
            {
                return DfaState::COMPARE;
            }
            break;
            
        default:
            break;
    }
    
    return DfaState::ERROR;
}

void Lexer::appendToTokens(DfaState state, const std::string & lexeme)
{
    TokenType type;
    
    switch (state)
    {
        case DfaState::UINT:
            type = TokenType::UINT;
            break;
            
        case DfaState::ID:
            if (lexeme == "else")
            {
                type = TokenType::ELSE;
            }
            else if (lexeme == "if")
            {
                type = TokenType::IF;
            }
            else if (lexeme == "int")
            {
                type = TokenType::INT;
            }
            else if (lexeme == "print")
            {
                type = TokenType::PRINT;
            }
            else if (lexeme == "while")
            {
                type = TokenType::WHILE;
            }
            else
            {
                type = TokenType::ID;
            }
            break;
            
        case DfaState::PLUS:
            type = TokenType::PLUS;
            break;
            
        case DfaState::MINUS:
            type = TokenType::MINUS;
            break;
            
        case DfaState::MULTIPLY:
            type = TokenType::MULTIPLY;
            break;
            
        case DfaState::DIVIDE:
            type = TokenType::DIVIDE;
            break;
            
        case DfaState::MOD:
            type = TokenType::MOD;
            break;
            
        case DfaState::ASSIGN:
            type = TokenType::ASSIGN;
            break;
            
        case DfaState::LESS:
        case DfaState::GREATER:
        case DfaState::COMPARE:
            type = TokenType::COMPARE;
            break;
            
        case DfaState::PAREN_L:
            type = TokenType::PAREN_L;
            break;
            
        case DfaState::PAREN_R:
            type = TokenType::PAREN_R;
            break;
            
        case DfaState::SEMICOLON:
            type = TokenType::SEMICOLON;
            break;
            
        default:
            tokens->clear();
            throw LexicalError();
    }
    
    tokens->push_back(Token(type, lexeme));
}

const char * LexicalError::what() const noexcept
{
    return "Lexical error";
}
