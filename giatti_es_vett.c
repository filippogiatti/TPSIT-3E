//Filippo Giatti 3E
#include <stdio.h>

int main() {
    int n;
    printf("Quanti numeri vuoi inserire?\n");
    scanf("%d", &n);

    int v1[n], v2[n], vSomma[n];

    printf("\nRiempi il primo vettore:\n");
    for (int i = 0; i < n; i++) {
        printf("Inserisci il numero in posizione %d: ", (i + 1));
        scanf("%d", &v1[i]);
    }

    printf("\nRiempi il secondo vettore:\n");
    for (int i = 0; i < n; i++) {
        printf("Inserisci il numero in posizione %d: ", (i + 1));
        scanf("%d", &v2[i]);
    }

    printf("Il vettore somma è:\n");
    for (int i = 0; i < n; i++) {
        vSomma[i] = v1[i] + v2[i];
        printf("%d\n", vSomma[i]);
    }

    return 0;
}