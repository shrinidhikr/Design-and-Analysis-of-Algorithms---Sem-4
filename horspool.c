#include<stdio.h>
#include<string.h>
int table[128];
int txt_len;
int pat_len;
//table is an array indexed by ascii value of charecter,it contains the steps by which the
//pattern has to be shifted for a particular character.

void build_table(char pattern[])
{
  int i=0;
  int j=0;
  
  
  for(i;i<128;i++) table[i]=pat_len;
  for(j;j<pat_len-1;j++) table[pattern[j]]=pat_len-1-j;
}

int find_pattern(char text[],char patter[])
{
    int i,j,k,t;
    
    for(i=pat_len-1;i<txt_len;i+=k)
    {
      t=i;
      for(j=pat_len-1;j>=0;j--)
      {
        if(text[t]!=patter[j]) break;
        t--;
      }
      
      if(j==-1) return i-pat_len+1;
      k=table[text[i]];
      
      
      
    }
    return -1;
}

void main()
{
  char text[100];
  char pattern[100];
  int loc;
  int i=0;
  printf("Enter the text \n");
  gets(text);
  txt_len=strlen(text);
  
  printf("Enter the pattern to be found\n");
  gets(pattern);
  pat_len=strlen(pattern);
  
  build_table(pattern);
  loc=find_pattern(text,pattern);
  
  if(loc==-1) printf("Pattern not found \n");
  else printf("Pattern starts at %d",loc);
  
  
  
}
