#include <stdio.h>
void main()
{
     int Arr[5] = {4, 2, 1, 3, 5};
    int size = sizeof(Arr) / sizeof(Arr[0]);
        printf("Initial Array\n");
        print(Arr,size);
        recursive_merge(Arr, 0, size - 1);
        printf("\nAfter Merge sort\n");
        print(Arr,size);
}
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
divide_merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
//recursive function
void recursive_merge(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    recursive_merge(arr, l, m);
    recursive_merge(arr, m + 1, r);
    divide_merge(arr, l, m, r);
  }
}