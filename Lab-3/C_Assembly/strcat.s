.text
.align 4
.global strcat
.type strcat, %function

strcat:
  mov r3, r0 		/* save the initial address to fallback to */

find_end:
  ldrb r2, [r0], #1 	/* Iterate over string */
  cmp r2, #0
  bne find_end 		/* Iterate endlessly until null is found */
  sub r0, #1

loop:
  ldrb r2, [r1] ,#1 	/* Iterate over string */
  strb r2, [r0] ,#1 	/* Append it at the end */
  /* Note we don't use [r0, #1] since it starts from the start and iterates on r0 while [r0], #1
     adds on r0 thus can keep going from the end */
  cmp r2,#0             /* Check for Null and exit else loop again */
  bne loop
exit:
  mov r0, r3
  /* After the iteraions the addres variable stays at the last spot thus fallback to start. */
  bx lr
