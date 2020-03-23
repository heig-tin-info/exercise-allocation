#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
     int int_a = *((int*)a), int_b = *((int*)b);

     if (int_a == int_b)
        return 0;
     else if (int_a < int_b)
        return -1;
     else
        return 1;
}

int main(int argc, char *argv[]) {
    int array[10]; 

    if (argc < 2) return 1;
    int elements = atoi(argv[1]); 

    if (elements >= sizeof(array)/sizeof(array[0])) return 2;

    for (int i = 0; i < elements; i++) {
        scanf("%d", &array[i]);
    }

    qsort(array, sizeof(array)/sizeof(int), sizeof(int), compare);

    for (int i = 0; i < elements; i++) {
        printf("%d\n", array[i]);
    }    
}
