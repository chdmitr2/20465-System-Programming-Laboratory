/*This program accepts from stdin(file,keyboard) commands to execute operations on matrices.
It is take from file "input" each command and check if command exist in program.If it not 
exist program send error message of if a command is not correct.The program works like loop 
and exit when accept command "stop".In this file the program is starts and take from file
command if command exist it's going to function of this command exucute operation if not
print error message that commands not exist and wait to next command while not accepts stop*/
 

#include "mat.h"


/*Commands of program*/
mat_command cmd[]={
                   {"read_mat",read_mat},    /*reading numbers in matrix*/
                   {"print_mat",print_mat},  /*print matrix*/
                   {"add_mat",add_mat},      /*adding two matrices*/
                   {"sub_mat",sub_mat},      /*substraction two matrices*/
                   {"mul_mat",mul_mat},      /*multiplication two matrices*/
                   {"mul_scalar",mul_scalar},/*multiplication matrix in scalar*/
                   {"trans_mat",trans_mat},  /*matrix transpoce*/
                   {"stop",stop},            /*end of program*/
                   {"not_valid",NULL}        /*no match*/
                  };


int main(void)
{
 int i;
 char ch=',';
 char command[30],*p,str[30];
 printf("Enter commands on the matrices:\n\n");
 FOREVER
 if(scanf("%s",command))/*take command from input*/
   {
    for(i=0 ; cmd[i].func ; i++) /*searching command name*/
       {
         strcpy(str,command);/*copy command to array that help search comma in string*/
         p=strchr(str,ch);
         if(p!=NULL)/*if comma in string*/
          {        
           printf("\nInvalid comma after command name\n");/*if after command name comma*/
           goto next;
          }
       if(strcmp(command,cmd[i].name)==0)/*compare input with command names*/ 
          break;
       }
    if(cmd[i].func==NULL)/*no match*/
      {
       printf("\nUnknown command name \"%s\"\n",command);/*if no matches of commands*/ 
       while(getchar()!='\n');
      }
    else
     (*(cmd[i].func))();/*going to execute operation*/
    next: printf("\n");
   }
 return 0;
}


