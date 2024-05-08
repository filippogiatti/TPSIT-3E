/*Dopo un vettore di N elementi scrivere un programma che ordini il vettore in ordine crescente. 
Utilizzare 2 Metodi di ordinamento: Bubble Sort e Selection sort .*/
#include <stdio.h>
int main() {
    int N;

    printf("Inserisci il numero di elementi nel vettore: ");
    scanf("%d", &N);

    int vettore[N];

    printf("Inserisci gli elementi del vettore:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &vettore[i]);
    }
    int scelta;
    printf("\nCome vuoi riordinare l'array?\n [1]Bubble sort\n [2]Selection sort\n");
    scanf("%d", &scelta);
    if(scelta==1){
        int temp;
    
        for(int i=0; i<N-1; i++){
		    for(int j=0; j<N-i-1; j++){
			    if(vettore[j]>vettore[j+1]){
				    temp = vettore[j];
				    vettore[j] = vettore[j+1];
				    vettore[j+1] = temp;
			    }
		    }
	    }
        printf("Array ordinato:");
	    for(int i=0; i<N; i++){
		    printf("%d ", vettore[i]);
	    }
    }else{
        
    int indice_min, temp;
 
    for(int i=0; i<N-1; i++){
        indice_min=i;
        for(int j=i+1; j<N; j++){
            if(vettore[j] < vettore[indice_min])
                indice_min = j;
        }
        temp = vettore[indice_min];
        vettore[indice_min] = vettore[i];
        vettore[i] = temp;  
    }
    
    printf("Array ordinato:");
    for(int i=0; i<N; i++){
        printf("%d ", vettore[i]);        
    }    
    }

    
    return 0;
}
