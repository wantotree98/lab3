#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>


int main(void){

void sigint_handler(int sig);
int input;
int prime=1;
int pipefds[2];
int buffer;

if(signal(SIGINT, sigint_handler) == SIG_ERR){
perror("signal");
exit(EXIT_FAILURE);
}

if(pipe(pipefds) == -1){
perror("pipe");
exit(EXIT_FAILURE);
//error checking
}

printf("Enter a number please : \n");
scanf("%d", &input);
/*int nombor =22;

printf("Writing nombor to pipe... \n");
write(pipefds[1], &nombor, sizeof(nombor));
printf("Done. \n\n");

printf("Reading a number from pipe... \n");
read(pipefds[0], &buffer, sizeof(buffer));
printf("Done. \n\n");


printf("Number from pipe: %d \n", buffer);*/
for(int loop=2; loop < input ; loop++){

if((input % loop)== 0){
prime =0;
}

}

if(prime != 1){
printf("Writing number to pipe... \n");
write(pipefds[1], &input, sizeof(input));
printf("Done. \n\n");

printf("Reading a number from pipe... \n");
read(pipefds[0], &buffer, sizeof(buffer));
printf("Done. \n\n");


printf("Number from pipe: %d and its not a prime number! \n", buffer);
}
else{

printf("Writing number to pipe... \n");
write(pipefds[1], &input, sizeof(input));
printf("Done. \n\n");

printf("Reading a number from pipe... \n");
read(pipefds[0], &buffer, sizeof(buffer));
printf("Done. \n\n");


printf("Number from pipe: %d and its a prime number! \n", buffer);


return EXIT_SUCCESS;
}

}

void sigint_handler(int sig){

printf("This is a SIGINT signal!");

}
