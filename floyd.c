#include<stdio.h>
#include<math.h>


int min(int a,int b)
{
   if(a>b)
     return b;
   else
     return a;
}

void floyd(int r[10][10],int n)
{
   int i,j,k;
   for(k=1;k<=n;k++)
     for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          r[i][j] = min(r[i][j],(r[i][k]+r[k][j]));
}

void main()
{
   int r[10][10],a[10][10],i,j,n;
   printf("enter no of vertices\n");
   scanf("%d",&n);
   printf("enter adjacency matrix\n");
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       scanf("%d",&r[i][j]);
     }
   }

   floyd(r,n);
   printf("transitive closure\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
        printf("%d\t",r[i][j]);
      }
      printf("\n");
   }
}
