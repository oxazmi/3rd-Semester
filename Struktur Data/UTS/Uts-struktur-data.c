/* Nama: Muhammad Wifaqul Azmi
   NPM: 23081010246
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KAPASITAS_MAKSIMUM 20

typedef struct Mahasiswa {
    char nama[100];
    char jenis_kelamin;
    struct Mahasiswa *next; 
} Mahasiswa;

Mahasiswa* buatMahasiswa(char nama[], char jenis_kelamin) {
    Mahasiswa *newStudent = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    if (newStudent == NULL) {
        printf("Memori tidak cukup.\n");
        exit(1);
    }
    strcpy(newStudent->nama, nama);
    newStudent->jenis_kelamin = jenis_kelamin;
    newStudent->next = NULL;
    return newStudent;
}

int cekKondisiCindy(Mahasiswa *head) {
    if (head == NULL) return 1;

    Mahasiswa *temp = head;
    do {
        if (temp->next == head) break;
        temp = temp->next;
    } while (temp != head);

    if (temp->jenis_kelamin != 'P' || head->jenis_kelamin != 'P') {
        printf("Cindy hanya bisa ditambahkan jika nama sebelum dan sesudahnya perempuan.\n");
        return 0;
    }

    return 1;
}

int cekKondisiIrsyad(Mahasiswa *head) {
    if (head == NULL) return 0;

    Mahasiswa *temp = head;
    do {
        if (strcmp(temp->next->nama, "Arsyad") == 0 || strcmp(temp->next->next->nama, "Arsyad") == 0) {
            return 1;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Irsyad hanya bisa ditambahkan jika Arsyad berada sebelum atau sesudahnya.\n");
    return 0;
}

int cekKondisiArsyad(Mahasiswa *head) {
    if (head == NULL) return 0;

    Mahasiswa *temp = head;
    do {
        if (strcmp(temp->next->nama, "Irsyad") == 0 || strcmp(temp->next->next->nama, "Irsyad") == 0) {
            return 1;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Arsyad hanya bisa ditambahkan jika Irsyad berada sebelum atau sesudahnya.\n");
    return 0;
}

void insertStudent(Mahasiswa **head, char nama[], char jenis_kelamin, int *size) {
    if (*size >= KAPASITAS_MAKSIMUM) {
        printf("Lingkaran sudah penuh. Tidak bisa menambahkan mahasiswa lagi.\n");
        return;
    }
    
    if (strcmp(nama, "Cindy") == 0) {
        if (!cekKondisiCindy(*head)) return;
    }

    if (strcmp(nama, "Irsyad") == 0) {
        if (!cekKondisiIrsyad(*head)) return;
    }

    if (strcmp(nama, "Arsyad") == 0) {
        if (!cekKondisiArsyad(*head)) return;
    }

    Mahasiswa *newStudent = buatMahasiswa(nama, jenis_kelamin);

    if (*head == NULL) {
        *head = newStudent;
        (*head)->next = *head;
    } else {
        Mahasiswa *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newStudent;
        newStudent->next = *head;
    }
    (*size)++;
}

void hapusMahasiswa(Mahasiswa **head, char nama[], int *size) {
    if (*head == NULL) {
        printf("Lingkaran kosong.\n");
        return;
    }
    Mahasiswa *prev = NULL;
    Mahasiswa *curr = *head;
    do {
        if (strcmp(curr->nama, nama) == 0) {
            if (prev == NULL) { 
                if (curr->next == curr) { 
                    free(curr);
                    *head = NULL;
                } else {
                    Mahasiswa *last = *head;
                    while (last->next != *head) {
                        last = last->next;
                    }
                    last->next = curr->next;
                    *head = curr->next;
                    free(curr);
                }
            } else {
                prev->next = curr->next;
                free(curr);
            }
            (*size)--;
            printf("Mahasiswa %s telah keluar dari lingkaran.\n", nama);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != *head);
    printf("Mahasiswa %s tidak ditemukan.\n", nama);
}

void tampilkanMahasiswa(Mahasiswa *head) {
    if (head == NULL) {
        printf("Lingkaran kosong.\n");
        return;
    }
    Mahasiswa *temp = head;
    printf("Mahasiswa dalam lingkaran:\n");
    do {
        printf("%s (%c)\n", temp->nama, temp->jenis_kelamin);
        temp = temp->next;
    } while (temp != head);
}

void pisahkanLingkaran(Mahasiswa *head, Mahasiswa **maleHead, Mahasiswa **femaleHead) {
    if (head == NULL) {
        printf("Lingkaran kosong.\n");
        return;
    }
    Mahasiswa *temp = head;
    do {
        if (temp->jenis_kelamin == 'L') {
            insertStudent(maleHead, temp->nama, temp->jenis_kelamin, &(int){0});
        } else {
            insertStudent(femaleHead, temp->nama, temp->jenis_kelamin, &(int){0});
        }
        temp = temp->next;
    } while (temp != head);
}

int main() {
    Mahasiswa *head = NULL; 
    Mahasiswa *maleHead = NULL; 
    Mahasiswa *femaleHead = NULL; 
    int size = 0;
    int pilihan;
    char nama[50];
    char jenis_kelamin;
    
    while (1) {
    	printf("\nAcara Api Unggun Kelas Struktur Data\n");
        printf("1. Tambahkan Data Mahasiswa ke Lingkaran Api Unggun\n");
        printf("2. Hapus Data Mahasiswa dari Lingkaran Unggun\n");
        printf("3. Tampilkan Mahasiswa dalam Lingkara Api Unggunn\n");
        printf("4. Pisahkan Lingkaran Api Unggun antara Laki-laki dan Perempuan\n");
        printf("5. Exit\n");
        printf("Masukkan Pilihan Anda: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                printf("Masukkan nama: ");
                scanf("%s", nama);
                printf("Masukkan jenis kelamin (L/P): ");
                scanf(" %c", &jenis_kelamin);
                
                insertStudent(&head, nama, jenis_kelamin, &size);
                break;
            case 2:
                printf("Masukkan nama mahasiswa yang ingin dihapus: ");
                scanf("%s", nama);
                hapusMahasiswa(&head, nama, &size);
                break;
            case 3:
                tampilkanMahasiswa(head);
                break;
            case 4:
                pisahkanLingkaran(head, &maleHead, &femaleHead);
                printf("\nLingkaran laki-laki:\n");
                tampilkanMahasiswa(maleHead);
                printf("\nLingkaran perempuan:\n");
                tampilkanMahasiswa(femaleHead);
                break;
            case 5:
                exit(0);
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    
    return 0;
}

