#include <stdio.h>
#include <time.h>
 
int find_pivot(int arr[],int start,int end)
{
    
    int pivot=start;
    int l=start+1;
    int r=end;
    int temp;
    while(l<=r)
    {
        if(arr[l]>=arr[pivot] && arr[r]<=arr[pivot])
        {
            temp=arr[l];
            arr[l++]=arr[r];
            arr[r--]=temp;
        }
        else if(arr[l]>arr[pivot])
            r--;
        else l++;
    }
    temp=arr[pivot];
    arr[pivot]=arr[r];
    arr[r]=temp;
    
    return r;
    
}

void quick_sort(int arr[],int start,int end)
{
    
    if(start<end)
    {
        int pivot=find_pivot(arr,start,end);
        quick_sort(arr,start,pivot-1);
        quick_sort(arr,pivot+1,end);
        
    }
}



void main()
{
    clock_t start,end;
    int arr[1000000],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    start=clock();
    quick_sort(arr,0,n-1);
    end=clock();
    
    printf("Total time taken is %lf\n",((double)(end-start))/CLOCKS_PER_SEC);

for(int i=0;i<n;i++)
    {
        printf("%d    ",arr[i]);
    }
    
        
    
}
