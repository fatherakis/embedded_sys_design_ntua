#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <stdio.h>

#define BUFF_SIZE 65 //Buffer size of 64 characers and \n in the worst case scenario
int main(int argc, char **argv)
{
    int fd, lens;
    char input[BUFF_SIZE], output[BUFF_SIZE];
    ssize_t read_bytes;
    struct termios config;
    if (argc != 2) {
  		fprintf(stderr, "The right number of arguments weren't given please try again");
  		exit(1);
  	}
    printf("Please give a string to send to guest:\n");
    read_bytes = read(0, input, BUFF_SIZE); // Read the given from keyboard string
    if (read_bytes<0){
      perror("Not any character has been read");
  		exit(1);
    }
    lens = read_bytes;
    if (lens == 66) {
  		fprintf(stderr, "The string is more than 64 bytes please try with a smaller string!\n");
      fflush(0);
  		exit(1);
  	}
    else
      printf("The string is %d bytes. Valid!\n", lens);


    fd = open(argv[1], O_RDWR | O_NOCTTY);//Opent the seriel port

    if (fd == -1) {
        printf("Not able to open port\n");
        return 1;
    }

    if(tcgetattr(fd, &config) < 0) {
        printf("Failled to get the data from the terminal\n");
        return 1;
    }

    config.c_lflag = 0;
    config.c_lflag |= ICANON; /* Make port canonical */
    config.c_cflag |= (CLOCAL | CREAD | CS8);
    config.c_cflag &= ~CSTOPB;
    config.c_cc[VMIN] = 1; 
    config.c_cc[VTIME] = 0; //Returning as soon as any data is received.


   /* Set in/out baud rate */
    if(cfsetispeed(&config, B9600) < 0 || cfsetospeed(&config, B9600) < 0) {
        printf("Problem with baudrate\n");
        return 1;
    }

    /* Finally, apply the configuration */
    if(tcsetattr(fd, TCSANOW, &config) < 0) {
        printf("Couldn't apply settings\n");
        return 1;
    }

    tcflush(fd, TCIOFLUSH); /* Clear everything that is in the terminal*/

    printf("Sending to guest the string...\n");

    write(fd, input, BUFF_SIZE);

    printf("Reading from guest the most frequent character...\n");

    read(fd, output, BUFF_SIZE);

    int i, final;

    final = output[2];

    final=final-'0';


    if(final!=0)
      printf("The most frequent character is %c and it appeared %d times.\n", output[0], final);
    else
      printf("No characters were given\n");
    close(fd);
    return 0;
}