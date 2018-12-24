/*Compare length of two strings*/
#include "my_string.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int my_strcmp(char* x,char* y)/*Take two strings from main*/
{
int a = strlen(x);/*length of first string*/
int b = strlen(y);/*length of second string*/
if(a!=b)
/* if lengths of strings not compare return 1 that say strings unidentical*/
{
return 1;
}
else{
return my_strncmp(x,y,a);
/*if lengths of strings compare go to my_strncmp function that check if chars of strings identical*/
}
}



