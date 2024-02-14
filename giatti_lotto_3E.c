#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<unistd.h>

float calcoloVincita(int NumR, double Cost, double puntata, int Contatore) {
    double vincita;
    vincita = ((puntata * Cost) / NumR) * Contatore;
    return vincita;
}

int getFactorial(int Fact) {
    int result = 1;
    for (int i = 1; i <= Fact; i++) {
        result *= i;
    }
    return result;
}

int numRand(int min, int max) {
    return min + rand() % (max - min + 1);
}

int menu(char opzioni[], int dimensioneM) {
    int scelta;
    do {
        printf("\n%s\n", opzioni);
        scanf("\n%d", &scelta);
        if ((scelta < 1) || (scelta > dimensioneM)) {
            printf("\nOpzione sbagliata\n");
            usleep(2000000);
            system("clear");
        }
    } while ((scelta < 1) || (scelta > dimensioneM));
    return scelta;
}

int main() {
    char sceltaM;
    int dim;
    float puntata1 = 0, puntata2 = 0, puntata3 = 0, puntata4 = 0, puntata5 = 0, puntata6 = 0;
    int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0;
    float Vp1, Vp2, Vp3, Vp4, Vp5, Vp6;
    int sceltapuntata, dimU = 0;
    float costS = 11.23, costA = 5.62, costT = 3.74, costQ = 2.81, costC = 2.25, costAMB = 8.43; // Costo Ambata

    // Aggiunta dell'opzione Ambata
    printf("=== Gioco Lotto === \nSu quante ruote vuoi giocare?\n");
    char opzioni[] = "[1] Una ruota\n[2] Dieci ruote";
    int dimensioneM = sizeof(opzioni) / sizeof(opzioni[0]);
    sceltaM = menu(opzioni, dimensioneM);
    switch (sceltaM) {
        case 1: {
            dim = 1;
            break;
        }
        case 2: {
            dim = 10;
            break;
        }
    }

    int ruotaN[dim * 10]; // Aumentiamo la dimensione per contenere più numeri
    srand(time(NULL));

    printf("Numeri generati casualmente:\n");
    for (int i = 0; i < dim * 10; i++) {
        int k, controllo;
        do {
            controllo = 0;
            k = numRand(1, 90);
            for (int j = 0; j < dim * 10; j++) {
                if (ruotaN[j] == k) {
                    controllo++;
                }
            }
        } while (controllo == 1);
        ruotaN[i] = k;
    }

    printf("\nQuanti numeri vuoi inserire? (da 1 a 5): ");
    do {
        scanf("%d", &dimU);
    } while (dimU < 1 || dimU > 5);

    int NumUtente[dimU];
    printf("Inserisci i numeri su cui vuoi puntare:\n");
    for (int i = 0; i < dimU; i++) {
        do {
            int k, controllo;
            do {
                controllo = 0;
                scanf("%d", &k);
                for (int j = 0; j < dimU; j++) {
                    if (NumUtente[j] == k) {
                        printf("Hai già inserito questo numero!\n");
                        controllo++;
                    }
                }
            } while (controllo == 1);
            NumUtente[i] = k;
            if (NumUtente[i] < 1 || NumUtente[i] > 90) {
                printf("Hai inserito un valore errato!\n");
            }
        } while (NumUtente[i] < 1 || NumUtente[i] > 90);
    }

    bool s1 = false, s2 = false, s3 = false, s4 = false, s5 = false, s6 = false;
    do {
        printf("\nScegli su cosa puntare:\n");
        if (dimU >= 1) {
            printf("[1] Singolo\n");
            if (dimU >= 2) {
                printf("[2] Ambo\n");
                if (dimU >= 3) {
                    printf("[3] Terna\n");
                    if (dimU >= 4) {
                        printf("[4] Quaterna\n");
                        if (dimU >= 5) {
                            printf("[5] Cinquina\n");
                        }
                    }
                }
            }
        }
        printf("[0] Esci\n");
        scanf("%d", &sceltapuntata);

        switch (sceltapuntata) {
            case 1: {
                if (s1 == false) {
                    printf("Hai scelto di puntare su singolo!\n");
                    s1 = true;
                    do {
                        printf("Quanto vuoi puntare? (min 0.50, max 200): ");
                        puntata1 = 0;
                        scanf("%f", &puntata1);
                    } while (puntata1 < 0.50 || puntata1 > 200);
                } else if (s1 == true) {
                    printf("Hai già scelto singolo!\n");
                }
                break;
            }
            case 2: {
                if (s2 == false) {
                    printf("Hai scelto di puntare su ambo!\n");
                    s2 = true;
                    do {
                        printf("Quanto vuoi puntare? (min 0.50, max 200): ");
                        puntata2 = 0
                        ;
                        scanf("%f", &puntata2);
                    } while (puntata2 < 0.50 || puntata2 > 200);
                } else if (s2 == true) {
                    printf("Hai già scelto ambo!\n");
                }
                break;
            }
            case 3: {
                if (dimU >= 3) {
                    if (s3 == false) {
                        printf("Hai scelto di puntare su terna!\n");
                        s3 = true;
                        do {
                            printf("Quanto vuoi puntare? (min 0.50, max 200): ");
                            puntata3 = 0;
                            scanf("%f", &puntata3);
                        } while (puntata3 < 0.50 || puntata3 > 200);
                    } else if (s3 == true) {
                        printf("Hai già scelto terna!\n");
                    }
                } else {
                    printf("Devi scegliere almeno 3 numeri per puntare sulla terna!\n");
                }
                break;
            }
            case 4: {
                if (dimU >= 4) {
                    if (s4 == false) {
                        printf("Hai scelto di puntare su quaterna!\n");
                        s4 = true;
                        do {
                            printf("Quanto vuoi puntare? (min 0.50, max 200): ");
                            puntata4 = 0;
                            scanf("%f", &puntata4);
                        } while (puntata4 < 0.50 || puntata4 > 200);
                    } else if (s4 == true) {
                        printf("Hai già scelto quaterna!\n");
                    }
                } else {
                    printf("Devi scegliere almeno 4 numeri per puntare sulla quaterna!\n");
                }
                break;
            }
            case 5: {
                if (dimU >= 5) {
                    if (s5 == false) {
                        printf("Hai scelto di puntare su cinquina!\n");
                        s5 = true;
                        do {
                            printf("Quanto vuoi puntare? (min 0.50, max 200): ");
                            puntata5 = 0;
                            scanf("%f", &puntata5);
                        } while (puntata5 < 0.50 || puntata5 > 200);
                    } else if (s5 == true) {
                        printf("Hai già scelto cinquina!\n");
                    }
                } else {
                    printf("Devi scegliere almeno 5 numeri per puntare sulla cinquina!\n");
                }
                break;
            }
        }

        // Calcolo delle combinazioni vincenti
        int contatoreVittorie = 0;
        for (int i = 0; i < dimU; i++) {
            for (int j = 0; j < dim * 10; j++) {
                if (NumUtente[i] == ruotaN[j]) {
                    contatoreVittorie++;
                }
            }
        }

        // Calcolo delle vincite
        Vp1 = calcoloVincita(dim, costS, puntata1, contatoreVittorie) - puntata1;
        Vp2 = calcoloVincita(dim, costA, puntata2, contatoreVittorie) - puntata2;
        Vp3 = calcoloVincita(dim, costT, puntata3, contatoreVittorie) - puntata3;
        Vp4 = calcoloVincita(dim, costQ, puntata4, contatoreVittorie) - puntata4;
        Vp5 = calcoloVincita(dim, costC, puntata5, contatoreVittorie) - puntata5;
        Vp6 = calcoloVincita(dim, costAMB, puntata6, contatoreVittorie) - puntata6;

        float vincitacomp = Vp1 + Vp2 + Vp3 + Vp4 + Vp5 + Vp6;
        printf("La tua vincita è: %.2f\n", vincitacomp);
    } while (sceltapuntata != 0);

    return 0;
}



