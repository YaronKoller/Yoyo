//
//  token.hpp
//  Yoyo
//
//  Created by Yaron Koller on 2017-04-09.
//  Copyright © 2017 Yaron Koller. All rights reserved.
//

#ifndef token_hpp
#define token_hpp

#include <string>

enum class TokenType
{
    UINT,       // [0-9]+
    ID,         // [A-Za-z_][0-9A-Za-z_]*  (other than keywords)
    
    // Keywords
    ELSE,       // else
    IF,         // if
    INT,        // int
    PRINT,      // print
    WHILE,      // while
    
    // Operators
    PLUS,       // +
    MINUS,      // -
    MULTIPLY,   // *
    DIVIDE,     // /
    MOD,        // %
    ASSIGN,     // =
    COMPARE,    // == | < | > | <= | >= | !=
    
    // Others
    PAREN_L,    // (
    PAREN_R,    // )
    SEMICOLON,  // ;
};

struct Token
{
    const TokenType type;
    const std::string lexeme;
    
    Token(TokenType type, const std::string & lexeme);
    
    // Returns a string representation of the token
    std::string toString();
};

#endif /* token_hpp */
