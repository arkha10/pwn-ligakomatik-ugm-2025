// gcc -Wl,-z,relro -Wl,-z,now -o chall core_fmt.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char flag[]="LK25{Yang_mawu_ikuT_bUkb3r_l1St_dibawah}";
void print_flag() {
    printf("%s\n",flag);
}

void daftar() {
    char nama_buffer[64];
    char nim_buffer[32];

    char *temp_nama = nama_buffer;
    char *temp_nim = nim_buffer;

    char **alias_nama = &temp_nama;
    char **alias_nim = &temp_nim;

    char **p_nama = alias_nama;
    char **p_nim = alias_nim;

    printf("Masukkan nama lengkap: ");
    fgets(*p_nama, 64, stdin);
    (*p_nama)[strcspn(*p_nama, "\n")] = 0;

    printf("Masukkan NIM: ");
    fgets(*p_nim, 32, stdin);
    (*p_nim)[strcspn(*p_nim, "\n")] = 0;

    char ***triple_nama = &p_nama;
    char ***triple_nim = &p_nim;

    printf("\n[Server Down]\nNama: %s\nNIM: %s\n Belum bisa terdaftar", nama_buffer, nim_buffer);
}


void masuk(){
    printf("Silahkan masukkan nama akun yang valdi: \n");

    char buf[8];

    fflush(stdout);
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        printf("\nEOF terdeteksi!...\n");
        exit(0);
    }

    printf("Uppss.. fitur ini juga rusak ternyata. sorry ya ");
    printf(buf);
    fflush(stdout);
}

void kritik() {
    printf("Terimakasih telah menggunakan aplikasi kami, berikan kritik: \n");

    char buf[300];

    fflush(stdout);
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        printf("\nEOF terdeteksi!...\n");
        exit(0);
    }

    printf("Kami akan mempertimbangkan saranmu: ");
    printf(buf);
    fflush(stdout);

}

void aplikasi() {
    int pilihan;

    while (1) {
        printf("\n============================\n");
        printf("    Selamat datang di aplikasi pembayaran pajak\n");
        printf("============================\n");
        printf("1. Daftar\n");
        printf("2. Masuk\n");
        printf("3. Kritik & Saran\n");
        printf("4. Keluar\n");
        printf("============================\n");
        printf("Pilih menu (1-4): ");
        
        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n'); 
            printf("Input tidak valid!\n");
            continue;
        }
        getchar(); 

        switch (pilihan) {
            case 1:
                daftar();
                break;
            case 2:
                masuk();
                break;
            case 3:
                kritik();
                break;
            case 4:
                printf("Terima kasih telah menggunakan aplikasi.\n");
                return;
            default:
                printf("Pilihan tidak tersedia!\n");
                break;
        }
    }
}

void setup() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
}


int main()
{
    setup();
    aplikasi();
    return 0;
}
