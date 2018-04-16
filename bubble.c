#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
void main()
{
clock_t start,end;
double totaltime;
int i,r;
  int array[100], n, c, d, swap;
 
  
 
  printf("Enter number of elements\n");
   scanf("%d", &n);
for(i=0;i<=n;i++)
{
r=rand();
array[i]=r;
}
start=clock();
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
 
  printf("Sorted list in ascending order:\n");
 
  for ( c = 0 ; c < n ; c++ )
     printf("%d\n", array[c]);
end=clock();
totaltime=(double)(end-start)/CLOCKS_PER_SEC;
printf("total time =%f\n",totaltime);

}

