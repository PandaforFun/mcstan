#include <stdio.h>
//dividing the set
int division(int arr[], int small,int large) {
  int pivot = arr[large];
  int i = (small - 1);
  for (int j = small; j < large; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[large]);
  return (i + 1);
}
//merging the set
void quick(int arr[], int small, int large) {
  if (small < large) {
    int pi = division(arr, small, large);
    quick(arr, small, pi - 1);
    quick(arr, pi + 1, large);
  }
}
//displaying the array
void print(int arr[], int length)
{
    printf("{ ");
    for (int i = 0; i < length; ++i)
    {
        if (i == length - 1)
            printf("%d ", arr[i]);
        else
            printf("%d , ", arr[i]);
    }
    printf("}");
}
//function to swap the comparable elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
//main function
int main() {
  int Arr[] = {4,2,1,3,5};
  
  int n = sizeof(Arr) / sizeof(Arr[0]);
  printf("Initial Array\n");
  print(Arr, n);
  quick(Arr, 0, n - 1);
  
  printf("\nAfter Quick sort \n");
  print(Arr, n);
}