#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 100

int menu(char *options[], int size) {
    int choice;
    do {
        printf("\n=== MENU ===\n");
        for (int i = 0; i < size; i++) {
            printf("%s\n", options[i]);
        }
        printf("Scelta: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > size) {
            printf("\nScelta non valida. Riprova.\n");
            sleep(2);
        }
    } while (choice < 1 || choice > size);
    return choice;
}

void deleteCharacter(char *string, char character) {
    int len = strlen(string);
    int i, j;
    for (i = j = 0; i < len; i++) {
        if (string[i] != character) {
            string[j++] = string[i];
        }
    }
    string[j] = '\0';
}

void deleteCharacterAtPosition(char *string, int position) {
    int len = strlen(string);
    if (position >= 0 && position < len) {
        for (int i = position; i < len - 1; i++) {
            string[i] = string[i + 1];
        }
        string[len - 1] = '\0';
    }
}

void addCharacter(char *string, char character) {
    int len = strlen(string);
    if (len < MAX_LENGTH - 1) {
        string[len] = character;
        string[len + 1] = '\0';
    }
}

int main() {
    char string[MAX_LENGTH];
    char character;
    int position;
    int choice;
    char *menuOptions[] = {"[1] Elimina un carattere specifico", "[2] Elimina un carattere in base alla posizione", "[3] Aggiungi un carattere alla fine della stringa", "[4] Esci"};

    printf("Inserisci una stringa: ");
    scanf("%s", string);

    do {
        printf("La stringa di riferimento e': %s\n\n", string);
        choice = menu(menuOptions, sizeof(menuOptions) / sizeof(menuOptions[0]));

        switch (choice) {
            case 1:
                printf("Inserisci il carattere da eliminare: ");
                scanf(" %c", &character);
                deleteCharacter(string, character);
                printf("\nLa stringa modificata e': %s\n", string);
                break;
            case 2:
                printf("Inserisci la posizione del carattere da eliminare: ");
                scanf("%d", &position);
                deleteCharacterAtPosition(string, position);
                printf("\nLa stringa modificata e': %s\n", string);
                break;
            case 3:
                printf("Inserisci il carattere da aggiungere alla fine della stringa: ");
                scanf(" %c", &character);
                addCharacter(string, character);
                printf("\nLa stringa modificata e': %s\n", string);
                break;
            case 4:
                printf("Arrivederci!\n");
                break;
            default:
                printf("Scelta non valida.\n");
                break;
        }

        printf("\nPremi INVIO per continuare...");
        getchar(); 
        getchar(); // attende l'invio di un tasto
    } while (choice != 4);

    return 0;
}

