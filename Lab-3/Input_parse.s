
.text
.global main

@Syscalls: r0 defines the file descriptor
@          r1 defines the string to print/store value
@          r2 defines the bytes to read/write
@
@          r7 defines the type of syscall  3: write 4: read 1: exit
@          swi 0  runs the syscall  as  syscall + r7 as seen on instructions

@Read syscall:
@          after reading the r1 has the read data
@          after reading the r0 has the counter of bytes read

@Write syscall:
@          after writing the r0 has the counter of bytes written (useless tbh)

convert:
   push {r1,r2,r3,r4,r5,r8,lr}  @Lets not break our important registers + lr since its a function
   ldr r1, =input_safe_string   @Load the read string to traverse through
   ldr r2, =output_string       @Load the conversion buffer to modify
loop:
   cmp r0,#0                    @For each character read
   blt finished_conversion      @Traverse from back to front, when done end
   ldrb r3, [r1,r0]             @For each position load the character

   cmp r3,#58                   @9+1
   blt check_nums_conv          @Goto numbers conversion Note: commands here didnt work for sub

   cmp r3, #91                  @Z+1
   blt check_A_conv             @Goto Capital conversion Note: this could be done here but breaks lowercase

   cmp r3,#123                  @z+1
   blt check_a_conv             @Goto lowercase conversion Note: sub doesnt work in here

ret:
   strb r3, [r2,r0]             @Save the modified character to the corresponding position
   sub r0, r0, #1               @Iterate r0 backwards
   b loop                       @Redo whole process
finished_conversion:
   pop {r1,r2,r3,r4,r5,r8,lr}   @Recover the registers
   bx  lr                       @Go back to where the function was called

check_a_conv:
   cmp r3, #96                  @a-1
   subgt r3, r3, #32            @This means we are within z-a so -32
   b ret

check_A_conv:
   cmp r3, #64                  @A-1
   addgt r3, r3, #32            @This means we are within Z-A so +32
   b ret                        @Go back to iteration

check_nums_conv:
   cmp r3,#52                   @4
   bgt ninetofive               @This means we are within 9-5 so branch cuz subgt doesnt work
   cmp r3,#47                   @0-1
   addgt r3,r3,#5               @This means we are within 4-0 so +5
   b ret                        @Go back to iteration

ninetofive:
   subs r3, r3, #5              @subgt doesn't change the nums for -5
   b ret                        @Go back to iteration

main:
   push {ip,lr}                 @Push the instruction pointer and link register
reuse:   
   @Write using syscall "Input a string of up to 32 characters long: "
   mov r0, #1                   @Initialize r0 to stdout
   ldr r1, =input_message       @Load the message to send Note: we could use . - output_message but we choose not to
   mov r2, #43                  @Set the bytes to be written
   mov r7, #4                   @Set syscall to write(fd, buffer, count)
   swi 0                        @Do system call

   @Read that string
   mov r0, #0                   @Initialize r0 to stdin
   ldr r1, =input_safe_string   @Load buffer to save input Note: we could use . - output_message but we choose not to
   mov r2, #256                 @Supports 256 characters before crashing
   mov r7, #3                   @Set syscall to read (fd, buffer, count)
   swi 0                        @Do system call

   @Check for Quitting through r0
   cmp r0, #2                   @Check the read bytes if 2 (char + eol)
   bne skip_ahead               @Over 1 char so continue
   ldrb r2, [r1]                @Override r2 with r1[0]
   cmpeq r2, #81 @is it Q       @If Q (ascii)
   beq exit_msg                 @Then exit
   cmp r2, #113 @or is it q     @If q (ascii)
   beq exit_msg                 @Then exit


   @Call the conversion here and iterate based on min(r0,32) characters
skip_ahead:
   subs r0, r0, #2              @Remove 2 bytes since last 2 are \n + eol
   cmp r0, #32                  @Check the character count with 32
   movgt r0, #32                @If more then override with 32 for function
   bl convert                   @Call function  Note: we use bl to call with link which we will have to return



   @Print a message indicating results
   mov r0, #1                   @Initialize r0 to stdout
   ldr r1, =output_message      @Print the output message
   mov r2, #16                  @Set the byte value Note: we could use . - output_message but we choose not to
   mov r7, #4                   @Set syscall to write(fd, buffer, counter)
   swi 0                        @Do system call



   @Print the converted string
   mov r0, #1                   @Initialize r0 to stdout
   ldr r1, =output_string       @Print the converted string
   mov r2, #34                  @Set the byte value Note: we could use . - output_message but we choose not to
   mov r7, #4                   @Set syscall to write(fd, buffer, counter)
   swi 0                        @Do system call
   b reuse                       @Restart Program


exit_msg:
   @Print a message indicating exit
   mov r0, #1                   @Initialize r0 to stdout
   ldr r1, =exit_message      @Print the output message
   mov r2, #11                  @Set the byte value Note: we could use . - output_message but we choose not to
   mov r7, #4                   @Set syscall to write(fd, buffer, counter)
   swi 0                        @Do system call


  @Return 0
exit:
   @Lets setup a return and then pop to finish
   mov r0, #0                   @Initialize r0 (return value) to 0
   mov r7, #1                   @Set syscall to exit
   swi 0                        @Do system call
   pop {ip,pc}                  @Pop instruction pointer and link register to return to normal state


.data
  input_message: .asciz "Input string of up to 32 characters long: "
  input_safe_string: .asciz "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  output_message: .asciz "Your result is: "
  output_string: .asciz "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\n"
  exit_message: .asciz "Exiting...\n"
