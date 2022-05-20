/*Numărul 197 este considerat un număr prim circular, deoarece orice combinație a cifrelor sale formează un alt număr prim.
Există 13 numere prime circulare sub 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, și 97.
Se citește N (0<=N<=10^4).
Să se afișeze toate numerele prime circulare mai mici decât N.*/
#define _CRT_SECURE_NO_WARNINGS
#include"CITIRE_SCRIERE.h"
int put(int valoare, int P)
{
    int data = 1;
    while (P--) 
    {
        data *= valoare; 
    }
    return data;
}
int Prim(int valoare)            // Functia care verifica daca numarul este prim
{
    int count = 0;
    for (int j = 1; j <= valoare && count < 3; j++)
        if (valoare % j == 0) 
            count++;
    if (count < 3) 
        return 1;
    else
        return 0;
}
int Circular(int data)          // Verifica cifrele numerelor pentru ca acestea sa fie circulare. ex: 13 -> 31
{
    int count_for_circular = 0;
    int dim = 0, temp_size, flag = 1;
    int temp = data;
    while (temp != 0) 
    {
        dim++; 
        temp /= 10;
    }

    // Verifica daca numerele circulare gasite sunt si prime
    temp = data;
    temp_size = dim - 1;
    while ((--temp_size != -1) && flag) 
    {
        if ((temp / put(10, dim - 1)) == 0) 
        { 
            temp *= 10; 
        }
        else
            temp = ((temp % (int)put(10, dim - 1)) * 10) + (temp / put(10, dim - 1));
        flag = Prim(temp);
        if (!flag)
            break;
    }
    return flag;
}
void format()               
{
    FILE* f = fopen("in.txt", "a");
    fprintf(f, "Introduceti limita: ");
    fclose(f);
}
void Extrage_date(int* limita_maxima) 
{
    FILE* f = fopen("out.txt", "w");
    fclose(f);
    int i = 0, temp = 0, flag = 0;
    do 
    {
        if (DATA[i] >= '0' && DATA[i] <= '9')
        {
            temp = temp * 10 + DATA[i] - '0'; 
            flag = 1;
        }
        else if (flag == 1)
            *limita_maxima = temp;
    } while (DATA[i++] != '\0');
}
int main()
{
    int limita_maxima, numere_gasite=0;
    CITIRE();
    Extrage_date(&limita_maxima);
    FILE* f = fopen("out.txt", "a");
    fprintf(f, "Numerele prime circulare mai mici decat %d sunt: ",limita_maxima);
    for (int i = 2; i <= limita_maxima; i++)
        if (Prim(i))
            if (Circular(i))
            {
                fprintf(f, "%d ", i);
                numere_gasite++;
            }
    fprintf(f, "\nSunt %d (de) numere prime circulare gasite!", numere_gasite);     // Afiseaza cate numere prime circulare a gasit
        fclose(f);
    return 0;
}
