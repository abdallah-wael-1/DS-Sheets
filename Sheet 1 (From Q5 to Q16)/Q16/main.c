#include <stdio.h>
#include "stack.h"

int isBalanced(char *exp) {
    Stack s;
    createStack(&s);

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

       
        if (ch == '(' || ch == '[' || ch == '{') {
            push(ch, &s);
        }
       
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (isStackEmpty(s))
                return 0; 

            char top;
            pop(&top, &s);

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{'))
                return 0; 
        }
    }

    return isStackEmpty(s);
}

int main() {
    char exp[100];

    printf("Enter an expression: ");
    gets(exp);

    if (isBalanced(exp))
        printf("✅ Expression is balanced.\n");
    else
        printf("❌ Expression is NOT balanced.\n");

    return 0;
}
