#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"magic.h"

/*Accepts matrix and size of matrix and check if matrix(square) 
is magic square(sum of the integers in each row,column and 
diagonal is equal).If magic return 1 if not return 0*/
int check_if_Square_Magic(int a[][MAX],int b)
{
 int i,j,sum,temp;
 sum=MAGICSUM(b);


/*Check if diagonal equal to MAGICSUM*/
 for(i=0,j=0;i<b && j<b;i++,j++)
     {
      temp=a[i][j];
      sum-=temp;
     }
 if(sum!=0) return 0;


/*Check if each row equal to MAGICSUM*/
 for(i=0;i<b;i++)
    {
     sum=MAGICSUM(b);
      for(j=0;j<b;j++)
         { 
           temp=a[i][j];
           sum-=temp;
         }
     if(sum!=0) return 0;
    }


/*Check if each column equal to MAGICSUM*/
 for(j=0;j<b;j++)
     {
      sum=MAGICSUM(b);   
      for(i=0;i<b;i++)
         { 
           temp=a[i][j];
           sum-=temp;
         }
     if(sum!=0) return 0;
    }
 return 1;/*return 1 if square is magic square else 0 */
}
