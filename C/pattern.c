#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c, int d) {
    if (a <= b)
        if (a <= c)
            if (a <= d)
                return a;
    if (b <= a)
        if (b <= c)
            if (b <= d)
                return b;
    if (c <= b)
        if (c <= a)
            if (c <= d)
                return c;
    if (d <= b)
        if (d <= c)
            if (d <= a)
                return d;
    return 0;
}

int main() 
{
    int n;
    scanf("%d", &n);

    int x = 2*n-1;

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= x; j++) {
            
            int dist_to_top = i - 1;
            int dist_to_left = j - 1;
            int dist_to_bottom = x - i;
            int dist_to_right = x - j;
            
            int min_dist_to_edge = min(dist_to_top, dist_to_bottom, dist_to_left, dist_to_right);
            
            int value = abs(min_dist_to_edge - n);
            
            printf("%d ", value);
        }
        printf("\n");
    }

    return 0;
}

