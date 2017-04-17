//
//  lexer.hpp
//  Yoyo
//
//  Created by Yaron Koller on 2017-03-11.
//  Copyright © 2017 Yaron Koller. All rights reserved.
//

#ifndef lexer_hpp
#define lexer_hpp

#include <exception>
#include <string>
#include <vector>
#include "token.hpp"

class Lexer
{
public:
    Lexer();
    ~Lexer();
    
    // Tokenizes the string and appends the tokens to the internal array of tokens
    // On a lexing error, empties the internal array and throws a LexicalError
    void tokenize(const std::string & str);
    
    // Removes the tokens from the internal array of tokens and returns them
    // The returned data must be deleted by the caller
    std::vector<Token> * removeTokens();
    
private:
    enum class DfaState;
    
    std::vector<Token> * tokens;
    
    // Given the current DFA state and the next character of input, returns the next DFA state
    DfaState getNextState(DfaState state, char c);
    
    // Creates a token based on the given data and appends it to the internal array of tokens
    // On an invalid token, empties the internal array and throws a LexicalError
    void appendToTokens(DfaState state, const std::string & lexeme);
};

class LexicalError: public std::exception
{
public:
    // Returns a string that describes the error
    const char * what() const noexcept;
};

#endif /* lexer_hpp */
