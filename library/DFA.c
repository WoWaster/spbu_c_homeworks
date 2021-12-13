#include "DFA.h"
#include <stdarg.h>
#include <stdlib.h>

DFA* createDFA(int numberOfStates)
{
    DFA* dfa = malloc(sizeof(DFA));
    dfa->startStateID = 0;
    dfa->currentStateID = 0;
    dfa->numberOfStates = numberOfStates;
    dfa->states = calloc(dfa->numberOfStates, sizeof(DFAState*));
    return dfa;
}

DFATransition createDFATransition(bool (*validator)(char), int toStateID)
{
    DFATransition transition = { validator, toStateID };
    return transition;
}

DFAState* createDFAState(int ID, bool isAcceptState, int numberOfTransitions, ...)
{
    va_list transitions;
    va_start(transitions, numberOfTransitions);

    DFAState* state = malloc(sizeof(DFAState));
    state->ID = ID;
    state->isAcceptState = isAcceptState;
    state->numberOfTransitions = numberOfTransitions;
    state->transitions = calloc(numberOfTransitions, sizeof(DFATransition));
    for (int i = 0; i < numberOfTransitions; ++i) {
        DFATransition transition = va_arg(transitions, DFATransition);
        state->transitions[i] = transition;
    }

    va_end(transitions);
    return state;
}

void addDFAState(DFA* dfa, DFAState* state)
{
    dfa->states[state->ID] = state;
}

bool parseUsingDFA(const char* string, DFA* dfa, int* error)
{
    dfa->currentStateID = dfa->startStateID;

    while (*string != '\0') {
        DFAState* currentState = dfa->states[dfa->currentStateID];
        bool wasTransition = false;
        for (int i = 0; i < currentState->numberOfTransitions; ++i) {
            if (currentState->transitions[i].validator(*string)) {
                dfa->currentStateID = currentState->transitions[i].toStateID;
                wasTransition = true;
                break;
            }
        }
        if (!wasTransition) {
            *error = CHARACTER_NOT_IN_ALPHABET;
            return false;
        }
        string++;
    }

    if (dfa->states[dfa->currentStateID]->isAcceptState) {
        return true;
    } else {
        *error = NOT_IN_ACCEPT_STATE;
        return false;
    }
}

void destroyDFA(DFA* dfa)
{
    for (int i = 0; i < dfa->numberOfStates; ++i)
        if (dfa->states[i]) {
            free(dfa->states[i]->transitions);
            free(dfa->states[i]);
        }

    free(dfa->states);
    free(dfa);
}