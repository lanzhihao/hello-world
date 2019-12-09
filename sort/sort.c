#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort(int arr[], int len)
{
  int i, j;
  for(i = 0; i < len - 1; i++)
  {
    int min = i;
    for(j = i + 1; j < len; j++)
      if(arr[j] < arr[min])
        min = j;
      swap(&arr[min], &arr[i]);
  }
}

void bubble_sort(int arr[], int len)
{
  int i, j, temp;
  for(i = 0; i < len -1; i++)
    for(j = 0; j < len -1 - i; j++)
      if(arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
}


int main()
{
  int arr[] = {22, 34, 3, 32, 82, 55};
  int len = (int)sizeof(arr) /sizeof(*arr);
  printf("len: %d, size arr: %ld, arr add: %p, &arr add: %p\n", len, sizeof(&arr), arr, &arr);
  bubble_sort(arr, len);
  int i;
  for(i = 0; i < len; i++)
    printf("%d ", arr[i]);
  char *test = malloc(10);
  if(test)
    printf("\nsize test: %ld\n", sizeof(test));
  return 0;
}
