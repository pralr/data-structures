#include <stdio.h>
#include <stdlib.h>

int main(){
    int max, *ptr;
    printf("Escolha uma quantidade maxima para o array: \n");
    scanf("%d", &max); 

    ptr = malloc(max * sizeof(int)); 
    
    if(ptr!=NULL) {
        printf("Insira os elementos: \n"); 
        for(int i = 0; i < max; i++) 
            scanf("%d", ptr+i); 

    } else 
        printf("Memoria nao alocada.");

    for(int k = 0; k < max; k++) 
        printf("%d ",*(ptr+k));

    free(ptr);
    
return 0;
}
