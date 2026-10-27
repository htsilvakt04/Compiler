#include "compiler.h"

#include <stdio.h>

#include "scanner.h"

void compile(const char *source) {
    // 1: scan
    initScanner(source);

    int line = -1;
    for (;;) {
        Token token = scanToken();
        if (token.line != line) {
            printf("%4d ", token.line);
            line = token.line;
        } else {
            printf("   | ");
        }
        printf("%2d '%.*s'\n", token.type, token.length, token.start);

        if (token.type == TOKEN_EOF) break;
    }

    // 2: compile
    // 3: execute
}
