//Filippo Giatti
#include <stdio.h>

int main() {
    int N;
    int k = 0, t = 0;
    int vOrigin[10];

    // Input della dimensione del vettore
    do {
        printf("Inserisci la dimensione del vettore minore di 10: ");
        scanf("%d", &N);
    } while (N <= 0 || N > 10);
    
    // Riempimento del vettore
    for (int i = 0; i < N; i++) {
        printf("Inserisci il numero in posizione %d: ", i+1);
        scanf("%d", &vOrigin[i]);
    }

    // Riorganizzazione dei numeri pari e dispari nei rispettivi vettori
    int vPari[N], vDispari[N];
    for (int i = 0; i < N; i++) {
        if (vOrigin[i] % 2 == 0) {
            vPari[k] = vOrigin[i];
            k++;
        } else {
            vDispari[t] = vOrigin[i];
            t++;
        }
    }

    // Stampa del vettore pari
    if (k > 0) {
        printf("Vettore pari:\n");
        for (int i = 0; i < k; i++) {
            printf("%d \n", vPari[i]);
        }
    }
    
    // Stampa del vettore dispari
    if (t > 0) {
        printf("Vettore dispari:\n");
        for (int i = 0; i < t; i++) {
            printf("%d \n", vDispari[i]);
        }
    }
    
    return 0;
}