#include <stdio.h>


#include "buffer.h"

int main(void) {
    Buffer buf;
    if (!init(&buf)) return 2;

    int num;
    while(scanf("%d", &num) > 0 && append(&buf, num)) {}        
    sort(&buf);
    while(pop(&buf, &num)) printf("%d\n", num);
}
