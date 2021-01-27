#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>

COORD coord = { 0, 0 };
struct mahasiswa{
    int nim;
    float quiz, uts, uas, nilaiAkhir, rataRata;
    char nama[20];
    bool lulus;
};
#define dataSize 10
struct mahasiswa data[dataSize];
void gotoxy(int x, int y) {
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void initData(){
    strcpy(data[0].nama, "Ahmad"); data[0].nim = 1117004; data[0].quiz = 81; data[0].uts = 90; data[0].uas = 78;
    strcpy(data[5].nama, "Adang"); data[5].nim = 1117006; data[5].quiz = 50; data[5].uts = 78; data[5].uas = 84;
    strcpy(data[2].nama, "Dudung"); data[2].nim = 1117009; data[2].quiz = 60; data[2].uts = 75; data[2].uas = 80;
    strcpy(data[3].nama, "Hendra"); data[3].nim = 1117023; data[3].quiz = 73; data[3].uts = 82; data[3].uas = 78;
    strcpy(data[4].nama, "Nashir"); data[4].nim = 1117033; data[4].quiz = 75; data[4].uts = 68; data[4].uas = 87;
    calcNilai();
}
void calcNilai(){
    for(int i = 0; i < dataSize; i++){
        data[i].nilaiAkhir = ((2 * data[i].quiz) + (3 * data[i].uts) + (5 * data[i].uas))/10;
        data[i].rataRata = (data[i].quiz + data[i].uts + data[i].uas)/3;
        if(data[i].nilaiAkhir > 52){
            data[i].lulus = true;
        }else{
            data[i].lulus = false;
        }
    }
}
void swapData(struct mahasiswa* xp, struct mahasiswa* yp)
{
    struct mahasiswa temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printData(){
    system("cls");
    gotoxy(17, 5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   SHOWING      DATA   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(0, 6);
    printf("\t===============================================================================================================");
    gotoxy(0, 7);
    printf("\tNIM\t\t Nama Mahasiswa\t\t Quiz\t UTS\t UAS\t Nilai Akhir\t Rata-Rata\t Status Lulus\t\n"); //TABLE TITLES !
    gotoxy(0, 8);
    printf("\t===============================================================================================================");
    gotoxy(0,10);
    for(int i = 0; i < dataSize; i++){
        if(data[i].nim != 0){
            printf("\t%d\t\t %s\t\t\t %.2f\t %.2f\t %.2f\t    %.2f\t   %.2f\t   %s\n\n", data[i].nim, data[i].nama, data[i].quiz, data[i].uts, data[i].uas, data[i].nilaiAkhir, data[i].rataRata, data[i].lulus ? "LULUS" : "TIDAK LULUS");
        }
    }
    printf("Press Any Key to Continue\n");
    fflush(stdin);
    getchar();
}
void printSortNim(){
    system("cls");
    int idx;
    for(int i = 0; i < dataSize; i++){
        idx = i;
        for(int j = i+1; j < dataSize; j++){
            if(data[j].nim < data[idx].nim){
                idx = j;
                swapData(&data[idx], &data[i]);
            }
        }
    }
    gotoxy(17, 5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    SORT   BY   NIM    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(0, 6);
    printf("\t===============================================================================================================");
    gotoxy(0, 7);
    printf("\tNIM\t\t Nama Mahasiswa\t\t Quiz\t UTS\t UAS\t Nilai Akhir\t Rata-Rata\t Status Lulus\t\n"); //TABLE TITLES !
    gotoxy(0, 8);
    printf("\t===============================================================================================================");
    gotoxy(0,10);
    for(int i = 0; i < dataSize; i++){
        if(data[i].nim != 0){
            printf("\t%d\t\t %s\t\t\t %.2f\t %.2f\t %.2f\t    %.2f\t   %.2f\t   %s\n\n", data[i].nim, data[i].nama, data[i].quiz, data[i].uts, data[i].uas, data[i].nilaiAkhir, data[i].rataRata, data[i].lulus ? "LULUS" : "TIDAK LULUS");
        }
    }
    printf("Press Any Key to Continue\n");
    fflush(stdin);
    getchar();
}
void printSortNilai(){
    system("cls");
    int idx;
    for(int i = 0; i < dataSize; i++){
        idx = i;
        for(int j = i+1; j < dataSize; j++){
            if(data[j].nilaiAkhir > data[idx].nilaiAkhir){
                idx = j;
                swapData(&data[idx], &data[i]);
            }
        }
    }
    gotoxy(17, 5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   SORT   BY   NILAI   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(0, 6);
    printf("\t===============================================================================================================");
    gotoxy(0, 7);
    printf("\tNIM\t\t Nama Mahasiswa\t\t Quiz\t UTS\t UAS\t Nilai Akhir\t Rata-Rata\t Status Lulus\t\n"); //TABLE TITLES !
    gotoxy(0, 8);
    printf("\t===============================================================================================================");
    gotoxy(0,10);
    for(int i = 0; i < dataSize; i++){
        if(data[i].nim != 0){
            printf("\t%d\t\t %s\t\t\t %.2f\t %.2f\t %.2f\t    %.2f\t   %.2f\t   %s\n\n", data[i].nim, data[i].nama, data[i].quiz, data[i].uts, data[i].uas, data[i].nilaiAkhir, data[i].rataRata, data[i].lulus ? "LULUS" : "TIDAK LULUS");
        }
    }
    printf("Press Any Key to Continue\n");
    fflush(stdin);
    getchar();
}
int menu(){
    system("cls");
    int choice;
    gotoxy(17, 5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   SORTING   PROGRAM   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(17, 16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(22, 8);
    printf("1. Show Data\n\n");
    gotoxy(22, 10);
    printf("2. Sort by NIM\n\n");
    gotoxy(22, 12);
    printf("3. Sort by Nilai\n\n");
    gotoxy(22, 14);
    printf("4. Exit\n\n");
    gotoxy(22, 18);
    printf("Please Enter Your Choice : ");
    scanf(" %d", &choice);
    return choice;
}
int main()
{
    initData();
    while(true){
        int choice = menu();
        bool flagExit = false;
        switch(choice){
        case 1:
            printData();
            break;
        case 2:
            printSortNim();
            break;
        case 3:
            printSortNilai();
            break;
        case 4:
            flagExit = true;
            break;
        default:
            break;
        }
        if(flagExit){
            break;
        }
    }

}

