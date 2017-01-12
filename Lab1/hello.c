#include <stdio.h>

/*
  This program will print hello world
  over and over again every 3 seconds
  also changes colors of terminal
 */
int main(){
  while(1){ // allows to run forever
    int randomnumber; // used for storing a random number to dictate color

    randomnumber = rand() % 8; // generates the number
    
    /*
      %d is used as int placeholder
      
      \33[0;3%dm    --  changes font color
      \033[4%dm     --  changes background color
      \033[4;3%dm   --  changes underline color
     */
    printf("\33[0;3%dm\033[4%dm\033[4;3%dmHello World\n", randomnumber, randomnumber + 1 % 8, randomnumber + 3 % 8);
    sleep(3); // Pauses program for 3 seconds
  }
}
