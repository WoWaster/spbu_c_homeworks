#ifndef SPBU_C_HOMEWORKS_DFA_H
#define SPBU_C_HOMEWORKS_DFA_H

#include <stdbool.h>

enum {
    CHARACTER_NOT_IN_ALPHABET = 42,
    NOT_IN_ACCEPT_STATE = 43
};

typedef struct DFATransition DFATransition;

typedef struct DFAState DFAState;

typedef struct DFA DFA;

DFA* createDFA(int numberOfStates);
DFATransition createDFATransition(bool (*validator)(char), int toStateID);
DFAState* createDFAState(int ID, bool isAcceptState, int numberOfTransitions, ...);
void addDFAState(DFA* dfa, DFAState* state);
bool parseUsingDFA(const char* string, DFA* dfa, int* error);
void destroyDFA(DFA* dfa);

#endif // SPBU_C_HOMEWORKS_DFA_H
