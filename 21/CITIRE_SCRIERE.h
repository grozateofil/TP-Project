#include<stdio.h>
char DATA[200];     // Este un tablou variabil de tip de caractere 
void format();
void CITIRE()       // Creaza fisierul in.txt si citeste datele pe care eu le-am introdus
{
    int top = -1;
    FILE* f = fopen("in.txt", "w");
    fclose(f);
    printf("Fisierul in.txt a fost creat cu succes!\nVa rog completati corespunzator fisierul!\nDupa ce l-ati completat apasati ENTER!");
    format();
    getchar();
    f = fopen("in.txt", "r");
    while ((DATA[++top] = fgetc(f)) != EOF);
    DATA[top] = '\0';
    fclose(f);
}

void SCRIERE()      //Creaza fisierul out.txt si scrie caracterele
{
    FILE* f = fopen("out.txt", "a");
    fprintf(f, "%s", DATA);
    fclose(f);
}
