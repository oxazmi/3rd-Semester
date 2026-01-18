/*  Nama   :  Muhammad Wifaqul Azmi
    NPM    :  23081010246
    MATKUL :  Struktur Data-F         
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node {
    int data;
    struct node *next;
}; typedef struct node node;

struct queue {
    int count;
    struct node *front;
    struct node *rear;
}; typedef struct queue queue;

void createQueue(queue *q);
void enqueue(queue *q);
void dequeue(queue *q);
void queueFront(queue *q);
void queueRear(queue *q);
int isEmpty(queue *q);
int isFull(queue *q);
void queueCount(queue *q);
void displayQueue(queue *q);
void destroyQueue(queue *q);

int main() {
    queue q;
    createQueue(&q); 
    
    int pilihan;
    
    do {
        system("cls");
        printf("Masukkan Pilihan Anda:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Queue Front\n");
        printf("4. Queue Rear\n");
        printf("5. Display Queue\n");
        printf("6. Check Empty Queue\n");
        printf("7. Check Full Queue\n");
        printf("8. Queue Count\n");
        printf("9. Destroy Queue\n");
        printf("10. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        printf("\n");
        
        switch(pilihan) {
            case 1:
                enqueue(&q);
                getchar();
                getchar();
                break;
            case 2:
                dequeue(&q);
                getchar();
                getchar();
                break;
            case 3:
                queueFront(&q);
                getchar();
                getchar();
                break;
            case 4:    
                queueRear(&q);
                getchar();
                getchar();
                break;
            case 5:
                displayQueue(&q);
                getchar();
                getchar();
                break;
            case 6:
                printf("Queue is %sempty...\n", isEmpty(&q) ? "" : "not ");
                getchar();
                getchar();
                break;
            case 7:
                printf("Queue is %sfull...\n", isFull(&q) ? "" : "not ");
                getchar();
                getchar();
                break;
            case 8:
                queueCount(&q);
                getchar();
                getchar();
                break;            
            case 9:
                destroyQueue(&q);
                getchar();
                getchar();
                break;
            case 10:
                printf("Program berhenti...");
                break;    
            default:
                printf("Pilihan anda tidak valid, coba kembali...");
                getchar();
                getchar();
        }
        
    } while(pilihan != 10);
    
    return 0;
}

void createQueue(queue *q) {
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
    printf("Queue berhasil dibuat...\n");
}

void enqueue(queue *q) {
    if(isFull(q)) {
        printf("Queue sudah penuh...");
        return;
    }
    
    node *newNode = (node *)malloc(sizeof(node));
    int bil;
    printf("Masukkan bilangan: ");
    scanf("%d", &bil);
    
    newNode->data = bil;
    newNode->next = NULL;
    if(q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
    printf("\n%d berhasil ditambahkan ke dalam Queue...", bil);    
}

void dequeue(queue *q) {
    if(isEmpty(q)) {
        printf("Queue masih kosong...");
        return;
    }
    
    node *del = q->front;
    printf("%d berhasil dihapus dari Queue...\n", del->data);
    q->front = q->front->next;
    if(q->front == NULL) {
        q->rear = NULL;
    }
    free(del);
    q->count--;
}

void queueFront(queue *q) {
    if(isEmpty(q)) {
        printf("Queue masih kosong...");
        return;
    }
    printf("Data di depan Queue: %d\n", q->front->data);
}

void queueRear(queue *q) {
    if(isEmpty(q)) {
        printf("Queue masih kosong...");
        return;
    }
    printf("Data di belakang Queue: %d\n", q->rear->data);
}

int isEmpty(queue *q) {
    return q->front == NULL;
}

int isFull(queue *q) {
    return q->count == MAX;
}

void queueCount(queue *q) {
    printf("Jumlah data dalam Queue adalah %d\n", q->count);
}

void displayQueue(queue *q) {
    if(isEmpty(q)) {
        printf("Queue masih kosong...\n");
        return;
    }
    
    node *current = q->front;
    printf("Isi Queue:\n");
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    } 
}

void destroyQueue(queue *q) {
    while(!isEmpty(q)) {
        dequeue(q);
    }
    printf("\nQueue berhasil dikosongkan...");
}

