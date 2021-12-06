#include "../library/DFA.h"
#include <stdio.h>

bool isDigit(char character) { return character >= '0' && character <= '9'; }
bool isPlusOrMinus(char character) { return (character == '+' || character == '-'); }
bool isDot(char character) { return character == '.'; }
bool isE(char character) { return character == 'E'; }

int main()
{
    DFA* dfa = createDFA(8);
    addDFAState(dfa, createDFAState(0, false, 3, createDFATransition(isDigit, 1), createDFATransition(isPlusOrMinus, 2), createDFATransition(isDot, 3)));
    addDFAState(dfa, createDFAState(1, true, 3, createDFATransition(isDigit, 1), createDFATransition(isDot, 3), createDFATransition(isE, 5)));
    addDFAState(dfa, createDFAState(2, false, 2, createDFATransition(isDigit, 1), createDFATransition(isDot, 3)));
    addDFAState(dfa, createDFAState(3, false, 1, createDFATransition(isDigit, 4)));
    addDFAState(dfa, createDFAState(4, true, 2, createDFATransition(isDigit, 4), createDFATransition(isE, 5)));
    addDFAState(dfa, createDFAState(5, false, 2, createDFATransition(isPlusOrMinus, 6), createDFATransition(isDigit, 7)));
    addDFAState(dfa, createDFAState(6, false, 1, createDFATransition(isDigit, 7)));
    addDFAState(dfa, createDFAState(7, true, 1, createDFATransition(isDigit, 7)));

    int error = 0;
    char number[256];

    printf("This app will check if entered string is number in one of many forms.\n");
    printf("Please enter number: ");
    scanf("%s", number);

    bool out = parseUsinfDFA(number, dfa, &error);

    if (out)
        printf("This is a number");
    else
        printf("This is NOT a number");

    destroyDFA(dfa);
    return 0;
}