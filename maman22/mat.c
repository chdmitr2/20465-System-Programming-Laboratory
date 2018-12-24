
#include "mat.h"


/*Matrices*/
mat_list mats[]={
                 {"MAT_A",&A},/*matrix A*/
                 {"MAT_B",&B},/*matrix B*/
                 {"MAT_C",&C},/*matrix C*/
                 {"MAT_D",&D},/*matrix D*/
                 {"MAT_E",&E},/*matrix E*/
                 {"MAT_F",&F},/*matrix F*/
                 {"#",NULL}   /*if no match*/
                };


/*Error messages*/
err_msg messages[]={
                    {"\nUndefined matrix name\n",&ERR0},                      /*message 0*/
                    {"\nParameter not a real number\n",&ERR1},                /*message 1*/
                    {"\nMissing parameter\n",&ERR2},                          /*message 2*/
                    {"\nExtraneous text at the end of command\n",&ERR3},      /*message 3*/              
                    {"\nMissing comma\n",&ERR4},                              /*message 4*/
                    {"\nMultiple consecutive commas\n",&ERR5},                /*message 5*/
                    {"\nUndefined matrix name or numbers of matrix \n",&ERR6} /*message 6*/
                   };



abc_parms parm;/*struct three matrices*/
asb_parms parm2;/*struct two matrices and scalar*/


/****************************************READ_MAT********************************************/
/*Take from input file values type of double and place them in matrix by order of rows.
If we have numbers in file1,2,3,4 matrix 2x2 for example(in specific program min size is 3)
first row is 1,2 second row 3,4.This command puts 16 number in matrix 4x4 if enter less then 
16 index accept zero.If more then 16 numberscommand take only first 16 numbers.*/
/********************************************************************************************/


void read_mat(void)
{
 char *ptr=NULL;
 char input[LEN],temp[LEN];
 double mat_temp[SQR(SIZE)];
 int i,x=0,y=0,z=0;
 FOR(i,SQR(SIZE))/*initializing of array mat_temp*/
 mat_temp[i]=0.0;
 fgets (input , LEN , stdin);/*take string from input after command name*/
 strcpy(temp,input);/*copy input string to auxiliary array*/
 if(*input=='\n')/*if nothing after command*/
   {
    printf("%s",messages[2].string);/*print error message*/
    return;
   }
 ptr=strtok(temp," ,"); /*cut the Matrix name*/
 for(i=0; mats[i].address ;i++) /*scan until NULL in mats[].address*/
    if(strcmp(ptr,mats[i].name)==0)/*if Matrix name matches*/
      break;
 if(mats[i].address==NULL)/*no match found*/
   {
    printf("%s",messages[6].string);/*print error message*/
    return;
   }
 strcpy(temp,"");/*make array empty*/
 strcat(temp,mats[i].name);/*add matrix name*/
 strcat(temp,",");/*add comma to array*/
 ptr=strstr(input,temp);/*pointer to comma in input*/
 if(ptr==NULL)/*if comma not exist*/
   {
    printf("%s\n",messages[4].string);/*print error message*/
    return;
   }
 else
     {
      while(*ptr!=',')/*going to comma*/
           ptr++;
     }
 /*getting input to temp matrix*/
 while(*ptr!='\0' && z < SQR(SIZE))
      {
       if(*ptr==',')
         {
          if(ptr[1]==',')/*if commas sequence*/
            {
             printf("%s\n",messages[5].string);/*print error message*/
             return;
            }
          else if((ptr[1] >= '0' && ptr[1]<='9') || ptr[1]==' '|| ptr[1]=='-')/*limits of numbers*/
            ptr++;
          else 
             {
              printf("%s\n",messages[1].string);/*print error message*/
              return;
             }
          }
      else;
      mat_temp[z++]=strtod(ptr,&ptr);/*enter a value in array which converted in double number from string*/
     }
 z=0;
 /*Entering input from flat array into Matrix*/
 FOR(x,SIZE)
 FOR(y,SIZE)
 mats[i].address[0][x][y]=mat_temp[z++];/*fill matrix*/
 printf("\nYour matrix is ready\n");
}


