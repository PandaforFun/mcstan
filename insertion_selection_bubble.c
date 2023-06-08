#include <stdio.h>
// bubble sorting
void bubble(int arr[], int length)
{
    int count2=1;
    printf("****BUBBLE SORT****\nThe original Array is : \n");
    print(arr, length);
    printf("\n");
    for (int count = 0; count < length-1 ; ++count)
    {
        for (int i = 0; i < length - count - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                printf("Iteration %d :--> ", count2);
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                print(arr, length);
                printf("\n");
                count2++;
            }
        }
    }
}

//selection sort
void selection(int arr[], int length)
{
    printf("****SELECTION SORT****\nThe original Array is : \n");
    print(arr, length);
    printf("\n");
    int i,j,temp;
    for(i=0;i<length;i++)
    {
      printf ("Iteration %d :--> ", i+1);
      for(j=i+1;j<length;j++)
        {
           if(arr[i]>arr[j])
               {
                 temp=arr[i];
                 arr[i]=arr[j];
                 arr[j]=temp;
               }
         }
     print(arr,length);
     printf("\n");
    }
}

//insertion sort
void insertion(int arr[], int length) 
{
    printf("****INSERTION SORT****\nThe original Array is : \n");
    print(arr, length);
    printf("\n");
  for (int i = 1; i < length; i++) {
    int key = arr[i];
    int j = i - 1;
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
    printf ("Iteration %d :--> ", i);
     print(arr,length);
    printf("\n");
  }
}

// print function
void print(int arr[], int length)
{
    printf("{ ");
    for (int i = 0; i < length; ++i)
    {
        if(i==length-1)printf("%d ", arr[i]);
        else printf("%d , ", arr[i]);
    }
    printf("}");
}

void main()
{
    int Arr[5] = {4, 2, 1, 3, 5};
    int size = 5,sort;
    printf("Which sorting do you wish to perform : \n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n:--> ");
    scanf("%d",&sort);
    switch(sort)
    {
        case 1:
        {
            printf("\n");
            bubble(Arr, size);
            break;
        }
        case 2:
        {
            printf("\n");
            selection(Arr, size);
            break;
        }
        case 3:
        {
            printf("\n");
            insertion(Arr, size);
            break;
        }
    }
}