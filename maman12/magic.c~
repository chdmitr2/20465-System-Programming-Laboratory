/*This program take file with string of  different integers enter
them in matrix in nxn order and check if this matrix is square 
magic (sum of the integers in each row,column and diagonal
is equal).Program have number of error codes that warning if
input erroneuos.Inputs files have different names for example
kelet_5 or kelet_3 it is correct input with magic square.
Name of file err1 or err3 (error codes 101,103) example
incorrect files with specific error err1->101,err->103.
Program have six errors code with input file err1,err2....
It is include empty file name "./magic<empty" and square
without errors but not magic square"./magic<noerr_but_notmagic"*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"magic.h"
#include"error.h"

int main()
{
 int square[MAX][MAX];
 int size,values,count,magic;

 printf("Please enter which size of square nxn you want to use:  ");

 size=get_Square_size();/*take from input file first integer that states order nxn of square(matrix)*/

 if(RANGE(size,ERR1,ERR6)) print_Error(size);/*return error message if input is wrong*/

 print_Number(size);/*print size of matrix(square)*/

 printf("Number of values of square that you must enter is:  ");

 values=SQR(size);/*calculate how many values need to enter in matrix(square)*/

 print_Number(values);/*print number of values*/

 printf("Please enter %d different values of type integer.\n",values);

 printf("Values must be in range [1,%d].\n",values);

 count=built_Square(square,size,values);/*put all values in matrix from input file*/

 if(RANGE(count,ERR1,ERR6)) print_Error(count);/*return error message if input is wrong*/

 print_Square(square,size);/*print matrix(square)*/

 magic=check_if_Square_Magic(square,size);/*check if square(matrix) is magic square*/

 if(magic==1) printf("\n\n CONGRATULATION!!!YOUR SQUARE IS MAGIC SQUARE!!!\n\n");

 else printf("\n\n Sorry, but your square is not magic!!!\n\n");

 return 0;

}
