.text
.align 4
.global strcmp
.type strcmp, %function

strcmp:
   mov r4, #0 		/* Result */
loop:
   ldrb r2, [r0], #1    /* Load str one */
   ldrb r3, [r1], #1    /* Load str two */
   cmp r2, r3		/* Compare loaded characters */
   beq equal   		/* check for null and exit or keep going */
   blt neg		/* Return negative if str1 < str2 */
   movgt r4, #1 	/* Return 1 for str1 > str2 */
   b exit

equal:
  cmp r2,#0 		/* Check for null */
  bne loop 		/* If no null back */
  b exit

neg:
 sub r4, r4, #1		/* From 0 sub 1 thus exit with -1 */
 b exit

exit:
 mov r0, r4             /* Send return value to r0 and  exit */
 bx lr

.data
