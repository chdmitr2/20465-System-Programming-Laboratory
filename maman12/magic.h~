#ifndef MAGIC_H
   #define MAGIC_H

#define MAXSIZE 9 /*max size of matrix(square)*/
#define MINSIZE 3 /*min size of matrix(square)*/
#define MAX 100   /*save place in memory for matrix*/

/*macros check if number in range [min,max] if number  in range return 1 else return 0*/
#define RANGE(n,min,max) ((n>=min) && (n<=max)) ? (1) : (0)

/*macros calculate number in square*/
#define SQR(n) ((n)*(n))

/*macros calculate sum of the integers in each row,column and diagonal*/
#define MAGICSUM(n) (((n)*(SQR(n)+1))/(2))

/*macros calculate sum of all values in matrix(square)*/
#define SQUARESUM(n) ((n)*MAGICSUM(n))

/*Accepts number of type integer and prints it*/
void print_Number(int);

/*Printing error message by error code that we received.
The program has six error codes 101,102,103,104,105,106 
program accepts one of them and print error message*/
void print_Error(int);

/*Take from input file values type of integers and place 
them in matrix by order of rows.If we have numbers in file
1,2,3,4 matrix 2x2 for example(in specific program min size is 3)
first row is 1,2 second row 3,4.In addition  it's calculate number
of values that entered and sum of all matrix and if matrix is 
correct return number of values if not return one of error codes*/
int built_Square(int [][MAX],int,int);

/*Accepts matrix and size of matrix and print a matrix*/
void print_Square(int [][MAX],int);

/*Accepts matrix and size of matrix and check if matrix(square) 
is magic square(sum of the integers in each row,column and 
diagonal is equal).If magic return 1 if not return 0*/
int check_if_Square_Magic(int [][MAX],int );

/*Accepts from input file number type of integer and return it
 if number is correct if not return one of error codes*/
int get_Square_size(void);

#endif
