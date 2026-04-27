/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2
 *   Hari dan Tanggal    : Selasa, 21 April 2026
 *   Nama (NIM)          : 13224024
 *   Nama File           : soal1.c
 *   Deskripsi           : 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int jumlah = 0;
int CAP = 100;


int *add (int * data, int elemen){
    if(jumlah >= CAP-2){
        CAP = CAP + 50;
        int *temp = (int *)realloc(data, CAP*sizeof(int)); 
        if (temp == NULL) {
            printf("Memory expansion failed!\n");
            CAP = CAP - 50; 
            return data;    
        }
        data = temp;
    } 
    data[jumlah] = elemen;
    jumlah ++;
    return data;
}

void sort (int *data){
    int temp;
    for (int i = 0; i < jumlah-1; i++)
    {
        for (int j = 0; j < jumlah-1-i; j++)
        {
            if (data[j] > data[j+1])
            {
                temp = data[j+1];
                data[j+1] = data[j];
                data[j] = temp;
            }
        }
    }    
}

int main(){
    
    int *data = (int *)malloc(CAP * sizeof(int));
    int input;
    do
    {
        scanf("%d", &input);
        data = add(data, input);

    } while (input != -1);
    jumlah --;


    printf("%d\n", jumlah);
    sort(data);
    for (int i = 0; i < jumlah; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    if (jumlah%2 == 0)
    {
        printf("%d", 0.5*(data[jumlah/2] + data[jumlah/2 + 1]));
    }
    else{
        printf("%d", data[jumlah/2]);
    }
    return 0;
}
