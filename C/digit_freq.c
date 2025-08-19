#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char freq[10] = {0};
    char *s = malloc(1024 * sizeof(char));
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            freq[s[i] - '0']++;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }

    free(s);

    return 0;
}

