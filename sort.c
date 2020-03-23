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

int main(void) {
    int buffer_size = 1;
    int *array = malloc(sizeof(int) * buffer_size);
    if (array == NULL) return 2;

    // Read values from stdin
    int size = 0;
    while(scanf("%d", &array[size]) > 0) {
        if (size > buffer_size) {
            array = realloc(array, buffer_size = size * 2);
            if (array == NULL) return 2;
        }
        size++;
    }

    // Sort values
    qsort(array, size, sizeof(int), compare);

    // Display
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }    

    free(array);
}
