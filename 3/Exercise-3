/*Într-un oraș circular, numărul total de locuitori este N. Fiecare dintre aceștia are o casă și un
birou propriu, deci în total există 2N construcții, așezate la periferia orașului. Distanța între oricare
două clădiri consecutive este egală cu 1. Dându-se cele N perechi de numere care reprezintă pozițiile
casei și a biroului fiecărui locuitor, să se afișeze distanța maximă parcursă de un locuitor, știind că
fiecare locuitor alege mereu drumul cel mai scurt de la casa sa spre birou. Complexitate maximă
O(N).
*/
#define _CRT_SECURE_NO_WARNINGS
#include"CITIRE_SCRIERE.h"
struct Constructii
{
    int casa, birou;
};
void format()           // Creaza fisierul in.txt si afiseaza mesajul
{
    FILE* f = fopen("in.txt", "a");
    fprintf(f, "Numarul de locuitori: \nIntroduceti perechile (Casa, Birou):\n");
    fclose(f);
}
void Extrage_data(int* locuitori)       // Extrage datele din sirul DATA
{
    int temp = 0;                       // temp - stocheaza valori temporare
    for (int i = 0; DATA[i] != '\0'; i++)
        if (DATA[i] >= '0' && DATA[i] <= '9')
        {
            temp = temp * 10 + DATA[i] - 48; DATA[i] = ' ';
        }
        else if (temp != 0)
        {
            *locuitori = temp;
            break;
        }
}
int main()
{
    int locuitori = 0, temp = 0, flag = 1, top = -1, i = 0;
    CITIRE();                   // Creaza fisierul in.txt si citeste datele pe care eu le-am introdus
    SCRIERE();                  // Creaza fisierul out.txt si scrie rezultatul
    FILE* f = fopen("out.txt", "a");
    Extrage_data(&locuitori);
    struct Constructii C[50];   
    if (locuitori == NULL)      // Daca nu ati introdus numarul de locuitori afiseaza mesajul:
    {
        printf("\nNu ati introdus numarul de locuitori!\n");
        return 0;
    }
    else
        printf("\nVerificati fisierul out.txt!\n");
    do
    {
        if (DATA[i] >= '0' && DATA[i] <= '9')
        {
            temp = temp * 10 + DATA[i] - 48; DATA[i] = ' ';
        }
        else if (temp != 0)
            if (flag == 1)
            {
                C[++top].casa = temp; temp = 0; flag++;
            }
            else if (flag == 2)
            {
                C[top].birou = temp; temp = 0; flag = 1;
            }
    } while (DATA[i++] != '\0');

    for (int i = 0; i < locuitori; i++)
    {
        int sensul_acelor_ceasornicului = 0, invers_acelor_ceasornicului = 0, temp = C[i].casa;
        fprintf(f, "\n%cDistanta cea mai scurta pentru persoana %d din (%d , %d) este: ", '\0', i + 1, C[i].casa, C[i].birou);
        //Prima data parcurge drumul in sensul acelor de ceasornic:
        while (C[i].casa++ != C[i].birou)
        {
            sensul_acelor_ceasornicului++;
            if (C[i].casa > (2 * locuitori))
                C[i].casa = C[i].casa % (2 * locuitori + 1);
        }
        //Apoi parcurge drumul in sens invers acelor de ceasornic:
        C[i].casa = temp;
        while (C[i].casa-- != C[i].birou)
        {
            invers_acelor_ceasornicului++;
            if (C[i].casa < 1) 
                C[i].casa = 2 * locuitori;
        }
        ///Acum compara cele 2 drumuri gasite si afiseaza distanta cea mai scurta:
        if (sensul_acelor_ceasornicului < invers_acelor_ceasornicului)
            fprintf(f, " %d  In sensul acelor de ceasornic.", sensul_acelor_ceasornicului);
        else if (sensul_acelor_ceasornicului > invers_acelor_ceasornicului)
            fprintf(f, " %d  Invers acelor de ceasornic.", invers_acelor_ceasornicului);
        else
            fprintf(f, " %d  In ambele directii.", sensul_acelor_ceasornicului);
    }
    fclose(f);
    return 0;
}
