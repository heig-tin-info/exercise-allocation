#include <stdio.h>
#include <stdlib.h>

typedef struct Buffer {
    size_t buffer_size; // Double each time we reallocate
    size_t elements; // Number of elements in the buffer
    int *data;
} Buffer;

int *init(Buffer *buf) {
    buf->buffer_size = 1;
    buf->elements = 0;
    buf->data = malloc(buf->buffer_size * sizeof(int));
    return buf->data;
}

int append(Buffer *buf, int data) {
    if (buf->data == NULL) return 1;
    buf->data[buf->elements++] = data;
    if (buf->elements > buf->buffer_size) {
        buf->data = realloc(buf->data, buf->buffer_size <<= 1);
        if (buf->data == NULL) {
            return 0;
        }
    }
    return 1;
}

int pop(Buffer *buf, int *data) {
    if (buf->elements == 0) {
        return 0;
    }
    if (buf->elements < buf->buffer_size / 2) {
        buf->data = realloc(buf->data, buf->buffer_size >>= 1);
        if (buf->data == NULL) {
            return 0;
        }        
    }
    *data = buf->data[--buf->elements];
    return 1; 
}

int compare(const void* a, const void* b)
{
     int int_a = *((int*)a), int_b = *((int*)b);

     if (int_a == int_b)
        return 0;
     else if (int_a < int_b)
        return 1;
     else
        return -1;
}

void sort(Buffer *buf) {
    qsort(buf->data, buf->elements, sizeof(int), compare);
}

int main(void) {
    Buffer buf;
    if (!init(&buf)) return 2;

    int num;
    while(scanf("%d", &num) > 0 && append(&buf, num)) {}        
    sort(&buf);
    while(pop(&buf, &num)) printf("%d\n", num);
}
