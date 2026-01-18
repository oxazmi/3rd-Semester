#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;  
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

int main()
{
  node *head;
  char pilih;

  head = NULL;
  do{
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
     else if (pilih == '4'){
            cetakData(head);
         getch();
     }
     else if (pilih == '5'){
            hapusAwal(&head);
         getch();
     }
     else if (pilih == '6'){
            hapusTengah(&head);
         getch();
     }
     else if (pilih == '7'){
            hapusAkhir(&head);
         getch();
     }
     else if (pilih == '8'){
            cariData(head);
         getch();
     }
     else if (pilih == '9'){
            jumlahData(head);
         getch();
     }
     else if (pilih == '0'){
            jumlahNilaiData(head);
         getch();
     }
  } while (pilih != 'q');
  
  return 0;
}

// Tambah data di awal linked list //

void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin); 
  printf("Masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
      pNew->data = bil;
      pNew->next = *head;
      pNew->prev = NULL;  

      if (*head != NULL) {
          (*head)->prev = pNew;  
      }

      *head = pNew;
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

// Tambah data di tengah linked list //

void tambahTengah(node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  cetakData(*head);
  printf("\nPosisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nBilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur->data != pos) {
    pCur = pCur->next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = pCur->next;
     pNew->prev = pCur;  

     if (pCur->next != NULL) {
         pCur->next->prev = pNew;  
     }

     pCur->next = pNew;
  }
}

// Tambah data di akhir linked list //

void tambahAkhir(node **head){
  int bil;
  node *pNew, *pCur;

  system("cls");
  printf("Masukkan bilangan : ");
  scanf("%d", &bil);

  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
      pNew->data = bil;
      pNew->next = NULL;

      if (*head == NULL) {
        pNew->prev = NULL;  
        *head = pNew;
      } else {
        pCur = *head;
        while (pCur->next != NULL) {
          pCur = pCur->next;
        }
        pCur->next = pNew;
        pNew->prev = pCur;  
      }
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

// Cetak isi linked list //

void cetakData(node *head){
    node *pWalker;
    system("cls");
    pWalker = head;
    while (pWalker != NULL){
        printf("%d <-> ", pWalker->data);
        pWalker = pWalker->next;
    }
    printf("NULL\n");
}

// Hapus data di awal linked list //

void hapusAwal(node **head) {
    node *pTemp;

    system("cls");
    if (*head == NULL) {
        printf("Daftar data saat ini kosong. Tidak ada data yang dapat dihapus.\n");
    } else {
        pTemp = *head;
        *head = (*head)->next;

        if (*head != NULL) {
            (*head)->prev = NULL;  
        }

        free(pTemp);
        printf("Data awal telah dihapus.\n");
    }
    getch();
}

// Hapus data di tengah linked list //

void hapusTengah(node **head) {
  int val;
  node *pCur;

  system("cls");
  cetakData(*head);
  printf("\nMasukkan nilai data yang ingin dihapus : ");
  scanf("%d", &val);

  if (*head == NULL) {
    printf("\nDaftar data saat ini kosong. Tidak ada data yang dapat dihapus.\n");
    return;
  }

  pCur = *head;

  while (pCur != NULL && pCur->data != val) {
    pCur = pCur->next;
  }

  if (pCur == NULL) {
    printf("\nData tidak ditemukan.\n");
  } else {
    if (pCur->prev != NULL) {
        pCur->prev->next = pCur->next;  
    } else {
        *head = pCur->next;  
    }

    if (pCur->next != NULL) {
        pCur->next->prev = pCur->prev;  
    }

    free(pCur);
    printf("\nData telah dihapus.\n");
  }
}

// Hapus data di akhir linked list //

void hapusAkhir(node **head) {
    node *pCur;

    system("cls");

    if (*head == NULL) {
        printf("Daftar data saat ini kosong. Tidak ada data yang dapat dihapus.\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Data akhir telah dihapus.\n");
    } else {
        pCur = *head;
        while (pCur->next != NULL) {
            pCur = pCur->next;
        }

        pCur->prev->next = NULL;  
        free(pCur);
        printf("Data akhir telah dihapus.\n");
    }
}

// Cari data dalam linked list //

void cariData(node *head) {
  int val, pos = 0;
  node *pCur = head;

  system("cls");
  printf("Masukkan nilai data yang ingin dicari : ");
  scanf("%d", &val);

  while (pCur != NULL) {
    if (pCur->data == val) {
      printf("Data %d ditemukan pada posisi %d.\n", val, pos);
      return;
    }
    pCur = pCur->next;
    pos++;
  }

  printf("\nData %d tidak ditemukan.\n", val);
}

// Tampilkan jumlah data di linked list //

void jumlahData(node *head) {
  int count = 0;
  node *pCur = head;

  system("cls");
  while (pCur != NULL) {
    count++;
    pCur = pCur->next;
  }

  printf("Jumlah data dalam linked list : %d\n", count);
}

// Tampilkan hasil penjumlahan dari semua data di linked list //

void jumlahNilaiData(node *head) {
  int sum = 0;
  node *pCur = head;

  system("cls");
  while (pCur != NULL) {
    sum += pCur->data;
    pCur = pCur->next;
  }

  printf("Jumlah keseluruhan dari semua nilai data pada linked list : %d\n", sum);
}

