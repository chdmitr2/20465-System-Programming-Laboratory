#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"magic.h"
#include"error.h"


/*Accepts from input file number type of integer and return it
 if number is correct if not return one of error codes*/
int get_Square_size()
{
 int num;
 if(scanf("%d",&num))
   {
    if(!RANGE(num,MINSIZE,MAXSIZE))
      {
        return ERR1;/*if number is out of range return error code*/
      }
    else return num;/*return value that takes from file*/
   }
  return ERR4;/*if number not type of integer return error code*/
}


/*Take from input file values type of integers and place 
them in matrix by order of rows.If we have numbers in file
1,2,3,4 matrix 2x2 for example(in specific program min size is 3)
first row is 1,2 second row 3,4.In addition  it's calculate number
of values that entered and sum of all matrix and if matrix is 
correct return number of values if not return one of error codes*/
int built_Square(int a[][MAX],int b,int c)
{
 int i=0,j=0,num,count=0,sum=0;


     while(scanf("%d",&num)==1)/*while value from file integer stay in loop*/

          {   
           
           if((j<b) && (i<=b))/*the boundaries of matrix*/
             {
 
              if(!RANGE(num,1,c)) return ERR3;/*if value out of range return error code*/

              a[i][j]=num;

              if(i==b) return ERR2;/*pass  boundaries of matrix too many values return error code*/

              if(j==b-1) /*j came to the edge of columns stars new row*/
                {

                 j=0;
                 i+=1;

                }

               else j+=1;
             }

             count+=1;/*numbers of values*/
             sum+=num;/*sum of matrix(square)*/
          } 

     /*exit from while but not end of file that say is wrong type of value*/
     if((count<c)&&(scanf("%d",&num)!=EOF)) return ERR4;

     /*exit from value but number of values too few return error code*/
     if(count<c) return ERR6;

     /*sum of matrix not equal to SQUARESUM but all values range that say
     we have same values in string*/
     if(sum!=SQUARESUM(b)) return ERR5;

     return count; /*return number of values*/   

}
