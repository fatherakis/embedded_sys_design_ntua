.text
.align 4
.global strcpy

.type strcpy, %function

strcpy:
  mov r3, r0 		/* String Address */

  /* Until null we can load from 1 string and save to other */
  /* note r0 is destination r1 is source */
loop:
  ldrb r2, [r1] ,#1    /* Load input string */
  strb r2, [r0] ,#1    /* Save to target */
  cmp r2,#0	       /* Check for NULL */
  bne loop	       /* If not  then iterate */
quit:
  mov r0, r3
  /* After the iteration, r0 will have stayed on its last position thus we need to reset it */
  bx lr

.data
