#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

void tambahAwal(node **head);
void tambahTengah(node **head);
void tambahAkhir(node **head);
void cetakData(node *head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void jumlahData(node *head);
void jumlahNilaiData(node *head);

int main() {
    node *head = NULL;
    char pilih;

    do {
        system("cls");
        printf("Masukkan pilihan anda:\n");
        printf("1. Tambah data di awal linked list\n");
        printf("2. Tambah data di tengah linked list\n");
        printf("3. Tambah data di akhir linked list\n");
        printf("4. Cetak isi linked list\n");
        printf("5. Hapus data di awal linked list\n");
        printf("6. Hapus data di tengah linked list\n");
        printf("7. Hapus data di akhir linked list\n");
        printf("8. Cari data dalam linked list\n");
        printf("9. Tampilkan jumlah data di linked list\n");
        printf("0. Tampilkan hasil penjumlahan dari semua data di linked list\n");
        printf("MASUKKAN PILIHAN (Tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%c", &pilih);
        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahTengah(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4') {
            cetakData(head);
            getch();
        }
        else if (pilih == '5') {
            hapusAwal(&head);
            getch();
        }
        else if (pilih == '6') {
            hapusTengah(&head);
            getch();
        }
        else if (pilih == '7') {
            hapusAkhir(&head);
            getch();
        }
        else if (pilih == '8') {
            cariData(head);
            getch();
        }
        else if (pilih == '9') {
            jumlahData(head);
            getch();
        }
        else if (pilih == '0') {
            jumlahNilaiData(head);
            getch();
        }
    } while (pilih != 'q');

    return 0;
}

// Tambah data di awal circular linked list
void tambahAwal(node **head) {
    int bil;
    node *pNew, *pList;

    system("cls");
    printf("Masukkan bilangan : ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;

        if (*head == NULL) {
            pNew->next = pNew; 
        } else {
            pList = *head;
            while (pList->next != *head)
                pList = pList->next;
            pNew->next = *head;
            pList->next = pNew;
        }
        *head = pNew;
    } else {
        printf("Alokasi memori gagal");
    }
}

// Tambah data di tengah circular linked list
void tambahTengah(node **head) {
    int pos, bil;
    node *pNew, *pList;

    system("cls");
    cetakData(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    scanf("%d", &pos);
    printf("\nBilangan : ");
    scanf("%d", &bil);

    pList = *head;
    if (pList == NULL) {
        printf("List kosong. Tambah di awal.\n");
        return;
    }

    do {
        if (pList->data == pos) {
            break;
        }
        pList = pList->next;
    } while (pList != *head);

    if (pList->data != pos) {
        printf("Node tidak ditemukan.\n");
        return;
    }

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = pList->next;
        pList->next = pNew;
    } else {
        printf("Alokasi memori gagal");
    }
}

// Tambah data di akhir circular linked list
void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pList;

    system("cls");
    printf("Masukkan bilangan : ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;

        if (*head == NULL) {
            pNew->next = pNew; 
            *head = pNew;
        } else {
            pList = *head;
            while (pList->next != *head)
                pList = pList->next;
            pList->next = pNew;
            pNew->next = *head;
        }
    } else {
        printf("Alokasi memori gagal");
    }
}

// Cetak isi circular linked list
void cetakData(node *head) {
    node *pWalker;

    system("cls");
    if (head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }

    pWalker = head;
    do {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    } while (pWalker != head);
    printf("HEAD\n");
}

// Hapus data di awal circular linked list
void hapusAwal(node **head) {
    node *pTemp, *pList;

    system("cls");
    if (*head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        pList = *head;
        while (pList->next != *head)
            pList = pList->next;
        pTemp = *head;
        *head = (*head)->next;
        pList->next = *head;
        free(pTemp);
    }
    printf("Data awal telah dihapus.\n");
}

// Hapus data di tengah circular linked list
void hapusTengah(node **head) {
    int val;
    node *pCur, *pDel;

    system("cls");
    cetakData(*head);
    printf("\nMasukkan nilai data yang ingin dihapus : ");
    scanf("%d", &val);

    if (*head == NULL) {
        printf("\nDaftar data kosong.\n");
        return;
    }

    pCur = *head;
    do {
        if (pCur->next->data == val) {
            break;
        }
        pCur = pCur->next;
    } while (pCur != *head);

    if (pCur->next == *head) {
        printf("Data tidak ditemukan.\n");
    } else {
        pDel = pCur->next;
        pCur->next = pDel->next;
        free(pDel);
        printf("Data telah dihapus.\n");
    }
}

// Hapus data di akhir circular linked list
void hapusAkhir(node **head) {
    node *pCur, *pPrev;

    system("cls");

    if (*head == NULL) {
        printf("Linked list kosong.\n");
    } else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        printf("Data akhir telah dihapus.\n");
    } else {
        pCur = *head;
        while (pCur->next != *head) {
            pPrev = pCur;
            pCur = pCur->next;
        }
        pPrev->next = *head;
        free(pCur);
        printf("Data akhir telah dihapus.\n");
    }
}

// Cari data dalam circular linked list
void cariData(node *head) {
    int val, pos = 0;
    node *pCur = head;

    system("cls");
    printf("Masukkan nilai data yang ingin dicari : ");
    scanf("%d", &val);

    if (head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }

    do {
        if (pCur->data == val) {
            printf("Data %d ditemukan pada posisi %d.\n", val, pos);
            return;
        }
        pCur = pCur->next;
        pos++;
    } while (pCur != head);

    printf("Data %d tidak ditemukan.\n", val);
}

// Tampilkan jumlah data di circular linked list
void jumlahData(node *head) {
    int count = 0;
    node *pCur = head;

    system("cls");
    if (head == NULL) {
        printf("Jumlah data dalam linked list : 0\n");
        return;
    }

    do {
        count++;
        pCur = pCur->next;
    } while (pCur != head);

    printf("Jumlah data dalam linked list : %d\n", count);
}

// Tampilkan hasil penjumlahan dari semua data di circular linked list
void jumlahNilaiData(node *head) {
    int sum = 0;
    node *pCur;

    system("cls");
    if (head == NULL) {  
        printf("Hasil penjumlahan semua data : 0\n");
        return;
    }

    pCur = head;  
    do {
        sum += pCur->data;  
        pCur = pCur->next;  
    } while (pCur != head);  

    printf("Jumlah keseluruhan dari semua nilai data pada circular linked list : %d\n", sum);
}
