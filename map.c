#include <stdio.h>
#include <stdlib.h>

void map(int(*f)(int x), int n, int i, int *array, int *newArray) {
    if(i < n) {
        newArray = realloc(newArray, (i+1)*sizeof(int));
        newArray[i] = f(*(array+i));
        i++;
        map(f, n, i, array, newArray);
    } else {
        for(i = 0; i < n; i++) 
            printf("%d ", *(newArray+i));
    }
}

int square(int x) {
   return x * x; 
}


int factorial(int x) {
    int num = 1;
    for(int i = x; i > 0; i--)
        num = num * i;
    return num;
}

int main() {
    int n, i, *array, *newArray;
    printf("Digite o tamanho do array: \n");
    scanf("%d", &n); 
    array = malloc(n*sizeof(int));

    for(i = 0; i < n; i++)
        scanf("%d", (array+i));

    printf("---------SQUARE-------------\n");
    map(square, n, 0, array, newArray); 

    printf("\n---------FACTORIAL----------\n");
    map(factorial, n, 0, array, newArray);

    free(array); 
    free(newArray);
    return 0;
}
