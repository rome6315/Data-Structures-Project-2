//The goal of this project is to take a base ten integer entered by the user and convert it to hex. This process will continue until the user prompts the program to terminate.
//Written by Roman Morasco
//On 10/10/2022

#include <iostream>
#include "lststack.h"

//Given: A base ten integer entered by the user and the stack variable
//Task: Calculate the remainders and push them onto the stack
//Return: Nothing is returned, however, the stack is now populated
void stackFunction(int baseTen, LstStackClass &stackk);

//Given: The stack variable
//Task: Pop the items off the stack and convert them to hexadecimal format when necessary
//Return: Nothing is returned, however, the stack is now empty and the output is displayed
void popItemsOffStack(LstStackClass &stackk);

//Given: The remainder that was popped off the stack
//Task: Convert any remainder >= 10 to its correspondign hexadecimal letter
//Return: The converted remiander is returned to the popItemsOffStack function to display for output
std::string convertToLetter(float remainder);

//Given: nothing
//Task: Get a users input for a base ten integer
//Return: The users input is returned and assigned to the variable in main
float getUserInput();

int main(void) {
   int userKeepGoing = 0; //exit condition for while loop
   LstStackClass stack; //declare stack variable

   while(userKeepGoing == 0) {
   int num = getUserInput(); //get users input
   stackFunction(num, stack); //get remainders and push onto stack
   popItemsOffStack(stack); //display output in hex

   //ask user if they want to input another base ten integer
   std::cout << "Would you like to enter another base ten integer to convert? Enter 0 for yes and 1 for no: ";
   std::cin >> userKeepGoing;
   std::cout << std::endl; //whitespace
   }


   return  0;
}


void stackFunction(int baseTen, LstStackClass &stackk) {
   int quotient = baseTen; //set quotient equal to the users input
   int remainder = 0; //intitialize remainder
   
   do{
      remainder = quotient%16; //get remainder
      quotient  = quotient/16; //get next quotient

      stackk.Push(remainder); //push remainder to stack
      
   }while(quotient != 0); //exit condition
}

void popItemsOffStack(LstStackClass &stackk) {
   float item = 0; //initialize variable 
   std::string hexx = "Yo"; //initialize variable

   std::cout << "Result: "; //output

   while(!stackk.Empty()) {
   stackk.Pop(item); //pop item off list

   //convert the remiander to hex if it is greater than or equal to 10
   if(item >= 10) {
      hexx = convertToLetter(item);
      std::cout << hexx;
   }
   
   //if its less than 10, just display the remainder
   else {
   std::cout << item;
   }
   }
   std::cout << std::endl; //whitespace in output
}

std::string convertToLetter(float remainder) {
   std::string hexx = "Yo"; //initialize the string variable

   if(remainder == 10) {
      return "A";
   }
   if(remainder == 11) {
      return "B";
   }
   if(remainder == 12) {
      return "C";
   }
   if(remainder == 13) {
      return "D";
   }
   if(remainder == 14) {
      return "E";
   }
   if(remainder == 15) {
      return "F";
   }

   return "error"; //if remainder is out of scope
}

float getUserInput() {
   float userInput = 0; //initialize variable

   //prompt user for base ten number
   std::cout << "Enter a base ten number of your choice: ";
   std::cin >> userInput;

   return userInput; 
}
