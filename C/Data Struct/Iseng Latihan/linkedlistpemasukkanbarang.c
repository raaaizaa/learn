#include <stdio.h>
#include <stdlib.h>

/* Isi data user yang berisi id, nama, dan harga barang */ 
struct data{ 
    int id;
    char name[128];
    long long int price;
};

/* Membuat node */
struct node{
    struct data data; /* Kotak pertama di node berisi data user */
    struct node *next; /* Kotak kedua di node berisi address dari node selanjutnya */
};

/* Kotak head & tail berisi NULL atau tidak ada data */
struct node *head = NULL;
struct node *tail = NULL;

int total = 0;

int input(struct data data){

    /* Jika head tidak berisi data */
    if(head == NULL){
        /* Deklarasi variabel sementara, temp */
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp -> data = data; /* Data yang dimasukkan masuk ke variabel sementara */
        temp -> next = NULL; /* Node selanjutnya diset kosong */
        head = temp; /* Head & Tail berada di node yang sama, kenapa? karena head = NULL, yang berarti di dalam data masih 
                        belum ada head. Sehingga ketika ada data yang dimasukkan, data tersebut menjadi head sekaligus tail */
        tail = temp;
    }else{
        /* Deklarasi variabel sementara, temp */
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp -> data = data; /* Data yang dimasukkan masuk ke variabel sementara */
        temp -> next = NULL; /* Node selanjutnya diset kosong */
        tail -> next = temp; /* Si tail next bakal diisi sama si variabel sementara */
        tail = temp; /* Variabel sementara yang tadi bakal dijadiin tail */
    }

    total++;
}

void show(){
    int count = 1;

    if(head == NULL){
        system("cls");
        getchar();
        printf("Data kosong!\n");
        getchar();
    }else{
        system("cls");
        /* Deklarasi variabel current, yang ditunjukkan pada head si linked list */
        struct node *curr = head;

        /* Perulangan selama linked list tidak bernilai NULL */
        while(curr != NULL){
            printf("%d. ID: %d - Nama: %s - Harga: %lld\n", count, curr->data.id, curr->data.name, curr->data.price);
            curr = curr->next;
            count++;
        }
        getchar();
        printf("\nData berhasil ditampilkan!\n");
        getchar();
    }

}

void search(){
    int tempId;

    if(head == NULL){
        system("cls");
        getchar();
        printf("Data kosong!\n");
        getchar();
    }else{
        system("cls");
        printf("ID Barang yang dicari: ");
        scanf("%d", &tempId);
    
        /* Temporary di set ke head */
        struct node *temp = head;
        while(temp->next != NULL){ /* Perulangan selama data tidak berisi NULL */
            if(temp->data.id == tempId){ /* Jika ID yang dimasukkan sesuai dengan ID yang ada di dalam data */
                break;
            }
            temp = temp->next; /* Variabel temp bergeser ke next */
        }

        if(temp->data.id == tempId){ /* Jika ID ditemukan */
            system("cls");
            getchar();
            printf("Nama barang: %s\n", temp->data.name);
            getchar();
        }else{ /* Jika ID tidak ditemukan */
            system("cls");
            getchar();
            printf("Data dengan ID %d kosong\n", tempId);
            getchar();
        }
    }
}

void showTotal(){
    system("cls");
    getchar();
    printf("Barang yang ada di dalam data berjumlah %d barang.", total);
    getchar();

}

int main(){
    int ch;
    struct data data;

    while(1){
        system("cls");
        printf("1. Input barang masuk\n");
        printf("2. Cetak barang\n");
        printf("3. Cari barang\n");
        printf("4. Total barang\n");
        printf("5. Exit\n");
        printf("\nPilihan: ");
        scanf("%d", &ch);

        if(ch == 1){
            system("cls");
            printf("ID Barang: ");
            scanf("%d", &data.id);
            printf("Nama Barang: ");
            scanf(" %[^\n]", &data.name);
            printf("Harga Barang: ");
            scanf("%lld", &data.price);

            input(data);

            system("cls");
            printf("Data berhasil ditambahkan!\n");
            getchar();
            printf("Tekan enter untuk melanjutkan...");
            getchar();
        }else if(ch == 2){
            show();
        }else if(ch == 3){
            search();
        }else if(ch == 4){
            showTotal();
        }else if(ch == 5){
            system("cls");
            printf("Program telah dihentikan.");
            return 0;
        }else{
            system("cls");
            printf("Salah input!\n");
            return 0;
        }
    }
}
