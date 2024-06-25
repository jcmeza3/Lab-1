#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c) {
    return c == ' ' || c == '\t';
}

int non_space_char(char c) {
    return !space_char(c) && c != '\0';
}

char *token_start(char *s) {
    while (*s && space_char(*s)) s++;
    return *s ? s : NULL;
}

char *token_terminator(char *token) {
    while (*token && non_space_char(*token)) token++;
    return token;
}

int count_tokens(char *s) {
    int count = 0;
    while ((s = token_start(s))) {
        count++;
        s = token_terminator(s);
    }
    return count;
}

char *copy_str(char *inStr, short len) {
    char *copy = (char *)malloc((len + 1) * sizeof(char));
    strncpy(copy, inStr, len);
    copy[len] = '\0';
    return copy;
}

char **tokenize(char *s) {
    int count = count_tokens(s);
    char **tokens = (char **)malloc((count + 1) * sizeof(char *));
    char *start = token_start(s);
    for (int i = 0; i < count; i++) {
        char *end = token_terminator(start);
        int len = end - start;
        tokens[i] = copy_str(start, len);
        start = token_start(end);
    }
    tokens[count] = NULL;
    return tokens;
}

void print_tokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("Token %d: %s\n", i, tokens[i]);
    }
}

void free_tokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}
