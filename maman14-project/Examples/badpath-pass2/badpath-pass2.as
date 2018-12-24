; This file is intended to check the bad-path of the assembler.

; 1. this line is ok (label X is ignored, warning may be issued in 1st pass)
X:     .extern DATA1

; 2. this line is ok (label Y is ignored, warning may be issued in 1st pass)
Y:     .entry START

; 3. this line is ok (DATA1 is an external label)
START:  add  DATA1,r1

; 4. undefined label as first operand
        add  Q,r2

; 5. undefined label as second operand
        add  r3,Q

; 6. undefined label as first operand (label X is ignored)
        add  X,r4

; 7. undefined label as second operand (label Y is ignored)
        add  r5,Y

; 8. undefined label
       .entry Q

; 9. undefined label (label X is ignored)
       .entry X

; 10. undefined label (label Y is ignored)
       .entry Y

; 11. this line is ok
        stop