#include <stdio.h>
int main()
{
    int i, j, n, num = 0;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int arr[n];
    for (i=0;i<n; i++)
    {
        printf("enter number %d : ",i+1);
        scanf("%d", &arr[i]);
    }
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (arr[i]>arr[j])
            {
                num+=1;
            }
        }
    }
    printf("Number of inversion : %d\n", num);
}

