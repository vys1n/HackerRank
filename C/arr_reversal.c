#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    /* Write the logic to reverse the array. */
    int *a = (int*) malloc(num * sizeof(int));
    for (i = 0; i < num; i++) {
        a[i] = arr[num - i - 1];
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(a + i));
    printf("\n");
    return 0;
}

