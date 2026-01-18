/*  Nama   :  Muhammad Wifaqul Azmi
    NPM    :  23081010246
    MATKUL :  Struktur Data-F         
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stackChar[100];
int topChar = -1;

void pushChar(char ch) {
    stackChar[++topChar] = ch;
}

char popChar() {
    return (topChar >= 0) ? stackChar[topChar--] : '\0';
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
    switch (ch) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

// Matching Balancing Parenthesis
int isBalanced(char exp[]) {
    char stack[100];
    int top = -1;

    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stack[++top] = exp[i];
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1 || 
                (stack[top] == '(' && exp[i] != ')') || 
                (stack[top] == '{' && exp[i] != '}') || 
                (stack[top] == '[' && exp[i] != ']')) {
                return 0;
            }
            top--;
        }
    }
    return (top == -1);
}

// Infix to Postfix
void infixToPostfix(char *infix) {
    char postfix[100];
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            pushChar(ch);
        } else if (ch == ')') {
            while (topChar != -1 && stackChar[topChar] != '(') {
                postfix[j++] = popChar();
            }
            popChar();
        } else if (isOperator(ch)) {
            while (topChar != -1 && precedence(stackChar[topChar]) >= precedence(ch)) {
                postfix[j++] = popChar();
            }
            pushChar(ch);
        }
    }

    while (topChar != -1) {
        postfix[j++] = popChar();
    }

    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

// Postfix to Infix
void postfixToInfix(char *postfix) {
    char stack[100][100];
    int top = -1;

    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};
            strcpy(stack[++top], operand);
        } else if (isOperator(ch)) {
            char operand2[100], operand1[100];
            strcpy(operand2, stack[top--]);
            strcpy(operand1, stack[top--]);
            snprintf(stack[++top], sizeof(stack[top]), "(%s%c%s)", operand1, ch, operand2);
        }
    }

    printf("Infix: %s\n", stack[top]);
}

int main() {
    int choice;
    char expression[100];

    do {
        printf("Masukkan Pilihan Anda:\n");
        printf("1. Matching Balancing Parenthesis\n");
        printf("2. Infix ke Postfix\n");
        printf("3. Postfix ke Infix\n");
        printf("4. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
            	system("cls");
                printf("Masukkan ekspresi: ");
                fgets(expression, sizeof(expression), stdin);
                expression[strcspn(expression, "\n")] = '\0'; 
                if (isBalanced(expression))
                    printf("Tanda kurung seimbang\n");
                else
                    printf("Tanda kurung tidak seimbang\n");
                printf("\nPress enter to continue...");
                getchar();
                system("cls");
                break;
            case 2:
            	system("cls");
                printf("Masukkan Infix: ");
                fgets(expression, sizeof(expression), stdin);
                expression[strcspn(expression, "\n")] = '\0'; 
                infixToPostfix(expression);
                printf("\nPress enter to continue...");
                getchar();
                system("cls");
                break;
            case 3:
            	system("cls");
                printf("Masukkan Postfix: ");
                fgets(expression, sizeof(expression), stdin);
                expression[strcspn(expression, "\n")] = '\0'; 
                postfixToInfix(expression);
                printf("\nPress enter to continue...");
                getchar();
                system("cls");
                break;
            case 4:
                printf("\nProgram berhenti...\n");
                break;
            default:
                printf("\nPilihan anda tidak valid, coba kembali...\n");
                printf("\nPress Enter to continue...");
                getchar();
                system("cls");
        }
    } while (choice != 4);

    return 0;
}

