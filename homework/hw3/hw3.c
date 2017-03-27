// Luke Feetterer helped with test case file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// when a comment of multiple "//" happens it is end of that set
int main() {
  int inst;
  int rm, rn, rd;
  printf(".text\n");
  printf(".syntax unified\n");
  printf(".thumb\n");
  while((scanf("%x", &inst) == 1)) {
    //check for section 2
    if((inst >> 11) < 0b1000){
      //add/sub reg&imm
      if(inst >> 13 == 0b000){
	//add/sub imm
	if((inst >> 10) & 1){
	  //subs
	  if((inst >> 9) & 1){
	    rm = (inst >> 6) & 0b111;
	    rn = (inst >> 3) & 0b111;
	    rd = inst & 0b111;
	    printf("\tsubs r%d, r%d, #%d\n", rd, rn, rm);
	  }//end subs
	  //adds
	  else{
	    rm = (inst >> 6) & 0b111;
	    rn = (inst >> 3) & 0b111;
	    rd = inst & 0b111;
	    printf("\tadds r%d, r%d, #%d\n", rd, rn, rm);
	  }//end adds
	}//end add/sub imm

	///////////////////////////////////////////////////////////////////

	//add/sub reg
	else{
	  if((inst >> 9) & 1){//subs
	    rm = (inst >> 6) & 0b111;
	    rn = (inst >> 3) & 0b111;
	    rd = inst & 0b111;
	    printf("\tsubs r%d, r%d, r%d\n", rd, rn, rm);
	  }else{//adds
	    rm = (inst >> 6) & 0b111;
	    rn = (inst >> 3) & 0b111;
	    rd = inst & 0b111;
	    printf("\tadds r%d, r%d, r%d\n", rd, rn, rm);
	  }// end adds
	}// end add/sub reg

	////////////////////////////////////////////////////////////////////

	//Add/sub/comp/mov imm
      }else if(inst >> 13 == 0b001){
	//check first bit of opcode
	// first bit 1
	if((inst  >> 12) & 0b1){
	  // check second bit of opcode
	  // second bit 1
	  if((inst >> 11) & 0b1){
	    //sub imm
	    rn = (inst >> 8) & 0b111;
	    rd = inst & 0b11111111;
	    printf("\tsubs r%d, #%d\n", rn, rd);
	  }
	  // second bit 0
	  else{
	    // add imm
	    rn = (inst >> 8) & 0b111;
	    rd = inst & 0b11111111;
	    printf("\tadds r%d, #%d\n", rn, rd);
	  }
	}//end first bit 1
	//first bit 0
	else{
	  // check second bit of opcode
	  // first bit 1
	  if((inst >> 11) & 0b1){
	    // cmp imm
	    rd = (inst >> 8) & 0b111;
	    rm = inst & 0b11111111;
	    printf("\tcmp r%d, #%d\n", rd, rm);
	  }// end second bit 1
	  // second bit 0
	  else{
	    //mov imm
	    rd = (inst >> 8) & 0b111;
	    rm = inst & 0b11111111;
	    printf("\tmovs r%d, #%d\n", rd, rm);
	  }
	}// end first bit 0
      }//end Add/sub/comp/mov imm
    }//end first section 

    //////////////////////////////////////////////////////////////

    // check if data-processing registar
    else if(inst >> 10 == 0b010000){
      // check first bit of opcode
      // first bit 1
      if(inst >> 9 & 0b1){
	// check second bit
	// second bit 1
	if(inst >> 8 &0b1){
	  // check third bit
	  // third bit 1
	  if(inst >> 7 & 0b1){
	    // check fourth bit
	    // fourth bit 1
	    if(inst >> 6 & 0b1){
	      // move negative
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\tmvns r%d, r%d\n", rn, rm);
	    }// end fourth bit 1
	    // fourth bit 0
	    else{
	      // bit clear
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\tbics r%d, r%d\n", rn, rm);
	    }// end fourth bit 0
	  }// end third bit 1
	  // third bit 0
	  else{
	    // check fourth bit
	    // fourth bit 1
	    if(inst >> 6 & 0b1){
	      // multiply
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\tmuls r%d, r%d, r%d\n", rn, rm, rn);
	    }// end fourth bit 1
	    // fourth bit 0
	    else{
	      // logical or
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\torrs r%d, r%d\n", rn, rm);
	    }// end fourth bit 0
	  }// end third bit 0
	}// end second bit 1
	// second bit 0
	else{
	  // check third bit
	  // third bit 1
	  if(inst >> 7 & 0b1){
	    // check fourth bit
	    // fourth bit 1
	    if(inst >> 6 & 0b1){
	      // compare negative
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\tcmn r%d, r%d\n", rn, rm);
	    }// end fourth bit 1
	    // fourth bit 0
	    else{
	      // compare
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\tcmp r%d, r%d\n", rn, rm);
	    }// end fourth bit 0
	  }// end third bit 1
	  // third bit 0
	  else{
	    // check fourth bit
	    // fourth bit 1
	    if(inst >> 6 & 0b1){
	      //reverse subtract
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\trsbs r%d, r%d, #0\n", rn, rm);
	    }// end fourth bit 1
	    // fourth bit 0
	    else{
	      // test
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\ttst r%d, r%d\n", rn, rm);
	    }// end fourth bit 0
	  }// end third bit 0
	}// end second bit 0
      }// end first bit 1
      // first bit 0
      else{
	// check second bit
	// second bit 1
	if(inst >> 8 &0b1){
	  // check third bit
	  // third bit 1
	  if(inst >> 7 & 0b1){
	    // check fourth bit
	    // fourth bit 1
	    if(inst >> 6 & 0b1){
	      // rotate right
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\trors r%d, r%d\n", rn, rm);
	    }// end fourth bit 1
	    // fourth bit 0
	    else{
	      // sub with carry
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\tsbcs r%d, r%d\n", rn, rm);
	    }// end fourth bit 0
	  }// end third bit 1
	  // third bit 0
	  else{
	    // check fourth bit
	    // fourth bit 1
	    if(inst >> 6 & 0b1){
	      //add with carry
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\tadcs r%d, r%d\n", rn, rm);
	    }// end fourth bit 1
	    // fourth bit 0
	    else{
	      // arithmetic shift right
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\tasrs r%d, r%d\n", rn, rm);
	    }// end fourth bit 0
	  }// end third bit 0
	}// end second bit 1
	// second bit 0
	else{
	  // check third bit
	  // third bit 1
	  if(inst >> 7 & 0b1){
	    // check fourth bit
	    // fourth bit 1
	    if(inst >> 6 & 0b1){
	      // logical shift right
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\tlsrs r%d, r%d\n", rn, rm);
	    }// end fourth bit 1
	    // fourth bit 0
	    else{
	      // logical shift left
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\tlsls r%d, r%d\n", rn, rm);
	    }// end fourth bit 0
	  }// end third bit 1
	  // third bit 0
	  else{
	    // check fourth bit
	    // fourth bit 1
	    if(inst >> 6 & 0b1){
	      // bitwise xor
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\teors r%d, r%d\n", rn, rm);
	    }// end fourth bit 1
	    // fourth bit 0
	    else{
	      // bitwise and
	      rm = (inst >> 3) & 0b111;
	      rn = inst & 0b111;
	      printf("\tands r%d, r%d\n", rn, rm);
	    }// end fourth bit 0
	  }// end third bit 0
	}// end second bit 0
      }// end first bit 0
    }
    // not found
    else{
      printf("\t.hword 0x%x\n", inst);
    }// end not found
  } // end while loop
  return 0;
}
