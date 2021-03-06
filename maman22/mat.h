#ifndef MAT_H
   #define MAT_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4 /*Size of matrix*/
#define LEN 100 /*Save place in memory for string*/

/*Macros calculate number in square*/
#define SQR(n) ((n)*(n))

/*Macros short way for loop*/
#define FOR(n,m) for(n=0;n<m;n++)

/*Macros short way for loop*/
#define FOREVER for(;;)

/*Numbers '0' and '1'*/
enum{TRUE,FALSE};

/*Type definition of matrix 4x4*/
typedef double matrix[SIZE][SIZE];

/*Type definition of string with error message 100 characters in string*/
typedef char errors[LEN];

/*Definition of six matrices*/
matrix A,B,C,D,E,F;

/*Definition of seven errors messages*/
errors ERR0,ERR1,ERR2,ERR3,ERR4,ERR5,ERR6;

/*Type definition of struct error message that have string with pointer to error message
and pointer to his address in memory that save place array of 100 index's*/
typedef struct
              {
               char *string;
               errors *address;
              }err_msg;


/*Type definition of struct list of matrices that have pointer to  name of matrix
and pointer to address in memory that save place 2-d matrix 4x4*/
typedef struct 
              {
               char *name;
               matrix *address;
              }mat_list;


/*Type definition of struct matrices commands that have a pointer to name of command
and void pointer to this function with the aim to execute this function*/
typedef struct
              {
               char *name;
               void (*func)(void);
              } mat_command;



/*Type definition of struct parametrs that going after command.This struct
 have three parameters all threes is matrices that first_parm pointer to 
first matrix,second_parm pointer to second matrix and result_parm pointer 
to third matrix.Program have commands that need this type of three matrices*/
typedef struct 
              {
               matrix *first_parm;
               matrix *second_parm;
               matrix *result;
              }abc_parms;


/*Type definition of struct parametrs that going after command.
This struct have three parameters all two is matrices that first_parm 
pointer to first matrix,result_parm pointer to second matrix and 
scalar pointer to double number.Program have commands that need 
this type of two matrices and scalar*/
typedef struct 
              {
               matrix *first_parm;
               double scalar;
               matrix *result;
              }asb_parms;


/*Take from input file values type of double and place 
them in matrix by order of rows.If we have numbers in file
1,2,3,4 matrix 2x2 for example(in specific program min size is 3)
first row is 1,2 second row 3,4.This command puts 16 number in 
matrix 4x4 if enter less then 16 index accept zero.If more then 16 numbers
command take only first 16 numbers.*/
void read_mat(void);


/*Accepts matrix print it.All numbers with a precision of 2 digits*/
void print_mat(void);
  

/*Take two matrices adding them and saving result in third matrix*/
void add_mat(void);


/*Take two matrices execute substraction  first of second and saving 
result in third matrix*/
void sub_mat(void);


/*Take two matrices execute multiplication  first of second and saving 
result in third matrix*/
void mul_mat(void);


/*Take two matrices execute multiplication  with scalar and saving 
result in second matrix*/
void mul_scalar(void);


/*Take matrix execute transpose of matrix  saving 
result in second matrix*/
void trans_mat(void);


/*end of program*/
void stop(void);


/*Check if type of command with three matrices is 
correct and return true if correct or false if not.
In addition if command not correct send error message*/
int get_matrix_abc(void);


/*Check if type of command with two matrices and scalar is 
correct and return true if correct or false if not.
In addition if command not correct send error message*/
int get_matrix_asb(void);


/*Check if type of command with two matrices is 
correct and return true if correct or false if not.
In addition if command not correct send error message*/
int get_matrix_ab(void);

#endif