/****************************************PRINT_MAT*******************************************/
/*Accepts matrix print it.All numbers with a precision of 2 digits*/
/********************************************************************************************/


void print_mat(void)
{
 char *ptr=NULL;
 char input[LEN];
 int i,x,y;
 fgets (input , LEN , stdin);/*take string from input after command name*/
 ptr=strtok(input," \n"); /*cut the matrix name*/
 if(ptr==NULL || *ptr=='\n')/*if empty string*/
   {
    printf("%s\n",messages[0].string);/*print error message*/
    return;
   }
 for(i=0; mats[i].address ;i++)/*search matrix in list*/
    if(strcmp(ptr,mats[i].name)==0)/*compare input with matrices in list*/
      break;
 if(mats[i].address==NULL)/*no matches*/
   {
    printf("%s\n",messages[0].string);/*print error message*/
    return;
   }
 else
     {
      printf("\nMatrix %s:\n",mats[i].name);/*print matrix*/
      FOR(x,SIZE)
         {
          printf("\n\n");
              {
               FOR(y,SIZE)
               printf("%7.3g ",mats[i].address[0][x][y]);
               printf("\n");
              }
         }            
     }
}
 

/****************************************ADD_MAT*********************************************/
/*Take two matrices adding them and saving result in third matrix*/
/********************************************************************************************/
 
                                  
void add_mat(void)
{
 int x,y;
 if(get_matrix_abc()==TRUE)/*if correct command*/
   {
    FOR(y,SIZE)
    FOR(x,SIZE)
    parm.result[0][y][x]=parm.first_parm[0][y][x] + parm.second_parm[0][y][x];/*adding of matririces*/
    printf("\nAdding operation completed successfully\n");
   }
 else
      return;
}


/****************************************SUB_MAT*********************************************/
/*Take two matrices execute substraction  first of second and saving result in third matrix*/
/********************************************************************************************/


void sub_mat(void)
{
 int x,y;
 if(get_matrix_abc()==TRUE)/*if correct command*/
   {
    FOR(x,SIZE)
    FOR(y,SIZE)
    parm.result[0][x][y]=parm.first_parm[0][x][y] - parm.second_parm[0][x][y];/*substraction of matrices*/
    printf("\nSubstraction operation completed successfully\n");
   }
 else
     return;
}


/****************************************MUL_MAT*********************************************/
/*Take two matrices execute multiplication  first of second and saving result in third matrix*/
/********************************************************************************************/


void mul_mat(void)
{
 int x,y,z;
 if(get_matrix_abc()==TRUE)/*if correct command*/
  {
   FOR(x,SIZE)
   FOR(y,SIZE)
              {
               parm.result[0][x][y]=0; /*reset each matrix cell*/
               FOR(z,SIZE)
               parm.result[0][x][y]+= parm.first_parm[0][x][z] * parm.second_parm[0][z][y];/*multiplication*/
              }
   printf("\nMultiplication operation completed successfully\n");
 }
 else
     return;
}


/****************************************MUL_SCALAR******************************************/
/*Take two matrices execute multiplication  in scalar and saving result in second matrix*/
/********************************************************************************************/


void mul_scalar(void)
{
 int x,y;
 if(get_matrix_asb()==TRUE)/*if correct command*/
   {  
    FOR(x,SIZE)
    FOR(y,SIZE)
    parm2.result[0][x][y]=parm2.first_parm[0][x][y] * parm2.scalar;/*multiplication  in scalar*/
    printf("\nMultiplication in scalar operation completed successfully.\n");
   }
 else
     return;
}


/****************************************TRANS_MAT*******************************************/
/*Take matrix execute transpose of matrix  saving result in second matrix*/
/********************************************************************************************/


void trans_mat(void)
{
 int x,y,temp[SIZE][SIZE];/*temp-auxiliary 2d-array*/
 if(get_matrix_ab()==TRUE)/*if correct command*/
   {
    FOR(x,SIZE)
    FOR(y,SIZE)
    temp[y][x]=parm.first_parm[0][y][x];/*save matrix in auxiliary 2d-array*/
    FOR(x,SIZE)
    FOR(y,SIZE)
    parm.result[0][x][y]=temp[y][x];/*matrix transpose*/
    printf("\nMatrix transpose operation completed successfully.\n");
   }
 else
     return;
}


