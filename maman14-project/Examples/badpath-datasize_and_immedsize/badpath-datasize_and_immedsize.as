; This file contains tests for errors in the range of data values
; and tests for errors in the range of immediate operands
;------------------------------------------
; errors in the range of data values.
;-------------------------------------------
; 1. this line is ok
X:   cmp r1,r2

; 2. this line is ok (highest positive value that fits in 10 bits)
    .data  511

; 3. data overflow (positive value too large to fit in 10 bits)
    .data  512

; 4. this line is ok (lowest negative value that fits in 10 bits)
    .data  -512

; 5. data overflow (negative value too large to fit in 10 bits)
    .data  -513
;-----------------------------------------
;errors in the range of immediate operands
;------------------------------------------
; 1. this line is ok
DATA1: .data  100

; 2. this line is ok (largest positive immediate that fits in 8 bits)
       cmp #127,DATA1

; 3. invalid first operand (positive immediate too large to fit in 8 bits)
       cmp #128,DATA1

; 4. this line is ok (lowest negative immediate that fits in 8 bits)
       cmp r2,#-128

; 5. invalid second operand (negative immediate too large to fit in 8 bits)
       cmp r2,#-129

; 6. this line is ok
       stop