# Embedded Systems Design - ECE NTUA Course 2022 - 2023

This course is lab based with 6 total assignments. It focuses on FPGAs and ARM architectures including optimization techniques.
Subjects covered in this course:
* Algotithm Optimizations
* ARM Assembly
* HLS FPGA Design
* ARM Cross-Compilation

## <div align="center"> Lab 1 - Algorithm Optimizations </div>

* Loop Optimization & DSE ([DIR](Lab-1/1/)).
    * phods.c and subsequent versions, contain changes in "phods_motion_estimation" function with multiple optimization techniques. (see included instruction pdf for more info).
    * .sh scripts for average and processing.

* Automated Algorithm Optimization ([DIR](Lab-1/2/)).
    * Utilizing Orio package and configurations.

## <div align="center"> Lab 2 - Dynamic Data Type Refinement </div>

* Better check the assigmnent pdf [here](/Lab-2/2nd_laboratory_exercise_2022_2023.pdf) for detailed explanations.
    * [Dijkstra](/Lab-2/Dijkstra/)
    * [DRR](/Lab-2/DRR/)

## <div align="center"> Lab 3 - ARM Assembly </div>
Through QEMU KVM

* Parse and process Terminal input. [code](/Lab-3/Input_parse.s)

* Guest and Host machine communication through serial port. [DIR](/Lab-3/Serial_Communication/)

* Connect C and Assembly in ARM prossesor. [DIR](/Lab-3/C_Assembly/)

## <div align="center"> Lab 4 - HLS </div>

Intro to HLS with calcDist (Euclidian distance calculation) codes [here](/Lab-4/)

## <div align="center"> Lab 5 - HLS GAN evaluation </div>

HLS Optimizations: Quality and Performance assesment of GAN neural network on MNIST. [DIR](/Lab-5/)

## <div align="center"> Lab 6 - ARM Cross-Compilation System Call </div>

Cross-compile a system call function for ARM architecture using crosstool. All testing and simulations are run on QEMU KVM. [Here](/Lab-6/) are the qemu images along with all required files to implement, compile and run the system call.