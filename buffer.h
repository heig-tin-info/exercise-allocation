#include <stdlib.h>

typedef struct Buffer {
    size_t buffer_size; // Double each time we reallocate
    size_t elements; // Number of elements in the buffer
    int *data;
} Buffer;

int init(Buffer *buf);
int append(Buffer *buf, int data);
int pop(Buffer *buf, int *data);
int sort(Buffer *buf);
