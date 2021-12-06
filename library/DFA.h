#ifndef SPBU_C_HOMEWORKS_DFA_H
#define SPBU_C_HOMEWORKS_DFA_H

#include <stdbool.h>

enum {
    CHARACTER_NOT_IN_ALPHABET = 42,
    NOT_IN_ACCEPT_STATE = 43
};

typedef struct {
    bool (*validator)(char);
    int toStateID;
} DFATransition;

typedef struct {
    int ID;
    bool isAcceptState;
    int numberOfTransitions;
    DFATransition* transitions;
} DFAState;

typedef struct {
    int startStateID;
    int currentStateID;
    int numberOfStates;
    DFAState** states;
} DFA;

DFA* createDFA(int numberOfStates);
DFATransition createDFATransition(bool (*validator)(char), int toStateID);
DFAState* createDFAState(int ID, bool isAcceptState, int numberOfTransitions, ...);
void addDFAState(DFA* dfa, DFAState* state);
bool parseUsinfDFA(const char* string, DFA* dfa, int* error);
void resetDFA(DFA* dfa);
void destroyDFA(DFA* dfa);

#endif // SPBU_C_HOMEWORKS_DFA_H