/****************************************STOP************************************************/
/*end of program*/
/********************************************************************************************/


void stop(void)
{
 printf("\nProgram stopped by user request.\n");
 exit(0);
}


/*****************************************abc************************************************/
/*Check if type of command with three matrices is correct and return true if correct or false
 if not.In addition if command not correct send error message*/
/********************************************************************************************/


int get_matrix_abc(void)
{
 char *ptr=NULL,*p1=NULL,*p2=NULL;
 char input[LEN],temp[LEN];
 int i,j,count=0;
 fgets (input , LEN, stdin);/*take string from input after command name*/
 strcpy(temp,input);/*copy input string to auxiliary array*/
 ptr=strtok(input," ,\n"); /*cut first matrix name*/
 if(ptr==NULL)/*empty string*/
   {
    printf("%s\n",messages[2].string);/*print error message*/
    return FALSE;
   }
 else
     {
      for(i=0; mats[i].address ;i++) /*find matrix*/
         if(strcmp(ptr,mats[i].name)==0)/*compare if name of matrix exist in list*/
           break;
      if(mats[i].address==NULL)/*no matches*/
        {
         printf("%s\n",messages[0].string);/*print error message*/
         return FALSE;
        }
      else
          parm.first_parm=mats[i].address;/*first parameter accepts a first matrix*/
     }

 ptr=strtok(NULL," ,\n"); /*cut second matrix name*/
 if(ptr==NULL)/*empty string*/
   {
    printf("%s\n",messages[2].string);/*print error message*/
    return FALSE;
   }
 else
     {
      for(i=0; mats[i].address ;i++) /*find matrix*/
         if(strcmp(ptr,mats[i].name)==0)/*compare if name of matrix exist in list*/
            break;
      if(mats[i].address==NULL)/*no matches*/
        {
         printf("%s\n",messages[0].string);/*print error message*/
         return FALSE;
        }
      else
          parm.second_parm=mats[i].address;/*second parameter accepts a second matrix*/
     }
 ptr=strtok(NULL," \n"); /*cut third matrix name*/
 if(ptr==NULL)
   {
    printf("%s\n",messages[2].string);/*print error message*/
    return FALSE;
   }
 else
     {
      for(i=0; mats[i].address ;i++) /*find matrix*/
         if(strcmp(ptr,mats[i].name)==0)/*compare if name of matrix exist in list*/
           break;
      if(mats[i].address==NULL)/*no matches*/
        {
         printf("%s\n",messages[3].string);/*print error message*/
         return FALSE;
        }
      else
      parm.result=mats[i].address;/*result parameter accepts a third matrix*/
     }
 p1=strchr(temp,',');/*first occurence of comma*/
 p2=strrchr(temp,',');/*last occurence of comma*/
 if(p1==p2)/*if equal pointers missing comma*/
   {
    printf("%s\n",messages[4].string);/*print error message*/
    return FALSE;
   }
 for(j=0;temp[j]!='\0';j++)/*check if in string more when 2 commas*/
    if(temp[j]==',') count++;
      if(count>2)
        {
         printf("%s\n",messages[5].string);/*print error message*/
         return FALSE;
        }
 return TRUE;
}


/***************************************asb**************************************************/
/*Check if type of command with two matrices and scalar is correct and return true if correct 
or false if not.In addition if command not correct send error message*/
/********************************************************************************************/


