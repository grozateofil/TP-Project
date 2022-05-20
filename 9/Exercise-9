/*Se consideră un tabel în care se află toate numerele de la 1 la 2^(2N).
Dându-se un număr natural nenul N (N ≤ 8) și Q (0 < Q ≤ 1 000) perechi de valori întregi X și Y, să se afișeze care este valoarea din tabel la fiecare dintre coordonatele (X,Y). 
Coordonatele tabelului încep de la (1,1) și se garantează că sunt valide în matrice. De pe prima linie se citesc numerele N și Q, apoi urmează Q linii cu coordonate.
Complexitate maximă O(Q × N^2).*/
#define _CRT_SECURE_NO_WARNINGS
#include"CITIRE_SCRIERE.h"
struct Pereche
{
    int X;
    int Y;
}P[1000];
int N, Q;
//Calculeaza 2^2N
int putere(int numar, int exponent)
{
    int temp = 1;
    for (int i = 0; i < exponent; i++)
        temp = temp * numar;
    return temp;
}
//Traseaza liniile
int linie(int lungime_linie)
{
    FILE* f = fopen("out.txt", "a");
    fprintf(f, "\n ");
    for (int i = 0; i < lungime_linie - 1; i++)
        fprintf(f, "-");
    fprintf(f, "\n");
    fclose(f);
    return 1;
}

void Tabel()
{
    int counter = 0, flag = 0, lungime_linie = 0;  // Partea de design
    FILE* f;
    int T[128][128];
    int tracker[10];
    // Initializare
    for (int i = 0, limita = putere(2, N - 1); i < limita; i++)
        tracker[i] = putere(2, (2 * N)) - 4 * i;

    //Stabileste limitele tabelului si-l creaza
    for (int i = 0, limita_I = putere(2, N); i < limita_I; i++)
        for (int j = 0, limita_J = putere(2, N); j < limita_J; j++)
        {
            if (j % 2 == 0)
                T[i][j] = tracker[counter]--;
            else
                T[i][j] = tracker[counter]--;

            if (j % 2 != 0 && j > 0)
            {
                counter++;
                if (counter == putere(2, N - 1))
                {
                    counter = 0; flag++;
                    if (flag % 2 == 0 && flag > 0)
                        for (int k = 0, data = putere(2, (2 * N)) - putere(2, N) * flag; k < putere(2, N - 1); k++)
                            tracker[k] = data - 4 * k;
                }
            }
            if (i + 1 == limita_I && j + 1 == limita_J)
                lungime_linie = 9 * limita_I;
        }

    //Afiseaza tabelul
    for (int i = 0, limita_I = putere(2, N); linie(lungime_linie) && i < limita_I; i++)
    {
        f = fopen("out.txt", "a");
        for (int j = 0, limita_J = putere(2, N); j < limita_J; j++)
        {
            if (j == 0)
                fprintf(f, "|");
            fprintf(f, "  %4d  |", T[i][j]);
        }
        fclose(f);
    }
    f = fopen("out.txt", "a");
    for (int i = 0; i < Q; i++)
        fprintf(f, "\nNumarul situat la coordonata (%d,%d) este : %d", P[i].X, P[i].Y, T[P[i].X - 1][P[i].Y - 1]);
    fclose(f);
}

void format()
{
    FILE* f = fopen("in.txt", "a");
    fprintf(f, "Valoarea lui N:\nValoarea lui Q:\nIntroduceti coordonatele sub forma (X,Y):\n");
    fclose(f);
}

void Extrage_data()     // Extrage datele din fisierul DATA
{
    FILE* f = fopen("out.txt", "w");
    fprintf(f, DATA);
    fclose(f);
    for (int i = 0, temp = 0, top = -1, flag = -1; DATA[i] != '\0'; i++)  //temp - stocheaza valorile temporare, top - numara elementele dintr-un tablou
        if (DATA[i] >= '0' && DATA[i] <= '9')
        {
            temp = temp * 10 + DATA[i] - 48;
            if (flag == -1) flag = 0;
        }
        else if (DATA[i - 1] >= '0' && DATA[i - 1] <= '9')
            switch (flag)
            {
            case 0: N = temp; flag++; temp = 0;
                break;
            case 1: Q = temp; flag++; temp = 0;
                break;
            case 2: P[++top].X = temp; temp = 0; flag = 3;
                break;
            case 3: P[top].Y = temp; temp = 0; flag = 2;
                break;
            }
}

int main()
{
    CITIRE();
    Extrage_data();
    Tabel();
    return 0;
}
