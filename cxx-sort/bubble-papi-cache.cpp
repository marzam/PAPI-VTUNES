#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <climits>
#include <cstring>
#include <string>
#include <cstdint>
#include <System.hpp>
using namespace std;

// A function to implement bubble sort
void bubble_Sort(int64_t *vet, int64_t n){
        
    for (int64_t i = 0; i < n-1; i++)    
        for (int64_t j = 0; j < n-i-1; j++)
            if (vet[j] > vet[j+1]){
                int64_t swap = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = swap;
            }
                
}


void desordenado(int64_t *vet, int64_t n){
    for (int64_t i = 0; i < n; i++)
        vet[i] = n - i - 1;
}

void ordenado(int64_t *vet, int64_t n){
    for (int64_t i = 0; i < n; i++)
        vet[i] = i;
}

/*
 * av[1]: tamanho do vetor
 * av[2]: exibe dados
 * av[3]: alinhamento da memória - utilizar 64 bytes por padrão
 * av[4]: em ordem/em desordem
 * */
int main (int ac, char **av){
    
    int64_t n = stoi(av[1]), 
            mAlign = stoi(av[3]),
            idx = 0,
            mOrder = stoi(av[4]),
             *vet = NULL;
    
    bool showdata = stoi(av[2]);
    Events      events;
    
    posix_memalign(reinterpret_cast <void**>(&vet), mAlign, sizeof(int64_t) * n);

    if (mOrder)
        ordenado(vet, n);
    else
        desordenado(vet, n);
    
    if (showdata){
        cout << "Dados: " << endl;
        for (idx = 0; idx < n; idx++) cout << vet[idx] << endl;    
    }
    
    events.setNumberOfEvents(1);
    events.addEvents(PAPI_L3_TCM);
    
    
    events.start();
    bubble_Sort(vet, n);
    events.stop();
    cout << "\t PAPI_L3_TCM: " << fixed << setw(25) << events.getEventbyIndex(0)  << "" << endl;
    
    
    

    if (showdata){
        cout << "Dados ordenados: " << endl;
        for (idx = 0; idx < n; idx++) cout << vet[idx] << endl;
    }

    cout << "   Alinhamento: " << mAlign << endl;
    cout << "Bytes alocados: "<< sizeof(int64_t) * n << endl;

    return EXIT_SUCCESS;
}
