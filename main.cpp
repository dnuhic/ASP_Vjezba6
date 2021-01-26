#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

void generisiZaBubble(std::string filename, int vel) {
    std::ofstream izlaz(filename);
    srand (time(NULL));
    for(int i = 0; i < vel; i++) {
        if(i % 8)
            izlaz << rand() % 10000 << " ";
        else
            izlaz << i << " ";
        if(i % 20 == 0 && i != 0) izlaz << "\n";
    }
    izlaz.close();
}

template <typename Tip>
void modificraniBubble(Tip* niz, int vel) {
    int p = vel;
    while(p != 0) {
        int i = p - 1;
        p = 0;
        for(int j = 1; j <= i; j++) {
            if(niz[j-1] > niz[j]) {
                std::swap(niz[j], niz[j - 1]);
                p = j;
            }
        }
    }
}

template <typename Tip>
void insertionSort(Tip* niz, int vel) {
    for(int i = 1; i < vel; ++i) {
        Tip priv = niz[i];
        int j = i - 1;
        while(j >= 0 && niz[j] > priv) {
            niz[j + 1] = niz[j];
            j--;
        }
        niz[j + 1] = priv;
    }
}

template <typename Tip>
void shellSort(Tip* niz, int vel, int* h, int hVel) {
    for(int i = 0; i < hVel; i++) {
        int temp = h[i];
        for(int j = temp; j < vel; j++) {
            Tip priv = niz[j];
            int k = j - temp;
            while(k >= 0 && niz[k] > priv) {
                niz[k + temp] = niz[k];
                k -= temp;
            }
            niz[k + temp] = priv;
        }
    }
}

void countingSort(int* a, int vel, int* bNiz, int k) {
    int C[k];
    for(int i = 0; i < k; ++i) {
        C[i] = 0;
    }
    for(int i = 0; i < vel; i++) {
        C[a[i]]++;
    }
    for(int i = 1; i < k; i++) {
        C[i] += C[i-1];
    }
    for(int i = vel - 1; i >=  0; i--) {
        C[a[i]] -= 1;
        bNiz[C[a[i]]] = a[i];
    }
}

int main() {
    int niz[20];
//    int b[20];
    srand(time(NULL));
    for(int i = 0; i < 20; ++i) {
        niz[i] = rand() % 100;
    }
    std::cout << std::endl;
    for(int i = 0; i < 20; ++i) {
        std::cout << niz[i] << " ";
    }
    std::cout << std::endl;
//    //int h[] = {8, 4, 2, 1};
//    countingSort(niz, 20, b, 100);
    modificraniBubble(niz, 20);
    for(int i = 0; i < 20; ++i) {
        std::cout << niz[i] << " ";
    }
    return 0;
}
