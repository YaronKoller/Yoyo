# Yoyo
Yoyo is a statically-typed scripting language with C-like syntax. The language and interpreter are in active development, so I will add to this file details about the syntax and semantics of Yoyo once they are ready.

Since the parser is not yet complete, the Yoyo interpreter currently simply reads a line of input, tokenizes it, prints a string representation of the result, and repeats. On a lexical error, an error message is printed to stderr but execution continues.

## Lexical Analysis
Below is a table listing the different types of tokens in Yoyo and their corresponding lexemes. Notice that `else`, `if`, `int`, `print`, and `while` are reserved words and are thus not valid IDs.

| Token type | Lexeme (regex)           |
| ---------- | ------------------------ |
| UINT       | `[0-9]+`                 |
| ID         | `[A-Za-z_][0-9A-Za-z_]*` |
| ELSE       | `else`                   |
| IF         | `if`                     |
| INT        | `int`                    |
| PRINT      | `print`                  |
| WHILE      | `while`                  |
| PLUS       | `\+`                     |
| MINUS      | `-`                      |
| MULTIPLY   | `\*`                     |
| DIVIDE     | `/`                      |
| MOD        | `%`                      |
| ASSIGN     | `=`                      |
| COMPARE    | `==\|<\|>\|<=\|>=\|!=`   |
| PAREN_L    | `\(`                     |
| PAREN_R    | `\)`                     |
| SEMICOLON  | `;`                      |
