omputer Science > John Winans > CSCI 501 > Assignment 4
Assignment 4: Simplesim (20 points/\(.\{80\}.\{-}\s\)/\1\r/g


Thion 
in order to proceed to the next!

We start by "peeling open" a computer, look at its internal structure, and introducing machine language (assembler-level) programming. Your assignment is to write a program that simulates a computer, one that is capable of executing machine language programs.
Description of the Simplesim Computer

In this assignment you will write a program to simulate a fictional computer that we will call the Simplesim. As its name implies it is a simple machine. All information in the Simplesim is handled in terms of words. A word is a signed four-digit decimal (base 10) number such as +3364, -1293, +0007, -0001, 0000, etc. The Simplesim is equipped with memory and five registers.

    The Simplesim has a 100-word memory and these words are referenced by their location numbers 00, 01, . . . , 99. Each word in the Simplesim's memory (always a single signed four-digit decimal number) may be interpreted as an instruction to be executed, a data value, or may be uninitialized.
		
		    The first register is the accumulator, which is just large enough to hold a single word. Words from memory must be placed into the accumulator in order to perform arithmetic on them or test their values. All arithmetic and branching is done using the accumulator.
				
				    The second register is the instruction counter, which is just large enough to hold a memory location (a two digit number, 00, 01, ... , 99). The instruction counter is used to hold the memory location of the next instruction to be executed.
						
						    The third register is the instruction register, which, like the accumulator, is just large enough to hold a single word. The instruction register is used to hold a copy of the instruction (a word that was pulled out of memory) that is currently being executed.
								
								    The fourth and fifth registers are the operation code and operand, respectively. Each one is just large enough to hold half of a word (a two digit decimal number). The operation code and operand registers are used to "split" the instruction register in half, with the 2 leftmost digits and sign of the instruction register going into the operation code and the 2 rightmost digits going into the operand. For example, if the instruction register had +1009 then the operation code would have +10 and the operand would have 09. Likewise, if the instruction register had -1201, the operation code would have -12 and the operand would have 01.
										
										The Simplesim Machine Language (SML)
										
										Each instruction written in the Simplesim Machine Language (SML) occupies one word of the Simplesim's memory (and hence instructions are signed four-digit decimal numbers). The two leftmost digits of each SML instruction are the operation code (opcode), which specifies the operation to be performed. The two rightmost digits of an SML instruction are the operand, which is the memory location containing the word to which the operation applies. The complete set of SML instructions is described in the table that follows.
										Operation Code 	Meaning
										Input / Output Operations:
										READ 01 	Read a word into a specific memory location.
										WRITE 02 	Print a word from a specific memory location.
										Store / Load Operations:
										STORE 11 	Store the word in the accumulator into a specific memory location.
										LOAD 12 	Load a word from a specific memory location into the accumulator.
										Arithmetic Operations:
										ADD 21 	Add a word in a specific memory location to the word in the accumulator (leave result in accumulator).
										SUBTRACT 22 	Subtract a word in a specific memory location from the word in the accumulator (leave result in accumulator).
										MULTIPLY 23 	Multiply a word in a specific memory location by the word in the accumulator (leave result in accumulator).
										DIVIDE 24 	Divide a word in a specific memory location into the word in the accumulator (leave result in accumulator).
										Transfer of Control Operations:
										BRANCH 31 	Branch to a specific memory location.
										BRANCHZERO 32 	Branch to a specific memory location if the accumulatos it in the memory location defined by the operand, in this case rams will "partition" the Simplesim's memory in this way. The first words of memory (always starting at memory location 00) are 307 (BRANCHNEG) is a conditional branch instruction, much like an "if" statement in C++. All conditional branch instructions are based on the accumulator. The BRANCH instruction, which acts like a "goto", is the only branch instruction that ignores thetion of the program from wandering into the "data" portion of t simplesim and the name of the SML program file above is sum.sml, then the output of your program must look exactly like this:
										
										z123456@turing:~/csci501/Assign4$ ./simplesim < sum.sml
										READ: -0005
										READ: +0015
										+0010
										*** Simplesim execution terminated ***
										REGISTERS:
										accumulator:            +0010
										instruction_counter:    06
										instruction_register:   +3400
										operation_code:         34
										im's 100-word memory or a line of the input file may not fit into a word (i.e., it may be greater than 9999 or less than -9999). In these situations your program must print an error message, dump the contents of the machine, and terminate. It must not han 9999.
										Files You Must Write
										
										You will need to write three files for this assignment:
										
										    simplesim.h - This header file must contain the class definition for a class called simplesim. This class definition must contain the private data members described below under Simulating the Simplesim and an enumeration tsimplesim::execute_program()
												
												        This member function executes an SML program in the Simplesim's memory, as described under Execute SML Program. It takes no arguments and returns nothito the next step.
																        Call dump() on the simplesim object to dump its registers and memory.
																				
																				Simulating the Simplesim
																				
																				Among other things, your simplesim class will provide the definition of an enum that you will use to define the instruction operation codes (op codes.) It may be a public member of the class dncounter an invalid word (other than -99999 which denotes the end of the program) during the program load, your program must stop loading immediately, print the appropriate error message from the table above, and return false.
																				
																				    Also, if in the course of loading the program you run out of Simplesim's memory - i.e., an SML program that is more than 100 words - your program must stop loading immediately, print the appropriate error message from the table above, and return false.
																						
																						    If the program is successfully loaded with no errors, return true.
																								    Execute SML Program
																										
																										    Assuming a successful SML program load, the struction_counter register to point to the next instruction in  9999, inclusive), then place it into memory and print a line of output. For example, after reading the value -5 and placing it into memory, your program must print the following line:
																												
																												        READ: -0005
																																
																																        If the value read was not a "valid" word, then you must print the appropriate error message from the previous table, do not attempt to place the word in memory, and return. The program will then proceed directly to the dump phase.
																																				
																																				        WRITE. Print the word in memory from the locationis simply stops the execution of the SML program, and prints th     8     9
																																								    00 +4444 +4444 +4444 +4444 +4444 +4444 +4444 +You
																																										In addition to the example test program shown in the input  +4444 +4444 
																																										80 +4444 +4444 +4444 +4444 +4444 +4444 +4444 +44444 +4444 +4444 +4444 +4444 +4444 +4444 +4444 
																																										
																																										You must test yorite this assignment, it's a good idea to get this done correctted in loading valid words. It does not check if the program thver, it is not conceptually difficult. This portion of the code is essentially a while loop with two parts inside: instruction fetch followed by instruction execution. The instruction execution is essentially a large switch statement in which each case to your switch statement. Be sure that you check for overflow and underflow in your ADD instruction. If the result of the ADD underflow/overflow cases covered. Make sure that your program b
																																										Computer Science > John Winans > CSCI 501 > Assignment 4
																																										Assignment 4: Simplesim (20 points)
																																										
																																										This assignment is the first in a sequence. You must complete each part of the sequence in order to proceed to the next!
																																										
																																										We start by "peeling open" a computer, look at its internal structure, and introducing machine language (assembler-level) programming. Your assignment is to write a program that simulates a computer, one that is capable of executing machine language programs.
																																										Description of the Simplesim Computer
																																										
																																										In this assignment you will write a program to simulate a fictional computer that we will call the Simplesim. As its name implies it is a simple machine. All information in the Simplesim is handled in terms of words. A word is a signed four-digit decimal (base 10) number such as +3364, -1293, +0007, -0001, 0000, etc. The Simplesim is equipped with memory and five registers.
																																										
																																										    The Simplesim has a 100-word memory and these words are referenced by their location numbers 00, 01, . . . , 99. Each word in the Simplesim's memory (always a single signed four-digit decimal number) may be interpreted as an instruction to be executed, a data value, or may be uninitialized.
																																												
																																												    The first register is the accumulator, which is just large enough to hold a single word. Words from memory must be placed into the accumulator in order to perform arithmetic on them or test their values. All arithmetic and branching is done using the accumulator.
																																														
																																														    The second register is the instruction counter, which is just large enough to hold a memory location (a two digit number, 00, 01, ... , 99). The instruction counter is used to hold the memory location of the next instruction to be executed.
																																																
																																																    The third register is the instruction register, which, like the accumulator, is just large enough to hold a single word. The instruction register is used to hold a copy of the instruction (a word that was pulled out of memory) that is currently being executed.
																																																		
																																																		    The fourth and fifth registers are the operation code and operand, respectively. Each one is just large enough to hold half of a word (a two digit decimal number). The operation code and operand registers are used to "split" the instruction register in half, with the 2 leftmost digits and sign of the instruction register going into the operation code and the 2 rightmost digits going into the operand. For example, if the instruction register had +1009 then the operation code would have +10 and the operand would have 09. Likewise, if the instruction register had -1201, the operation code would have -12 and the operand would have 01.
																																																				
																																																				The Simplesim Machine Language (SML)
																																																				
																																																				Each instruction written in the Simplesim Machine Language (SML) occupies one word of the Simplesim's memory (and hence instructions are signed four-digit decimal numbers). The two leftmost digits of each SML instruction are the operation code (opcode), which specifies the operation to be performed. The two rightmost digits of an SML instruction are the operand, which is the memory location containing the word to which the operation applies. The complete set of SML instructions is described in the table that follows.
																																																				Operation Code 	Meaning
																																																				Input / Output Operations:
																																																				READ 01 	Read a word into a specific memory location.
																																																				WRITE 02 	Print a word from a specific memory location.
																																																				Store / Load Operations:
																																																				STORE 11 	Store the word in the accumulator into a specific memory location.
																																																				LOAD 12 	Load a word from a specific memory location into the accumulator.
																																																				Arithmetic Operations:
																																																				ADD 21 	Add a word in a specific memory location to the word in the accumulator (leave result in accumulator).
																																																				SUBTRACT 22 	Subtract a word in a specific memory location from the word in the accumulator (leave result in accumulator).
																																																				MULTIPLY 23 	Multiply a word in a specific memory location by the word in the accumulator (leave result in accumulator).
																																																				DIVIDE 24 	Divide a word in a specific memory location into the word in the accumulator (leave result in accumulator).
																																																				Transfer of Control Operations:
																																																				BRANCH 31 	Branch to a specific memory location.
																																																				BRANCHZERO 32 	Branch to a specific memory location if the accumulo store the program's variables and temporary results.
																																																				
																																																				All SML is printed and the program terminates.
																																																				
																																																				Note how the SML program is written. It "partitions" the Simplesim's memory into two cuted, your program must print the following line:
																																																				
																																																				*** Simplesim execution terminated ***
																																																				
																																																				At the end of any execution your program must dump the entire contents of the Simplesim. This means dumping the contents of all five registers and all 100 wordsocessing stops immediately. An example of this is an attempt topublic declarations (i.e., prototypes) for the four member functions whose definitions are contained in simplesim.cpp (described below). The header file must have an appropriate set of header guards.
																																																				
																																																				    simplesim.cpp - This source file will contain function definitions for the following four member functions of the simplesim class:
																																																						
																																																						        simplesim::simplesim()
																																																										
																																																										        Twords of memory are initialized with the value 4444. The value 4444 was chosen, in part, because the leftmost two digits (44) are not a valid instruction (...and therefore if an errant program branches to an uninitialized memory location, the program won of how each case must be processed. Some of these will be very simple (single lines in C++) and others will require more code. Although they may be listed as a single item in the list below, each SML instruction must be a single case statement within your switch.
																																																														
																																																														        READ. Attempt to read a word (from stdithose instructions (i.e., the default case of your switch statement), then your program must print the appropriate error message and return.
																																																																		    Dump Simplesim
																																																																				
																																																																				    At the end of every execution of your program (normal SML termination, SML program loadour simulator.
																																																																						Hints
																																																																						
																																																																						This is a large assignment so you might want to break it down into parts. Write part of the program, test that part thoroughly convincing yourself that it works, and then move on adding to what you've done. You might want to try t    First write just enough code to execute a program that halts itself and make sure it loads & stops right away. Then try another that does a single READ and a WRITE and then stops. These will require you to write the loop, the instruction fetch portion, and just some of the SML instructions (READ, WRITE, and HALT) in the switch statement. Your switch statement must also include the default case. Save the other SML instructions for later. Before proceeding, you should also test your code with some invalid operation codes and re-run all your prior tests to make sure they didn't stop working because something changed. Makek)))
