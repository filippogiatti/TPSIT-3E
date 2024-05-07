#include <stdio.h>

// Funzione per calcolare la media di un vettore
float calcolaMedia(int *vettore, int N) {
    int somma = 0;
    for (int i = 0; i < N; i++) {
        somma += *(vettore + i); // Accesso agli elementi del vettore tramite puntatori
    }
    return (float)somma / N; // Calcolo della media
}

// Funzione per trovare il massimo valore in un vettore
int trovaMassimo(int *vettore, int N) {
    int massimo = *vettore; // Assume il primo elemento come massimo
    for (int i = 1; i < N; i++) {
        if (*(vettore + i) > massimo) { // Accesso agli elementi del vettore tramite puntatori
            massimo = *(vettore + i);
        }
    }
    return massimo;
}

// Funzione per trovare il minimo valore in un vettore
int trovaMinimo(int *vettore, int N) {
    int minimo = *vettore; // Assume il primo elemento come minimo
    for (int i = 1; i < N; i++) {
        if (*(vettore + i) < minimo) { // Accesso agli elementi del vettore tramite puntatori
            minimo = *(vettore + i);
        }
    }
    return minimo;
}

int main() {
    int N;

    printf("Inserisci il numero di elementi nel vettore: ");
    scanf("%d", &N);

    int vettore[N];

    printf("Inserisci gli elementi del vettore:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &vettore[i]);
    }

    // Calcola la media
    float media = calcolaMedia(vettore, N);
    printf("La media del vettore è: %.2f\n", media);

    // Trova il massimo
    int massimo = trovaMassimo(vettore, N);
    printf("Il massimo valore nel vettore è: %d\n", massimo);

    // Trova il minimo
    int minimo = trovaMinimo(vettore, N);
    printf("Il minimo valore nel vettore è: %d\n", minimo);

    return 0;
}

