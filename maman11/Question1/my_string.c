/*This program checks if are input strings are same or not,search specific char in string and prints all results*/
#include "my_string.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 128
int main()
{
static char charBuffer[LENGTH];/*static variable toget strings from user*/
printf("Enter a name of function:\n");
/*Type one of three functions:my_strcmp or my_strncmp or my_strchr*/
scanf("%s",charBuffer);
if(strcmp("my_strchr",charBuffer)==0)/*if types my_strchr*/
{
char a;
char string1[LENGTH];
int index=-1;
printf("Which char you want to find?\n");
scanf("%s",&a);
printf("Enter your string:\n");
scanf("%s",string1);
index=my_strchr(string1,a);/*search char in string*/
if(index == -1)
{
printf("Your char %c was not found in string %s\n",a,string1);
}
else
{
printf("First occurrence of char %c is: %d\n",a,index);
}
}
else if(strcmp("my_strcmp",charBuffer)==0)/*if types my_strcmp*/
{
char string1[LENGTH];
char string2[LENGTH];
printf("Enter the first string:\n");
scanf("%s",string1);
printf("Enter the second string:\n");
scanf("%s",string2);
if(my_strcmp(string1,string2)==0)/*compare two strings if they have same lengths*/
{
printf("Your strings is identical\n");
}
else
{
printf("Your strings is unidentical\n");
}
}
else if(strcmp("my_strncmp",charBuffer)==0)/*if types my_strncmp*/
{
char string1[LENGTH];
char string2[LENGTH];
int n;
printf("Enter the first string:\n");
scanf("%s",string1);
printf("Enter the second string:\n");
scanf("%s",string2);
printf("Enter the number of cahrs to compare:\n");
scanf("%d",&n);
if(my_strncmp(string1,string2,n)==0)
/*compare n chars if they identical in two strings*/
{
printf("Your strings is identical first %d chars\n",n);
}
else
{
printf("Your strings is unidentical\n");
}
}
else
{
printf("Sorry!Your function %s not exist in our list\n",charBuffer);
/*message of weong type*/
}
return main();/*back to main*/
}
