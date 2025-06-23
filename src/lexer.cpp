#include <lexer.h>

bool isSpace(char c) {
  return c == ' ' || c == '\f' || c == '\n' || c == '\r'|| c == '\v';
}

bool isAlpha(char c) {
  return ('a' <= c && c <='z') || ('A' <= c && c <= 'Z') || c == '_';
}

bool isNum(char c) {
  return '0' <= c && c <= '9';
}

bool isAlNum(char c) {
  return isAlpha(c) || isNum(c);
}

char Lexer::peek() const {
  return source->buffer[idx];
}

char Lexer::eat() {
  column++;

  if (source->buffer[idx] == '\n') {
    line++;
    column = 0;
  }

  return source->buffer[idx++];
}

Token Lexer::getNextToken() {
  char currentChar = eat();

  while (isSpace(currentChar)) {
    currentChar = eat();

    SourceLocation tokenStartLocation{source->path, line, column};

    for (auto &&c : singleCharTokens) {
      if (c == currentChar) return Token{tokenStartLocation, static_cast<TokenType>(c)};
    }
  }
  
  if (currentChar == '/' && peek() == '/') {
    while (peek() != '\n' && peek() != '\0') eat();

    return getNextToken();
  }

  if (isAlpha(currentChar)) {
    std::string value{currentChar};

    while (isAlNum(peek())) value += eat();

    if (keywords.count(value)) return Token{tokenStartLocation, keywords.at(value), std::move(value)};
  }

  return Token{tokenStartLocation, TokenType::Unknown};
}
