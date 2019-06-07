/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 4 june 2019
AIM    : hackerrank "sort array of strings" problem 
		 to write a sorting function which takes pointer to a comparison function
		 which determines the type of sorting. 
		 just like the inbuilt sorting function in algorithm header
		 -------- see the problem page in the folder ---------
STATUS : !!! success !!!
##############################################################################*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char *a, const char *b) { 
	return strcmp(a, b); 
}

int lexicographic_sort_reverse(const char *a, const char *b) {
  return strcmp(b, a);
}

int distinct_chars(const char *a) {     // better method to count the distinct characters in a string
  int dist = 0;

  while (*a != '\0') {
    if (!strchr(a + 1, *a))
      dist++;
    a++;
  }
  return dist;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b) {
  int res = distinct_chars(a) - distinct_chars(b);
  return (res) ? res : lexicographic_sort(a, b);
}

int sort_by_length(const char *a, const char *b) {
  int res = strlen(a) - strlen(b);
  return (res) ? res : lexicographic_sort(a, b);
}

/* simple bubble sort :) */
void string_sort(char **arr, const int len,
                 int (*cmp_func)(const char *a, const char *b)) {
  int half = len / 2;
  int sorted = 0;
  while (!sorted) {
    sorted = 1;
    for (int i = 0; i < len - 1; i++) {
      if (cmp_func(arr[i], arr[i + 1]) > 0) {
        char *tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
        sorted = 0;
      }
    }
  }
}



int main() 
{
    int n;					// number of strings
    scanf("%d", &n);
  
    char** arr;				// string array
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = (char*)malloc(1024 * sizeof(char));	// allocate memory for each string
        scanf("%s", *(arr + i));
        *(arr + i) = (char*)realloc(*(arr + i), strlen(*(arr + i)) + 1);// reallocate the strings space
    }
  	// printf("\n\n");
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)		// printing the string
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