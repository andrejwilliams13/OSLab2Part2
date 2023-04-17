/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
//Andre Williams

int alarmOn = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(2);
  alarmOn = 1;
}


int main(int argc, char * argv[])
{
  signal(SIGALRM, handler); //register handler to handle SIGALRM
  alarm(2);
  while(1){
    alarmOn = 0;
    alarm(2);
    while(!alarmOn);
      printf("Turing was right!\n");
    
  }
  return 0;
}
