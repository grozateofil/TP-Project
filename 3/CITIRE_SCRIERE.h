#include<stdio.h>
char DATA[200];
void format();
void CITIRE()
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

void SCRIERE()
{
    FILE* f = fopen("out.txt", "a");
    fprintf(f, "%s", DATA);
    fclose(f);
}
