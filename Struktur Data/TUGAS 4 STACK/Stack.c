/*  Nama   :  Muhammad Wifaqul Azmi
    NPM    :  23081010246
    MATKUL :  Struktur Data-F         
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct node {
    int data;
    struct node *next;
}; typedef struct node node;

struct stack {
    int count;
    struct node *top;
}; typedef struct stack stack;

void push(stack *stack);
void pop(stack *stack);
void top(stack *stack);
int full(stack *stack);
int empty(stack *stack);
void count(stack *stack); 
void display(stack *stack);
void destroy(stack *stack);

int main() {
    stack s;
    s.count = 0;
    s.top = NULL;
    
    int pilihan;
    
    do {
        system("cls");
        printf("Masukkan Pilihan Anda:\n");
        printf("1. Push Stack\n");
        printf("2. Pop Stack\n");
        printf("3. Stack Top\n");
        printf("4. Stack Count\n");
        printf("5. Display Stack\n");
        printf("6. Destroy Stack\n");
        printf("7. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        printf("\n");
        
        switch(pilihan) {
            case 1:
                push(&s);
                getchar();
                getchar();
                break;
            case 2:
                pop(&s);
                getchar();
                getchar();
                break;
            case 3:
                top(&s);
                getchar();
                getchar();
                break;
            case 4:    
                count(&s);  
                getchar();
                getchar();
                break;            
            case 5:
                display(&s);
                getchar();
                getchar();
                break;
            case 6:
                destroy(&s);
                getchar();
                getchar();
                break;            
            case 7:
                printf("Program berhenti...");
                break;    
            default:
                printf("Pilihan anda tidak valid, coba kembali...");
                getchar();
                getchar();
        }
        
    } while(pilihan != 7);
    
    return 0;
}

void push(stack *stack) {
    system("cls");
    if(full(stack)) {
        printf("Stack sudah penuh...");
        return;
    }
    
    node *newNode = (node *)malloc(sizeof(node));
    int bil;
    printf("Masukkan bilangan: ");
    scanf("%d", &bil);
    
    newNode->data = bil;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;
    printf("\n%d berhasil ditambahkan ke dalam Stack...", bil);    
}

void pop(stack *stack) {
    system("cls");
    if(empty(stack)) {
        printf("Stack masih kosong...");
        return;
    }
    
    node *del = stack->top;
    printf("%d berhasil dihapus dari Stack...", del->data);
    stack->top = stack->top->next;
    free(del);
    stack->count--;
}

void top(stack *stack) {
    system("cls");
    if(stack->top == NULL) {
        printf("Stack masih kosong...");
        return;
    }
    
    node *atas = stack->top;
    printf("%d merupakan data teratas...", atas->data);
}

int full(stack *stack) {
    if(stack->count == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int empty(stack *stack) {
    if(stack->top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void count(stack *stack) {  
    system("cls");
    printf("Jumlah data dalam Stack adalah %d", stack->count);
}

void display(stack *stack) {
    system("cls");
    if(empty(stack)) {
        printf("Stack masih kosong...");
        return;
    }
    
    node *display = stack->top;
    while(display != NULL) {
        printf("%d\n", display->data);
        display = display->next;
    } 
}

void destroy(stack *stack) {
    system("cls");
    if(stack->top == NULL) {
        printf("Stack masih kosong...");
        return;
    }
    
    while(stack->top != NULL) {
        node *del = stack->top;
        stack->top = stack->top->next;
        free(del);    
    }
    printf("Stack berhasil dikosongkan...");
    stack->count = 0;
    return;
}
