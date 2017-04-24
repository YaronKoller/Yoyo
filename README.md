# Yoyo
An interpreter for Yolang, my own programming language.

Since the parser is not yet complete, Yoyo currently simply reads a line of input, tokenizes it, prints a string representation of the result to stdout, and repeats. On a lexical error, an error message is printed to stderr but execution continues.

I will add to this file details about the syntax and semantics of Yolang when they are ready.

## Lexical Analysis
These are the different types of tokens in Yolang and their corresponding lexemes:

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

Notice that `else`, `if`, `int`, `print`, and `while` are reserved words and are thus not valid IDs.
