.text
.global main
.align 4 /*alignment of code*/
.extern tcsetattr
.extern printf

main:
    ldr r0, = port /*load the adress of the device we need to open*/
    mov r1, #2 /*stdin and stdout*/
    ldr r2, =0666
    mov r7, #5 /*load the open system call*/
    swi 0
    /* now r0 has the fd */
 
    cmp r0, #0 /*check if the open was executed with errors*/
    bmi end
    mov r5, r0 /*save the fd for later*/
    /*set up the device*/
    /* call tcsetattr function in order to set the settings for the port*/
    mov r1, #0  
    ldr r2, =options
    bl tcsetattr

    /*read characters from the serial port*/
    mov r0, r5 /*load the fd*/
    ldr r1, =buffer_string
    mov r2, #64 /*read up to 64 characters*/
    mov r7, #3 /*load read system call*/
    swi 0
    /*save the number of char that were read*/
    bl freq_calculator
    /*Write the most frequent character to the port*/
    mov r0, r5 
    ldr r1, =result
    ldr r2, =len_result
    mov r7, #4 /*write system call position*/
    swi 0

    /*beginning the closing of the port*/
    mov r0, r5 /*fd position*/
    mov r7, #6 /*close system call position*/
    swi 0

end:/*exit the programm with an output 0*/
    mov r0, #0 
    mov r7, #1 /*exit system call*/
    swi 0

freq_calculator:
    push {r1-r6} /*remember to pop it in the end*/
    /*r1 has the buffer string*/
    mov r2, #0 /*it will be used as a counter*/
    ldr r4, =freq_arr

start:
    cmp r2, #64 /*if 64 is being reach then stop*/
    /*This is for the special case where the user enters 64 characters + \n*/
    beq cont    

    ldrb r3, [r1, r2] /* load value of array with offset r2 */
    cmp r3, #10 /*If we find \n  character then frequency culculator is ended*/
    beq cont

    cmp r3, #32 /*we dont count the frequency of the space character*/
    /*increase the counter*/
    addeq r2, r2, #1 
    beq start

    sub r3, r3, #33 
    /*Load the frequency of input char from frequrency array*/
    ldrb r5, [r4, r3] 
    add r5, r5, #1 /*Increase the frequency of the character*/
    strb r5, [r4, r3] 
    add r2, r2, #1 /*Increase the counter*/
    b start

cont:
    mov r2, #0 /*Initialize the counter*/
    mov r5, #0 /*Used to save the maximum frequency of the most used character*/
    mov r6, #0 /*Position of the max used characetr on frequency array*/

max_freq_loop:
    cmp r2, #94 
    beq finalize
    ldrb r3, [r4, r2] /*Get frequency of r2 cell in freq_arr.*/
    /*Change the most frequent char if the frequency is bigger than the previous one*/
    cmp r3, r5   
    movgt r5, r3 
    movgt r6, r2 /*Save new_max_freq, character's offset in freq_arr*/
    add r2, r2, #1
    b max_freq_loop

finalize:
    /*r4 has result array address*/
    ldr r4, =result
    /*The most frequent character and its frequency*/
    add r6, r6, #33 
    strb r6, [r4]
    sub r5, r5, #48
    strb r5, [r4, #2] 

exit:
    pop {r1-r6}
    bx lr


.data

     options:.word 0x00000000 /* c_iflag */
             .word 0x00000000 /* c_oflag */
             .word 0x000008bd /* c_cflag */
             .word 0x00000002 /* c_lflag */
             .byte 0x00       /* c_line */
             .word 0x00000000 /* c_cc[0-3] */
             .word 0x00010000 /* c_cc[4-7] */
             .word 0x00000000 /* c_cc[8-11] */
             .word 0x00000000 /* c_cc[12-15] */
             .word 0x00000000 /* c_cc[16-19] */
             .word 0x00000000 /* c_cc[20-23] */
             .word 0x00000000 /* c_cc[24-27] */
             .word 0x00000000 /* c_cc[28-31] */
             .byte 0x00       /* padding */
             .hword 0x0000    /* padding */
             .word 0x0000000d /* c_ispeed */
             .word 0x0000000d /* c_ospeed */

port:
    .ascii "/dev/ttyAMA0" /*the "device" that will communicate with the host*/


buffer_string: 
    .ascii "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
len_buffer = . - buffer_string

freq_arr:
    .ascii "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
/*1byte for 9 all the4 possible characters*/
result: 
    .ascii "c\0f"
len_result = . - result
