// # gcc -no-pie -o chall supersemar_heap.c 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char flag[]="LK25{0mGG_aBanKnya_H3ckeerz_y}";
void print_flag(int arg) {
    printf("%s\n",flag);
}
void banner() {
    puts("Silahkan menulis sesuatu ke catatanku");
}



int read_option() {
    int option;
    scanf("%d", &option);
    getchar();
    return option;
}

void show_menu() {
    puts("\n[1] Ubah apa yang sudah kutulis");
    puts("[2] Tulis cerita");
    puts("[3] Halaman selanjutnya");
    printf(">> ");
}

void setup() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
}


int main() {
    setup();
    banner();
    char *chunk[8];
    unsigned char value;
    int offset;
    int i;
    void *first_buf = NULL;
    void *buf = NULL;
    void *last_buf = NULL;
    void *dummy;
    chunk[0] = malloc(0x40);
    char temp[32];


    while (1) {
        show_menu();
        int option = read_option();

        if (option == 2) {
            printf("Tulis sesuatu: ");
            read(0, chunk[0], 0x30); 
            
        } else if (option == 1) {
            first_buf = malloc(0x60);
            strcpy((char *)first_buf, "AAAAAAAA");
        
            buf = malloc(0x60);
            strcpy((char *)buf, "========================Ini hadiah buat kamu: ");
            sprintf(temp, "%p", chunk);   
            strcat((char *)buf, temp);      
                    
        
            last_buf = malloc(0x60);
            strcpy((char *)last_buf, "========================Upps kamu melewatkan harta karun");
        
        
            free(buf);
            free(last_buf);
        
            printf("Silahkan ubah 1 huruf\n");
            printf("Halaman?: ");
            scanf("%d", &offset);
            printf("Huruf: ");
            scanf("%1s", &value);
        
            *((unsigned char *)first_buf + offset) = value;
        
            dummy = malloc(0x60);
            puts((char *)((char *)dummy + 0x10));
            


        } else if (option == 3) {
            chunk[0] = *(void **)((long)chunk[0] + 8);
            
        } else if (option == 1949) {
            free(chunk[0]);
            puts("Sayonara :)");
            return 0;
        } else {
            puts("opsi invaldi !");
        }
    }

}
