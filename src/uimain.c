#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main() {
    char input[256];
    List *history = init_history();

    printf("> ");
    while (fgets(input, sizeof(input), stdin)) {
        input[strcspn(input, "\n")] = 0;  // Remove newline character

        if (input[0] == '!' && input[1] != '\0') {
            int id = atoi(&input[1]);
            char *command = get_history(history, id);
            if (command) {
                printf("Recalling command %d: %s\n", id, command);
                strcpy(input, command);
            } else {
                printf("No command found with id %d\n", id);
                printf("> ");
                continue;
            }
        }

        add_history(history, input);
        char **tokens = tokenize(input);
        print_tokens(tokens);
        free_tokens(tokens);

        printf("> ");
    }

    free_history(history);
    return 0;
}
