#include <stdio.h>
#include <malloc.h>
#include <conio.h>

void foo(size_t n) {
    int *arr = NULL;
    size_t i;
arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("error allocating memory on heap");
        _getch();
    return 0;
        exit(1);
    }

    for (i = 0; i < n; i++) {
        arr[i] = rand();
        printf("%d\n", arr[i]);
    }
//    for (i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");

    free(arr);
}

int main() {
    foo(1000000);
    _getch();
    return 0;
}
