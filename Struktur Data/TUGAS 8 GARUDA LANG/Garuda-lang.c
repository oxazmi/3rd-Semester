/* Nama   : Muhammad Wifaqul Azmi
 NPM    : 23081010246
 Matkul : Struktur Data F081
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MAX 10000

struct node {
    char charData;
    struct node *next;
};

typedef struct node node;

struct stack {
    int count;
    struct node *top;
};

typedef struct stack stack;

stack* createStack() {
    stack *newStack = (stack *)malloc(sizeof(stack));
    if (newStack != NULL) {
        newStack->count = 0;
        newStack->top = NULL;
    }
    return newStack;
}

void pushChar(stack *stack, char data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->charData = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;
}

char popChar(stack *stack) {
    if (stack->top == NULL) {
        return '\0';
    }
    node *temp = stack->top;
    char data = temp->charData;
    stack->top = stack->top->next;
    stack->count--;
    free(temp);
    return data;
}

int isEmpty(stack *stack) {
    return stack->top == NULL;
}

void destroyStack(stack *stack) {
    while (!isEmpty(stack)) {
        popChar(stack);
    }
}

void checkBalancedParenthesis(char *expression) {
    stack *s = createStack();
    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[' || expression[i] == '<') {
            pushChar(s, expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']' || expression[i] == '>') {
            if (isEmpty(s)) {
                destroyStack(s);
                printf("Ekspresi Invalid...\n");
                return;
            }
            char top = popChar(s);
            if ((expression[i] == ')' && top != '(') ||
                (expression[i] == '}' && top != '{') ||
                (expression[i] == ']' && top != '[') ||
                (expression[i] == '>' && top != '<')) {
                destroyStack(s);
                printf("Ekspresi Invalid...\n");
                return;
            }
        }
    }
    if (isEmpty(s)) {
        printf("Kode/Syntaks Valid...\n");
    } else {
        printf("Kode/Syntaks Invalid...\n");
    }
    destroyStack(s);
}

int main() {
    char code[MAX];
    int i = 0;
    int empty_line_count = 0;
    int exit_flag = 0;

    do {
        system("cls");
        printf("=========================================\n");
    	printf("           Compiler Garuda Lang          \n");
    	printf("=========================================\n");
        printf("Note: Akhiri dengan klik enter 2x atau dua baris kosong\n\n");
        printf("Ketik 'exit' untuk keluar\n\n");
        printf("Masukan Kode Anda\n: ");

        memset(code, 0, MAX);
        i = 0;
        empty_line_count = 0;

        while (fgets(code + i, MAX - i, stdin)) {
            if (strstr(code, "exit") != NULL) {
                exit_flag = 1;  
                break;
            }

            if (strcmp(code + i, "\n") == 0) {
                empty_line_count++;
                if (empty_line_count == 2) {
                    break;
                }
            } else {
                empty_line_count = 0;
            }

            i += strlen(code + i);
        }

        if (exit_flag) {
            printf("\nKeluar dari program...\n");
            break;
        }

        checkBalancedParenthesis(code);

        printf("\nPress Enter to continue...");
        getchar();
    } while (1);

    return 0;
}

