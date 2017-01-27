/******************************************
 *
 *
 *   File: rpn.c
 *   Author: Michael McCann
 *   School: Indiana University
 *   Assignment: HW0
 *   Part of: Homework
 *   Description: Calculator for binary operators
 *   Date Created: 01/26/2017
 *   Date Modified: 01/26/2017
 *   Modified By: Michael McCann
 *
 *   Revision Description:  Fixed small bugs
 *      - divide by 0
 *      - stack not being fully cleared
 *      - crash when try to clear twice in a row
 *      - if stack is empty pull now returns 0 instead of null
 */

#include <stdio.h>

// Defines a new structure to hold
// a value and a link to the next element.
typedef struct CELL *LIST;
struct CELL {
  int val;
  LIST next;
};

// creates a global variable to 
static LIST stack;

/*****************
 *   clear
 *
 *   Input: N/A
 *   Assumptions of input: N/A
 *   Guarantees about output: Clears entire stack
 *   Description: Goes through all items in the stack
 *      and sets temp to next in stack and frees stack
 *      then sets stack to the temp stack
 *
 */
void clear(){
  LIST c = (LIST) malloc(sizeof(struct CELL));// allows saving a temp stack
  while(stack){// will keep looping while stack isnt empty
    c = stack->next;// sets the temp stack to the next in the stack
    free(stack);// clears the memory of top element in the stack
    stack = c;// sets the stack to its next, the temp stack
    // to loop until all are cleared
  }
}

/*****************
 *   printfull
 *
 *   Input: N/A
 *   Assumptions of input: N/A
 *   Guarantees about output: Prints the items in the stack
 *   Description: Goes through all items in the stack
 *      and prints them each on their own line.  If it
 *      is empty, it prints that is is empty instead.
 *
 */
void printfull(){
  // checks to see if stack is empty
  // if it is it prints that it is empty
  // then returns
  if(!stack){// checks if the stack isnt empty, null
    printf("The Stack is empty\n");
    return;
  }
  // used to store temp stack
  LIST c = (LIST) malloc(sizeof(struct CELL));
  c = stack;
  // used to go through all the elements in the stack
  //  will not hit last
  while(c->next){
    printf("%d\n",c->val);
    c = c->next;
  }
  //  Used to print the last item in the stack.
  if(stack){
    printf("%d\n", c->val);
  }
}

/*****************
 *   pull
 *
 *   Input: N/A
 *   Assumptions of input: N/A
 *   Guarantees about output: returns the top item in the stack
 *   Description: used to pull the top item crom the stack
 *      Will modify the stak to now be the next item.
 *
 */
int pull(){
  if(!stack){
    return 0;
  }
  int num = stack->val;
  LIST c = (LIST) malloc(sizeof(struct CELL));
  c = stack->next;
  free(stack);
  stack = c;
  return num;
}

/*****************
 *   push
 *
 *   Input: int
 *   Assumptions of input: integer that wont be
 *      too big to cause the int to go over the max value
 *   Guarantees about output: adds the value to the stack
 *   Description: used to push new elements to the stack.
 *      if the stack is empty, it creates a new one.
 *
 */
void push(int val){
  // used as a temp stack
  LIST c = (LIST) malloc(sizeof(struct CELL));
  if(c){
    // sets temp stack val to input
    c->val = val;
    // sets the next to the stack, making it on top of the stack
    c->next = stack;
    // sets the stack to the temp, adding the value given
    stack = c;
  } else{ printf("error occurred in push\n"); }
}

/*****************
 *   main
 *
 *   Input: N/A
 *   Assumptions of input: N/A
 *   Guarantees about output: N/A
 *   Description: Calculator.  Each number can be used
 *      with the binary operators +, -, *, and /
 *      it will be used in order "next operator top"
 *
 */
int main(){
  printf("Max input size allowed is 99 characters, all others are ignored\n");
  char str[100];// used to store text input
  int i = 0;// used to increment the str array
  int num = 0;// used when adding new number to stack, or pulling from stack
  int numTwo;// used when pulling from the stack
  int quit = 1;// used to stop the loop
  while(quit){
    scanf("%99s",&str);//allows user input, limits to 99 chars
    while(str[i]){// goes until null character is found
      if(isdigit(str[i])){//checks if it is a digit.
	num = atoi(&str[i]);//used to extract the number
	push(num);// pushes number to stack
	while(isdigit(str[i])){// increments through the rest of the number
	  i++;
	}
      }
      switch((int) str[i]){// checks char for specified operators and special letters.
      case '+': numTwo = pull();
	num = pull();
	push(num + numTwo);
	break;
      case '-': numTwo = pull();
	num = pull();
	push(num - numTwo);
	break;
      case '*':numTwo = pull();
	num = pull();
	push(num * numTwo);
	break;
      case '/':numTwo = pull();
	num = pull();
	//used to avoid divide by 0
	if(!numTwo){// checks if second number, first pulled is 0.
	  printf("ERR divide by 0, not changing stack\n");
	}else{
	  push(num / numTwo);
	}
	break;
      case 'p':
	if(!stack){// checks if stack is empty, null
	  printf("The Stack is empty\n");
	}else {
	  printf("Top element is %d\n", stack->val);
	}
	break;// prints the top element in the stack.
      case 'f': printf("Printing entire stack\n"); 
	printfull();// prints all elements in the stack
	break;
      case 'c':clear(); // clears the stack
      	break;
      case 'q': quit = 0;
	clear();
	break;// quits the program
      }
      i++;
    } 
    for(i = 0;i < 100; i++){
      str[i] = '\0';
    }// reseets the array to null character so it cant use old data
    i = 0;// resets incrementor
  }
  return 0;
}

