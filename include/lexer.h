#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <string_view>
#include <Token.h>

struct SourceFile {
  std::string_view path;
  std::string buffer;
};

class Lexer {
  const SourceFile *source;
  size_t idx = 0;
  
  int line = 1;
  int column = 0;

  char peek() const;
  char eat();

public:
  explicit Lexer(const SourceFile &source) : source(&source) {}
  Token getNextToken();
}

#endif
