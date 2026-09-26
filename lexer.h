#pragma once
#ifndef _lexer_h__
#define _lexer_h__

#include <string>
#include <vector>

enum class tokType_e {
    NUMBER = 0,
    IDENTIFIER,
    EQUALS,
    OPENPAREN, 
    CLOSEPARE,
    BINARYOPERATOR,
    LET,
};

struct tok_s {
    enum tokType_e type;
    std::string content;
};

typedef enum tokType_e tokType_t;
typedef struct tok_s tok_t;

std::vector<tok_t> tokenize(const std::string& line);

#endif