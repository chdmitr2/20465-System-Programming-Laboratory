/*Program search first char in string that we need and return to main*/
#include "my_string.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int my_strchr(char* x,char z)
/*Take string and char that need to find in string from main*/
{
int index = -1;
int i =0;
while ((x[i] !='\0')&&(index == -1))
/*Continue this loop while it's not end of string and index=-1*/
{
if (x[i] == z)/*if you find a char in string index = i*/
{
index=i;
}
i++;/*else continue to search take next char*/
}
if((index == -1)&&(x[i]==z))/*if next char is our char that we need index=i*/
{
index=i;
}
return index;/*if return -1char not found else return index of char*/
}
