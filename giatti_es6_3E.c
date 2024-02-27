//Filippo Giatti 3E
#include <stdio.h>

int main() {
    int numStudenti;
    float media = 0, somma = 0;
    int contSufficenti = 0;
    int contInsufficenti = 0;
    int contMigliori = 0;
    float votoMin, votoMax;
    float numMin, numMax;
    char Studenti[20][50]; 
    int scelta;
    
    do {
        printf("Inserisci il numero degli studenti: ");
        scanf("%d", &numStudenti);
        float voti[numStudenti];
        
        for (int i = 0; i < numStudenti; i++) {
            printf("Inserisci il cognome dello studente: ");
            scanf("%s", Studenti[i]); 

            printf("Inserisci il voto dello studente: ");
            scanf("%f", &voti[i]);
        }
        
        // Calcola somma dei voti
        for (int i = 0; i < numStudenti; i++) {
            somma = somma + voti[i];
        }
        
        // Calcola la media
        media = somma / numStudenti;
        
        // Conta il numero di studenti insufficienti, sufficienti e migliori
        for (int i = 0; i < numStudenti; i++) {
            if (voti[i] < 6) {
                contInsufficenti++;
            } else {
                contSufficenti++;
                if (voti[i] >= 7.50 && voti[i] < 10) {
                    contMigliori++;
                }
            }
        }
        
        // Trova il voto minimo e massimo
        numMin = voti[0];
        numMax = voti[0];
        for (int i = 1; i < numStudenti; i++) {
            if (voti[i] > numMax) {
                numMax = voti[i];
            }
            if (voti[i] < numMin) {
                numMin = voti[i];
            }
        }

        printf("Media della classe: %.2f\n", media);
        printf("Insufficenti: %d, Sufficienti: %d, Studenti con più di 7.5: %d\n", contInsufficenti, contSufficenti, contMigliori);
        printf("Voto piu basso: %.2f, Voto piu alto: %.2f\n", numMin, numMax);

        printf("Vuoi fare partire il programma di nuovo?\n [1] si\n [0] no\n");
        scanf("%d", &scelta);

    } while (scelta == 1);

    return 0;
}

