/*This program receives decimal numbers and returns decimal 
number which result of operation bitwise and of input numbers.
All numbers type of unsigned integer*/


#include "my_and.h"


unsigned  int var_and(unsigned int num,...) {

   va_list valist;
   unsigned int res,val;
   int i;

   /* initialize valist for num number of arguments */
   va_start(valist, num);

   /* access all the arguments assigned to valist */
   val=va_arg(valist,unsigned int);
   res=val;
  
   
   printf(LINE);
   printf("Numbers: ");

   for(i=0;i<num;i++)
      {
       res &=val;
       printf("%d ",val);/*print numbers*/
       val=va_arg(valist,unsigned int);
      }
	
   /* clean memory reserved for valist */
   va_end(valist);

   return res;
}

int main()
{
 printf(ACT);
 printf(RESULT,var_and(6,10,5,10,5,10,5));
 printf(RESULT,var_and(4,10,10,10,10));
 printf(RESULT,var_and(8,3,1,127,15,31,63,255,7)); 
 printf(RESULT,var_and(5,93,126,90,124,89));            
 printf(LINE); 
 printf(END);    
return 0;
}
