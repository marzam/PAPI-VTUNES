#include <cmath>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstdio>
#include <climits>
#include <cstring>
#include <string>
using namespace std;
void particao(int Esq, int Dir, int *i, int *j, int *vet){
    int x, w;
    *i = Esq; *j = Dir;
    x = vet[(*i + *j) / 2];   
    do{
        while (x > vet[*i])
            (*i)++;
        
        while (x < vet[*j])
            (*j)--;
        
        if (*i <= *j){
            w = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = w;
            (*i)++;
            (*j)--;
        }
    }while (*i <= *j);

 }

void quick_sort(int Esq, int Dir, int *vet){
    int i, j;
    particao(Esq, Dir, &i, &j, vet);
    if (Esq < j) quick_sort(Esq, j, vet);
    if (i < Dir) quick_sort(i, Dir, vet);
}

void desordenado(int *vet, int n){
    for (int i = 0; i < n; i++)
        vet[i] = n - i;
}

void ordenado(int *vet, int n){
    for (int i = 0; i < n; i++)
        vet[i] = i;
}

/*
 * av[1]: tamanho do vetor
 * av[2]: exibe dados
 * av[3]: alinhamento da memória - utilizar 64 bytes por padrão
 * av[4]: em ordem/em desordem
 * */
int main (int ac, char **av){
    
    int n = stoi(av[1]), 
        mAlign = stoi(av[3]),
        idx = 0,
        mOrder = stoi(av[4]),
        *vet = NULL;
    
    bool showdata = stoi(av[2]);
    posix_memalign(reinterpret_cast <void**>(&vet), mAlign, sizeof(int) * n);

    if (mOrder)
        ordenado(vet, n);
    else
        desordenado(vet, n);
    
    if (showdata){
        cout << "Dados: " << endl;
        for (idx = 0; idx < n; idx++) cout << vet[idx] << endl;    
    }
    

    quick_sort(0, n-1, vet);

    if (showdata){
        cout << "Dados ordenados: " << endl;
        for (idx = 0; idx < n; idx++) cout << vet[idx] << endl;
        }

    cout << "   Alinhamento: " << mAlign << endl;
    cout << "Bytes alocados: "<< sizeof(int) * n << endl;

    return EXIT_SUCCESS;
}
