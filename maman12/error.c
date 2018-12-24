#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"error.h"

void print_Error(int a)
{


/*This error code warning that size of matrix is out of range
(correct range is [3,9]) of file input is empty*/
 if(a==ERR1)
   {
    printf("\nError!!!Size of square out of range [3,9] or your file is empty!!!\n"); 
    exit(0);
   }


/*This error code warning that input file have too many values.
The correct number of values that must enter is square size of matrix*/
 if(a==ERR2)
   {
    printf("Error!!!Wrong number of values!!!Too many values!!!\n"); 
    exit(0);
   }


/*This error code warning that value that accepts from 
input file is out of range.The correct range from 1
 to amount of values of square size of matrix*/
 if(a==ERR3)
   {
    printf("Error!!!Value out of range !!!\n"); 
    exit(0);
   }


/*This error code warning that value that accepts from 
input file is not type of integer*/
 if(a==ERR4)
   {
    printf("Error!!!Value must be type of integer !!!\n");
    exit(0); 
   }


/*This error code warning that is same values in square.
All values that take from input file should be differrent*/ 
 if(a==ERR5)
   {
    printf("Error!!!There is same values in square !!!\n");
    exit(0); 
   }


/*This error code warning that input file have too few values.
The correct number of values that must enter is square size of matrix*/
if(a==ERR6)
   {
    printf("Error!!!Wrong number of values!!!Too few values!!!\n");
    exit(0); 
   }


}

