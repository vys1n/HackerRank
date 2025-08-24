#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    int max_len = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    for (int i = 0; i < max_len; i++) {
        if (a[i] < b[i])
            return -1;
        else if (a[i] > b[i])
            return 1;
    }
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int max_len = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    for (int i = 0; i < max_len; i++) {
        if (a[i] > b[i])
            return -1;
        else if (a[i] < b[i])
            return 1;
    }
    return 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int distinct_char_a = 0;
    int distinct_char_b = 0;
   
    int* array_a = (int*)malloc(26*sizeof(int));
    int* array_b = (int*)malloc(26*sizeof(int));
    
    for (int i = 0; i< strlen(a); i++) {
        array_a[(int)a[i] - 97]++;
    }
    for (int i=0; i<26;i++){
        if(array_a[i] > 0){
            distinct_char_a++;
        }
    }

    for (int i = 0; i< strlen(b); i++) {
        array_b[(int)b[i] - 97]++;
    }
    for (int i=0; i<26;i++){
        if(array_b[i] > 0){
            distinct_char_b++;
        }
    }
    
    if (distinct_char_a < distinct_char_b)
        return -1;
    else if (distinct_char_a > distinct_char_b)
        return 1;
    else if (distinct_char_a == distinct_char_b)
        return lexicographic_sort(a, b);

    return 0;
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) < strlen(b))
        return -1;
    else if (strlen(a) > strlen(b))
        return 1;
    else if (strlen(a) == strlen(b))
        return lexicographic_sort(a,b);

    return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for (int i = 0; i < len - 1; i++) {
        int swapped  = 0;
        for (int j = 0; j < len - i - 1; j++) {
            if (cmp_func(arr[j], arr[j+1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}



int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
