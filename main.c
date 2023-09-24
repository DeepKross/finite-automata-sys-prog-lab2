#include <stdio.h>
#include <stdlib.h>

// Структура для зберігання автомату
typedef struct {
    int start_state;
    int* final_states;
    int final_states_count;
    int** transition_function;
    int states_count;
} Automaton;

Automaton read_automaton(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    Automaton automaton;
    int alphabet_size;
    fscanf(file, "%d", &alphabet_size);
    fscanf(file, "%d", &automaton.states_count);
    fscanf(file, "%d", &automaton.start_state);

    fscanf(file, "%d", &automaton.final_states_count);
    automaton.final_states = malloc(automaton.final_states_count * sizeof(int));
    for (int i = 0; i < automaton.final_states_count; i++)
        fscanf(file, "%d", &automaton.final_states[i]);

    automaton.transition_function = malloc(automaton.states_count * sizeof(int*));
    for (int i = 0; i < automaton.states_count; i++)
        automaton.transition_function[i] = calloc(256, sizeof(int));

    int s;
    char a;
    int s_prime;
    while (fscanf(file, "%d %c %d", &s, &a, &s_prime) == 3)
        automaton.transition_function[s][(int)a] = s_prime + 1;

    fclose(file);
    return automaton;
}

int accepts_word_w(const Automaton* automaton, const char* w0) {
    int* current_states = calloc(automaton->states_count, sizeof(int));
    current_states[automaton->start_state] = 1;

    for (const char* symbol = w0; *symbol != '\0'; symbol++) {
        int* next_states = calloc(automaton->states_count, sizeof(int));

        for (int state = 0; state < automaton->states_count; state++) {
            if (current_states[state]) {
                int next_state = automaton->transition_function[state][(int)*symbol];
                if (next_state) next_states[next_state - 1] = 1;
            }
        }

        free(current_states);
        current_states = next_states;
    }

    for (int i = 0; i < automaton->final_states_count; i++) {
        if (current_states[automaton->final_states[i]]) {
            free(current_states);
            return 1;
        }
    }

    free(current_states);
    return 0;
}

int main() {
    char filename[256];
    printf("Enter the filename: ");
    scanf("%s", filename);

    Automaton automaton = read_automaton(filename);

    char w0[256];
    printf("Enter the word w0: ");
    scanf("%s", w0);

    if (accepts_word_w(&automaton, w0))
        printf("The automaton accepts the word %s\n", w0);
    else
        printf("The automaton does not accept the word %s\n", w0);

    // Clean up
    for (int i = 0; i < automaton.states_count; i++)
        free(automaton.transition_function[i]);
    free(automaton.transition_function);
    free(automaton.final_states);

    return 0;
}
