#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"magic.h"


/*Accepts number of type integer and prints it*/
void print_Number(int a)
{
 printf("%d\n",a);
}


/*Accepts matrix and size of matrix and print a matrix*/
void print_Square(int a[][MAX],int b)
{
 int i,j;
 for(i=0;i<b;i++)
   {
    printf("\n\n");
    for(j=0;j<b;j++)
       {
        printf("%4d",a[i][j]);
       }
   }
 printf("\n\n");
}

