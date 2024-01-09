#include <stdio.h>

int main() {
    int max_azione = 100;
    int max_lun = 50;

    char azioni[max_azione][max_lun];
    float prezzi[max_azione];

    float somma = 0, somma_range = 0;
    float prezzo_max = 0, prezzo_min = 0;
    int count = 0, count_range = 0;
    int i;

    while (1) {
        printf("Inserisci la denominazione dell'azione (terminato per uscire): ");
        scanf("%s", azioni[count]);

        if (azioni[count][0] == 't' && azioni[count][1] == 'e' && azioni[count][2] == 'r' && azioni[count][3] == 'm' && azioni[count][4] == 'i' && azioni[count][5] == 'n' && azioni[count][6] == 'a' && azioni[count][7] == 't' && azioni[count][8] == 'o' && azioni[count][9] == '\0') {
            break;
        }

        printf("Inserisci il prezzo dell'azione: ");
        scanf("%f", &prezzi[count]);

        while (prezzi[count] <= 0) {
            printf("Il prezzo deve essere maggiore di zero. Reinserisci il prezzo: ");
            scanf("%f", &prezzi[count]);
        }

        somma += prezzi[count];
        count++;

        if (prezzi[count - 1] > prezzo_max || count == 1) {
            prezzo_max = prezzi[count - 1];
            for (i = 0; azioni[count - 1][i] != '\0'; i++) {
                azioni[count][i] = azioni[count - 1][i];
            }
            azioni[count][i] = '\0';
        }

        if (prezzi[count - 1] < prezzo_min || count == 1) {
            prezzo_min = prezzi[count - 1];
            for (i = 0; azioni[count - 1][i] != '\0'; i++) {
                azioni[count][i] = azioni[count - 1][i];
            }
            azioni[count][i] = '\0';
        }

        if (prezzi[count - 1] >= 2.50 && prezzi[count - 1] <= 3.50) {
            somma_range += prezzi[count - 1];
            count_range++;
        }
    }

    if (count > 0) {
        printf("\n1) Somma dei prezzi delle azioni: %.2f\n", somma);
        printf("2) Media dei prezzi delle azioni: %.2f\n", somma / count);
        printf("3) Azione con il prezzo massimo: %s (%.2f)\n", azioni[count - 1], prezzo_max);
        printf("4) Azione con il prezzo minimo: %s (%.2f)\n", azioni[count - 1], prezzo_min);

        if (count_range > 0) {
            printf("5) Media dei prezzi delle azioni tra 2.50 e 3.50 euro: %.2f\n", somma_range / count_range);
        } else {
            printf("5) Nessuna azione rientra nell'intervallo 2.50 - 3.50 euro.\n");
        }
    } else {
        printf("Nessuna azione inserita.\n");
    }

    return 0;
}



