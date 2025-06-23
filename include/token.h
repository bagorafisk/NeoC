#ifndef TOKEN_H
#define TOKEN_H

#include <unordered_map>
#include <string>
#include <string_view>
#include <optional>

constexpr char singleCharTokens[] = {'\0', '(', ')', '{', '}', ':'};

enum class TokenType : char {
  Unk = -128,

  Identifier,

  KwFn,
  KwVoid,

  EoF = singleCharTokens[0],
  Lpar = singleCharTokens[1],
  Rpar = singleCharTokens[2],
  Lbrace = singleCharTokens[3],
  Rbrace = singleCharTokens[4],
  Colon = singleCharTokens[5],
};

const std::unordered_map<std::string, TokenType> keywords = {
  {"fn", TokenType::KwFn},
  {"void", TokenType::KwVoid},
};

struct SourceLocation {
  std::string_view filepath;
  int line;
  int col;
};

struct Token {
  SourceLocation location;
  TokenType type;
  std::optional<std::string> value = std::nullopt;
};

#endif
