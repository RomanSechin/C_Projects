#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char * a, const char * b) {
  return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
  return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
  char ch;
  int sum1 = 0;
  int sum2 = 0;
  char set1[255];
  char set2[255];
  for(ch = *a; ch != ' ' && ch != '\n' && ch != '\0'; ch = *(a++))
  {
    set1[ch]++;
    if(set1[ch] == 0)
      set1[ch]++;
    else
      ++sum1;
  }
  for(ch = *b; ch != ' ' && ch != '\n' && ch != '\0'; ch = *(b++))
  {
    set2[ch]++;
    if(set2[ch] == 0)
      set2[ch]++;
    else
      ++sum2;
  }
  if(sum1 == sum2) return strcmp(a, b);
  return sum1 - sum2;
}

int sort_by_length(const char* a, const char* b) {
  int sum1 = strlen(a);
  int sum2 = strlen(b);
  if(sum1 == sum2) return strcmp(a, b);
  return strlen(a) - strlen(b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
  char * temp = (char *)malloc(1024 * sizeof(char));
  for(int i = 0; i < len - 1; ++i)
    for(int j = i + 1; j < len; ++j)
    {
      temp = realloc(temp, strlen(arr + i) * sizeof(char));
      if(cmp_func(*(arr + j), *(arr + i)) < 0)
      {
        memcpy(temp, (arr+i), strlen(arr + i));
        memcpy(arr + i, arr + j, strlen(arr + j));
        memcpy(arr + j, temp, strlen(temp));
      }
    }
    free(temp);
}


int main()
{
  int n;
  scanf("%d", &n);

  char** arr;
  arr = (char**)malloc(n * sizeof(char*));

  for(int i = 0; i < n; i++) {
    *(arr + i) = malloc(1024 * sizeof(char));
    scanf("%s", *(arr + i));
    *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
  }

  string_sort(arr, n, lexicographic_sort);
  printf("\n");
  for(int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, lexicographic_sort_reverse);
  for(int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, lexicographic_sort);
  string_sort(arr, n, sort_by_length);

  for(int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, lexicographic_sort_reverse);
  string_sort(arr, n, sort_by_number_of_distinct_characters);

  for(int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");
}
