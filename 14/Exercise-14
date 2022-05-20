/*Se citesc două mulțimi de numere naturale A și B. Să se afișeze reuniunea, intersectia, diferenta celor două mulțimi.*/
#define _CRT_SECURE_NO_WARNINGS
#include"CITIRE_SCRIERE.h"
int A1[20], B1[20];         //A1 stocheaza datele din A, iar B1 stocheaza datele din B
int T1 = -1, T2 = -1;       //T1 si T2 sunt 2 variabile care stocheaza nr. de valori stocate in A1 si B1
int R[30], I[30], D[30];
void format() 
{
    FILE* f = fopen("in.txt", "w");
    fprintf(f, "A= {  }\nB= {  }");
    fclose(f);
}

void Ia_Valoare()           // Extrage datele din sirul DATA
{
    int i = 0, temp = 0, flag = 0;
    char status = '\0';     // status 'r' si status 'w' constau in a verifica daca ar trebui sa citim sau sa sticam datele
    do 
    {
        if (DATA[i] == 'A') 
            flag = 0;
        else if (DATA[i] == 'B') 
            flag = 1;

        if (DATA[i] >= '0' && DATA[i] <= '9')
        {
            temp = temp * 10 + DATA[i] - '0';
            status = 'r';           // Citeste fisierul in.txt
        }
        else if (status=='r')
        {
            status = 'w';           // Scrie (copiaza) toate numere din A si B in fisierul out.txt la locul potrivit
            if (!flag) 
            { 
                A1[++T1] = temp; 
                temp = 0; 
            }
            else 
            { 
                B1[++T2] = temp; 
                temp = 0;
            }
        }
    } while (DATA[i++] != '\0');
}

// Afiseaza rezultatele in fisierul out.txt
void Scrie_Rezultatul(int P1, int P2, int P3)       
{
    FILE* f = fopen("out.txt", "a");
    fprintf(f, "\nREUNIUNEA = {");
    for (int i = 0; i <= P1; i++)       // P1 mentine numerele in multimea reuniunii
    {
        fprintf(f, "%d", R[i]); 
        if (i != P1) 
            fprintf(f, ",");
    }
    fprintf(f, "}\nINTERSECTIA = {");
    for (int i = 0; i <= P2; i++)       // P2 mentine numere in multimea intersectiei
    {
        fprintf(f, "%d", I[i]); 
        if (i != P2) 
            fprintf(f, ",");
    }
    fprintf(f, "}\nDIFERENTA = {");
    for (int i = 0; i <= P3; i++)       // P3 mentine datele in multimea diferentei
    {
        fprintf(f, "%d", D[i]); 
        if (i != P3) 
            fprintf(f, ",");
    }
    fprintf(f, "}\n");
    fclose(f);
}

void R_I_D()        // functiea R_I_D aduce laolalta functiile P1, P2, P3
{
    int P1, P2, P3;
    P1 = P2 = P3 = -1;
    for (int i = 0; i <= T2; i++)
        R[++P1] = B1[i];

    for (int i = 0; i <= T1; i++)
        for (int j = 0, count = 0; j <= T2; j++)
        {
            if (A1[i] == B1[j]) 
                I[++P2] = A1[i];
            else 
                count++;
            if (count == T2 + 1)
            {
                D[++P3] = A1[i]; 
                R[++P1] = A1[i];
            }
        }
    Scrie_Rezultatul(P1, P2, P3);       // In final afisam rezultatul dorit
}

int main()
{
    CITIRE();
    Ia_Valoare();
    R_I_D();
    return 0;
}
