#include <stdio.h>

int main() { //dichiarazione variabili
    int N, num;
    int sommaPositivi = 0, sommaNegativi = 0, conteggioPositivi = 0, conteggioNegativi = 0;
    float mediaPositivi = 0, mediaNegativi = 0;

    printf("Inserisci il numero di numeri da leggere: ");
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        printf("Inserisci il numero %d: ", i + 1);
        scanf("%d", &num);

        if (num >= 0) {
            sommaPositivi += num;
            ++conteggioPositivi;
        } else {
            sommaNegativi += -num; // Somma dei negativi in valore assoluto
            ++conteggioNegativi;
        }
    }

    if (conteggioPositivi != 0) {
        mediaPositivi = (float)sommaPositivi / conteggioPositivi;
    }

    if (conteggioNegativi != 0) {
        mediaNegativi = (float)sommaNegativi / conteggioNegativi;
    }
    //output
    printf("Somma dei numeri positivi: %d\n", sommaPositivi);
    printf("Somma dei numeri negativi in valore assoluto: %d\n", sommaNegativi);
    printf("Conteggio dei numeri positivi: %d\n", conteggioPositivi);
    printf("Conteggio dei numeri negativi: %d\n", conteggioNegativi);
    printf("Media dei numeri positivi: %.2f\n", mediaPositivi);
    printf("Media dei numeri negativi: %.2f\n", mediaNegativi);

    return 0;
}
