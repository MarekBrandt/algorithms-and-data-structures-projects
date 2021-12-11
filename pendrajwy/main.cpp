#include <iostream>

using namespace std;

#define LPEN 2

struct plik
{
    int id;
    int rozmiar;
    int ktoryPen;
};

typedef plik sType;

void zamien(sType tab[], int fIndex, int sIndex)
{
    sType temp = tab[fIndex];
    tab[fIndex] = tab[sIndex];
    tab[sIndex] = temp;
}

void quickSort(sType tab[], int lIndex, int rIndex, int tryb)
{


    if(lIndex < rIndex)
    {
        int pIndex = (lIndex + (rIndex-1))/2;
        zamien(tab, rIndex, pIndex);

        int ptr = lIndex;

        for(int i = lIndex; i < rIndex; i++)
        {
            if(tryb == 0)//po rozmiarze
            {
                if(tab[i].rozmiar < tab[rIndex].rozmiar)
                {
                    zamien(tab, ptr, i);
                    ptr++;
                }
            }
            else
            {
                if(tab[i].id < tab[rIndex].id)//po id
                {
                    zamien(tab, ptr, i);
                    ptr++;
                }
            }

        }
        zamien(tab, rIndex, ptr);

        quickSort(tab, lIndex, ptr-1, tryb);
        quickSort(tab, ptr+1, rIndex, tryb);
    }
}

int policzDodane(int lPlikow, plik tab[])
{
    int ilePlikowNaPen = 0;
    for(int i= 0; i<lPlikow; i++)
    {
        if(tab[i].ktoryPen !=0) ilePlikowNaPen++;
    }

    return ilePlikowNaPen;
}

void wypiszPliki(plik tab[], int lPlikow, int ktoryPen)
{
    for(int i= lPlikow-1; i>=0; i--)
    {
        if(tab[i].ktoryPen == ktoryPen) cout << tab[i].id << " ";
    }
}

int main() {
    int lPlikow, pojPen;
    scanf("%d %d", &lPlikow, &pojPen);

    plik * tablicaPlikow = new plik[lPlikow];

    for(int i= 0; i<lPlikow; i++)
    {
        scanf("%d %d", &tablicaPlikow[i].id, &tablicaPlikow[i].rozmiar);
    }

    quickSort(tablicaPlikow, 0, lPlikow-1, 0);

    int * objetoscDanych = new int[LPEN+1];
    for(int i = 1; i<=LPEN; i++)
    {
        objetoscDanych[i] = 0;
    }

    int ktoryPen = 1;
    for(int i= 0; i<lPlikow; i++)
    {
        if(objetoscDanych[ktoryPen] + tablicaPlikow[i].rozmiar <= pojPen)
        {
            tablicaPlikow[i].ktoryPen = ktoryPen;
            objetoscDanych[ktoryPen] += tablicaPlikow[i].rozmiar;
        }
        else if((objetoscDanych[ktoryPen] + tablicaPlikow[i].rozmiar > pojPen)&&(objetoscDanych[ktoryPen+1] + tablicaPlikow[i].rozmiar <= pojPen)&&(ktoryPen+1<=LPEN))
        {
            ktoryPen++;
            tablicaPlikow[i].ktoryPen = (ktoryPen);
            objetoscDanych[ktoryPen] += tablicaPlikow[i].rozmiar;
        }
        else tablicaPlikow[i].ktoryPen = 0;
    }

    int ilePlikowNaPen = policzDodane(lPlikow, tablicaPlikow);

    quickSort(tablicaPlikow, 0, lPlikow-1, 1);

    cout << ilePlikowNaPen<<endl;
    for(int i = 1; i <= LPEN; i++)
    {
        cout << i << ": ";
        wypiszPliki(tablicaPlikow, lPlikow, i);
        cout << endl;
    }

    delete [] objetoscDanych;
    delete [] tablicaPlikow;
    return 0;
}
