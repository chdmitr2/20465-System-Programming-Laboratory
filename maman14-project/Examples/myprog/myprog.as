;example file  

.extern    DATA4            
.extern    DATA3            
.entry     DATA2             
.entry     DATA1  

;main program 

Start:    dec   DATA4         
          mov   PROG.1,r4  
		  
DATA2:    cmp   #5,#6         
          dec   NUM                  
          add   r1,r5                
          red   r5                   
          bne   DATA4                
          mov   PROG.2,DATA3         
          mov   r1,r2                
          add   r7,DATA1             
          inc   NUM                  
          red   r1                   
          mov   PROG.1,DATA4         
          red   r3                   
          jmp   DATA3                
          bne   DATA2                
          mov   r5,r6                
          jmp   DATA1                
          prn   #-127  
		  
DATA1:    mov   r3,r4          
          dec   NUM                  
          bne   DATA4                
          jsr   NUM                  
          mov   #-1,r2               
          clr   r2    
		  
STOP:   stop              
NUM:    .data 100, 200,500,3
PROG:   .struct 511,"LC"   
STR:    .string "xyz"      
