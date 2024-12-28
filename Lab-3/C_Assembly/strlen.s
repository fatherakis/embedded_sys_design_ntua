.text
.align 4
.global strlen
.type strlen, %function

strlen:

/* Note r0 has the string data thus we can iterate on it */
/* Idea: start r1 at 0 and load str to r2.
   Then define loop and for each iteration:
   check r2 for null, if not increment conuter
   if null exit else iterate
*/
   mov r1, #0  		/* Init Counter */
   ldrb r2, [r0,#0]     /* Load initial char */
loop:
   cmp r2, #0           /* Check Loaded char */
   beq exit             /* Null Detected */
   add r1, #1 		/* Iterate */
   ldrb r2, [r0,#1]! 	/* Load the next character iteratively */
   b loop
exit:
   mov r0, r1           /* Move the  counter on r0 and exit */
   bx lr
