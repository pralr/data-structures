#include <stdio.h>
#include <stdlib.h>

int main() {

    int max, newMax, *ptr; 

    printf("Escolha o numero maximo para o array: \n");
    scanf("%d", &max); 

    ptr = malloc(max*(sizeof(int))); 

    if(ptr!=NULL) {
    
        printf("Insira os valores: \n");
        for(int i = 0; i<max; i++) 
            scanf("%d", ptr+i); 
        
        for(int k = 0; k<max; k++) 
            printf("%d ", *(ptr+k)); // acessando o conteúdo do ponteiro *
        printf("foram adicionados.\n");

        // agora vamos realocar memória
        // lembre que os parametros são nosso ponteiro e o novo tam

        printf("Insira um novo valor para o maximo: \n"); 
        scanf("%d", &newMax); 
        ptr = realloc(ptr, newMax*sizeof(int)); 

        // ao invés de j = 0 para inserir, você coloca j = max, pois você vai inserir depois dos valores já existentes
        printf("Insira %d elementos: \n", newMax-max);
        for(int j = max; j<newMax; j++) {
            scanf("%d", ptr+j);
        }

        printf("novo Array: "); 
        for(int m = 0; m<newMax; m++) {
            printf("%d ", *(ptr+m)); 
        }        

    } else {
        printf("Memoria nao alocada.\n");
    }

    free(ptr);
    return 0;
}