int get_matrix_asb(void)
{
 char *ptr=NULL,*p1=NULL,*p2=NULL;
 char input[LEN],temp[LEN];
 int i,j,count;
 fgets (input , LEN , stdin);/*take string from input after command name*/
 strcpy(temp,input);/*copy input string to auxiliary array*/
 ptr=strtok(input," ,\n"); /*cut first matrix name*/
 if(ptr==NULL)/*empty string*/
   {
    printf("%s\n",messages[2].string);/*print error message*/
    return FALSE;
   }
 else
     {
      for(i=0; mats[i].address ;i++) /*find matrix*/
         if(strcmp(ptr,mats[i].name)==0)/*compare if name of matrix exist in list*/
           break;
      if(mats[i].address==NULL)/*no matches*/
        {
         printf("%s\n",messages[0].string);/*print error message*/
         return FALSE;
        }
      else
          parm2.first_parm=mats[i].address;/*first parameter accepts a first matrix*/
     }
 ptr=strtok(NULL," ,\n"); /*cut scalar*/
 if(ptr==NULL)/*empty string*/
   {
    printf("%s\n",messages[2].string);/*print error message*/
    return FALSE;
   }
 else
     parm2.scalar=strtod(ptr,&ptr);/*enter a value in variable scalar which converted in double number from string*/
 ptr=strtok(NULL," \n"); /*cut second matrix name*/
 if(ptr==NULL)
   {
    printf("%s\n",messages[2].string);/*print error message*/
    return FALSE;
   }
 else
     {
      for(i=0; mats[i].address ;i++) /*find matrix*/
         if(strcmp(ptr,mats[i].name)==0)/*compare if name of matrix exist in list*/
           break;
      if(mats[i].address==NULL)/*no matches*/
        {
         printf("%s\n",messages[3].string);/*print error message*/
         return FALSE;
        }
      else
          parm2.result=mats[i].address;/*result parameter accepts a second matrix*/
     }
 p1=strchr(temp,',');/*first occurence of comma*/
 p2=strrchr(temp,',');/*last occurence of comma*/
 if(p1==p2)/*check if in string more when 2 commas*/
   {
    printf("%s\n",messages[4].string);/*print error message*/
    return FALSE;
   }
 for(j=0;temp[j]!='\0';j++)/*check if in string more when 2 commas*/
    if(temp[j]==',') count++;
      if(count>2)
        {
         printf("%s\n",messages[5].string);/*print error message*/
         return FALSE;
        }
 return TRUE;
}


/***************************************ab***************************************************/
/*Check if type of command with two matrices is correct and return true if correct or false 
if not.In addition if command not correct send error message*/
/********************************************************************************************/


int get_matrix_ab(void)
{
 char *ptr=NULL,*p1=NULL,*p2=NULL;
 char input[LEN],temp[LEN];
 int i;
 fgets (input , LEN , stdin);/*take string from input after command name*/
 strcpy(temp,input);/*copy input string to auxiliary array*/
 ptr=strtok(input," ,\n"); /*cut first matrix name*/
 if(ptr==NULL)
   {
    printf("%s\n",messages[2].string);/*print error message*/
    return FALSE;
   }
 else
     {
      for(i=0; mats[i].address ;i++) /*find matrix*/
         if(strcmp(ptr,mats[i].name)==0)/*compare if name of matrix exist in list*/
           break;
      if(mats[i].address==NULL)/*no matches*/
        {
         printf("%s\n",messages[0].string);/*print error message*/
         return FALSE;
        }
     else
         parm.first_parm=mats[i].address;/*first parameter accepts a first matrix*/
    }
 ptr=strtok(NULL," \n"); /*cut second matrix name*/
 if(ptr==NULL)
   {
    printf("%s\n",messages[2].string);/*print error message*/
    return FALSE;
   }
 else
     {
      for(i=0; mats[i].address ;i++) /*find matrix*/
         if(strcmp(ptr,mats[i].name)==0)/*compare if name of matrix exist in list*/
           break;
      if(mats[i].address==NULL)/*no matches*/
        {
         printf("%s\n",messages[3].string);/*print error message*/
         return FALSE;
        }
      else
          parm.result=mats[i].address;/*result parameter accepts a second matrix*/
     }
 p1=strchr(temp,',');/*first occurence of comma*/
 p2=strrchr(temp,',');/*last occurence of comma*/
 if(p1!=p2)/*if not equals multiple consecutive commas*/
   {
    printf("%s\n",messages[5].string);/*print error message*/
    return FALSE;
   }
 if(p1==NULL)/*if NULL missing comma*/
   {
    printf("%s\n",messages[4].string);/*print error message*/
    return FALSE;
   }
 return TRUE;
}




