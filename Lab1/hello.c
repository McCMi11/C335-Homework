#include <stdio.h>

int main(){
  while(1){
    int randomnumber;
    randomnumber = rand() % 10;
    printf("\33[0;3%dm\033[4%dm\033[4;3%dmHello World\n", randomnumber, randomnumber + 1 % 10, randomnumber + 3 % 10);
    sleep(3);
  }
}
