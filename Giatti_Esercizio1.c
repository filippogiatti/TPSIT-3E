/*Leggi N numeri (interi),
con N scelto dall'utente
e non superiore ai 30 elementi,
calcolare la somma e la media dei numeri pari,
e dei numeri dispari (utilizza %).*/

#include <stdio.h>
void main() {
	int N, num[30], pari=0, dispari=0, i;
	int sommaPari=0, sommaDispari=0;
	float mediaP, mediaD;

	do {
		printf("Quanti numeri interi vuoi inserire?\n");
		scanf("%d", &N);
	} while (N<=0 || N>30);

	for (i=0; i<N; i++) { 
		printf("Inserisci un numero\n");
		scanf("%d", &num[i]);

		if(num[i]%2==0) {
			pari++;
			sommaPari=sommaPari+num[i];
		}

		else {
			dispari++;
			sommaDispari=sommaDispari+num[i];
		}

	} 

	mediaP=sommaPari/pari;
	mediaD=sommaDispari/dispari;

	// output
	printf("Sono stati inseriti %d numeri pari e %d numeri dispari\n", pari, dispari);
	printf("La somma dei numeri pari e': %d\n", sommaPari);
	printf("La media dei numeri pari e': %.2f\n", mediaP);
	printf("\n");
	printf("La somma dei numeri dispari e': %d\n", sommaDispari);
	printf("La media dei numeri dispari e': %.2f\n", mediaD);
}
