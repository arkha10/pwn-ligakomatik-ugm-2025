// gcc -no-pie -o twit twit_buf_ret.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define Max_twit 100
#define Max_words 100

__attribute__((naked)) void custom_rop_gadget() {
    __asm__(
        "pop %rsp;\n"
        "pop %r13;\n"
        "pop %rdi;\n"
        "ret\n"
    );
}


typedef struct {
    char judul[Max_words];
    char twit[Max_words];
} twitting;

char flag[]="LK25{K4sih_sAy4nG_Atm1n_Kpd_m3mB3r}";
void print_flag(int arg) {
    if(arg == 1949){
        printf("%s\n",flag);
        exit(0);
    }else{
        printf("uppss sepertinya ada yang kurang?!?!");
        exit(0);
    }
}

int twit_count = 0; 


int ketik(){
    char var[0x10];
    return atoi(fgets(var,0x10,stdin));
}

void Buat_twit(twitting My_account[]) {
    if (twit_count >= Max_twit) {
        printf("Jumlah twit telah mencapai batas\n");
        return;
    }

    printf("Masukkan judul twit: ");
    scanf(" %152s", My_account[twit_count].judul);

    printf("Masukkan isi twit: ");
    scanf(" %152s", My_account[twit_count].twit);
    getchar();

    twit_count++;
}

void Hapus_twit(twitting My_account[]) {
    if (twit_count == 0) {
        printf("Kamu belum membuat twit.\n");
        return;
    }

    printf("Pilih nomor twit yang ingin dihapus: ");
    int index = ketik();

    if (index < 1 || index > twit_count) {
        printf("Nomor twit tidak valid\n");
        return;
    }

    for (int i = index - 1; i < twit_count - 1; i++) {
        My_account[i] = My_account[i + 1];
    }

    twit_count--;
    printf("Twit berhasil dihapus.\n");
}


void Lihat_twit(twitting My_account[]) {
    printf("Maaf fitur sedang diperbaiki, sebagai gantinya kami akan memberi: %p\n", My_account);
}

void tampilkan_fitur() {
    printf("Menu:\n");
    printf("1. Buat twit\n");
    printf("2. Hapus twit\n");
    printf("3. Lihat twit\n");
    printf("4. Keluar\n");
}

void setup() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
}


int main() {
    setup();
    int pilihann;
    twitting My_account[Max_twit];
    while (1) {
        tampilkan_fitur();
        printf("Silahkan pilih fitur: ");
        pilihann = ketik();
        switch (pilihann) {
            case 1:
                Buat_twit(My_account);
                break;
            case 2:
                Hapus_twit(My_account);
                break;
            case 3:
                Lihat_twit(My_account);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Pilihan tidak valdi\n");
        }
    }
    return 0;
}