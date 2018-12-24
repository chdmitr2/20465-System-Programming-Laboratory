/*This program receives a set of sentences and corrects mistakes and writes them correctly with the correct spacing between lines*/
#include<stdio.h>
#include<ctype.h>

enum status{OUT,NEW_SENTENCE,QUOTES};/*different states of sentences*/

int main(){
        int c, state = NEW_SENTENCE,buffer=0;
        while((c = getchar()) != EOF){
      /*don't exit from loop until receive end of file*/
             switch(state){
                    case NEW_SENTENCE:/*start from here*/
                        if (isdigit(c))/*if digit skip*/
                                  break;
                        else if(c == '"'){
/*if apostrophes print char when go to case Quotes after that save char in buffer and back to while or from there came(one of cases)*/
                            putchar(c);
                            state = QUOTES;
                            buffer=c;
                                  break;    
                            }
                        else if(c == '.'){
/*if period print char twice print new line when go to case New sentence after that  back to while or from there came(one of cases)*/
                            putchar(c);
                            putchar('\n');
                            putchar('\n');
                            state = NEW_SENTENCE;
                                  break; 
                            }
                        else if(c == ' '){
/*if space first time save in buffer else back while or from ther came (one of cases)*/                        
                               if(buffer != ' ')
                                   buffer=c;
                                  break;
                            }
                        else if(c == '\n')
/* if new line print and back to while or from there came (one of cases),else print Capital letter and go case Out after that save char in buffer and back to while or from there came (one of cases)*/
                            putchar(c);
                              else{
                                 putchar(toupper(c));
                                 state = OUT;
                                 buffer=c;
                             }        
                                  break;
                                         
                     case QUOTES:
                             if(c == '"'){
/*if apostrophes print char if in buffer period go to case Out else to New sentence after that back to while or from there came(one of cases)*/
                            putchar(c);
                                if(buffer == '.')
                                   state = OUT;
                                else
                                   state = NEW_SENTENCE;
                                  break;    
                            }
                            else if (isdigit(c))/*if digit skip*/
                                  break;
                            else if(c == ' '){
/*if space first time print char and save in buffer else back while or from ther came (one of cases)*/                        
                                 if(buffer != ' ')
                                   putchar (c);
                                   buffer=c;
                                  break;
                            }
                            else if (c == '\n'){
                    /*if new line print and plus new line*/
                                    putchar (c);
                                    putchar('\n');
                                  break;
                            }
                            else if(isalpha(c)){
/*if letter change to Capital save in buffer else back while or from ther came (one of cases)*/
                                 putchar(toupper(c));
                                 buffer = c;
                                  break;
                            }
/*else print c save in buffer else back while or from ther came (one of cases)*/                        
                                 putchar(c);
                                 buffer = c;
                                  break;
                            

                                                                                          
                     case OUT:
                               if(c == '.'){
/*if period print char twice print new line when go to case New sentence after that  back to while or from there came(one of cases)*/
                                  putchar(c);
                                  putchar('\n');
                                  putchar('\n');
                                  state = NEW_SENTENCE;
                                  break;
                            }
                            else if((c == '\n') && (buffer=='.')){
/*if new line and buffer is period print new line and go to New sentence after that  back to while or from there came(one of cases)*/
                                    putchar(c);
                                    state = NEW_SENTENCE;
                                  break; 
                            }
                            else if(c == '\n'){
/*if new line print new line and go to Out after that  back to while or from there came(one of cases)*/
                                    putchar(c);
                                    state = OUT;
                                  break; 
                            }
                            else if (isdigit(c))/*if digit skip*/
                                  break;
                            else if(isalpha(c)){
/*if letter change to lower char save in buffer else back while or from ther came (one of cases)*/
                                    putchar(tolower(c));
                                
                            }
                            else if(c == ' '){
/*if space first time print char and save in buffer else back while or from ther came (one of cases)*/                        
                                 if(buffer != ' ')
                                   putchar (c);
                                   buffer=c;
                                  break;
                            }
                            else if(c == '"'){
/*if apostrophes print char when go to case Quotes after that save char in buffer and back to while or from there came(one of cases)*/
                            putchar(c);
                            state = QUOTES;
                            buffer=c;
                                  break;    
                            }
                            else
                                 putchar(c);
                                 buffer=c;
                                  break;
                             }
                    }
return 0;
}

