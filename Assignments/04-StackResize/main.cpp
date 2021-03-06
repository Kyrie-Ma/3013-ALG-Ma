/*

        ######    ###     #           
        #     #  #   #   ##           
        #     # #     # # #           
        ######  #     #   #           
        #       #     #   #           
        #        #   #    #           
        #         ###   #####         
                                      
         #####    ###     #    #####  
        #     #  #   #   ##   #     # 
              # #     # # #         # 
         #####  #     #   #    #####  
              # #     #   #         # 
        #     #  #   #    #   #     # 
         #####    ###   #####  #####  
                                      
        #     #                       
        ##   ##   ##                  
        # # # #  #  #                 
        #  #  # #    #                
        #     # ######                
        #     # #    #                
        #     # #    #                

*/

///////////////////////////////////////////////////////////////////////////////
//
// Author:           Yuankai Ma
// Label:            L01
// Title:            Lecture 01 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/**
 * ArrayStack
 * 
 * Description:
 *      Array based stack
 * 
 * Public Methods:
 *      - See class below
 * 
 * Usage: 
 *      - See main program
 *      
 */
class ArrayStack{
private:
  int *A;           // pointer to array of int's
  int size;         // current max stack size
  int top;          // top of stack 
  int counter1;     // time of stack resize
public:
 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor no params
  * 
  * Params:
  *     - None
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(){
    size = 10;
    A = new int[size];
    top = -1;
    counter1 = 0;
  }

 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor size param
  * 
  * Params:
  *     - int size
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(int s){
    size = s;
    A = new int[s];
    top = -1;
    counter1 = 0;
  }

 /**
  * Public bool: Empty
  * 
  * Description:
  *      Stack empty?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = empty
  */
  bool Empty(){
    return (top <= -1);
  }
  
 /**
  * Public bool: Full
  * 
  * Description:
  *      Stack full?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = full
  */
  bool Full(){
     return (top >= size - 1);
  }

 /**
  * Public int: Peek
  * 
  * Description:
  *      Returns top value without altering the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Peek(){
    if(!Empty()){
      return A[top];
    }
    
    return -99; // some sentinel value
                // not a good solution
  }

 /**
  * Public int: Pop
  * 
  * Description:
  *      Returns top value and removes it from stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Pop(){
    if(Empty()){
      return -200; //sentinel value
    }
    else{
      if(top<=(size*0.5-1)){
      CheckResize();
      }
      return top--;
    }
  }

 /**
  * Public void: Print
  * 
  * Description:
  *      Prints stack to standard out
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void Print(){
    for(int i=0;i<=top;i++){
      cout<<A[i]<<" ";
    }
    cout<<endl;
  } 

 /**
  * Public bool: Push
  * 
  * Description:
  *      Adds an item to top of stack
  * 
  * Params:
  *      [int] : item to be added
  * 
  * Returns:
  *      [bool] ; success = true
  */
  bool Push(int x){
    if(Full()){
      CheckResize();
    }
    if(!Full()){
      A[++top] = x;
      return true;
    }
    return false;
  }

 /**
  * Public void: ContainerGrow
  * 
  * Description:
  *      Resizes the container for the stack by time 1.75 of
  *      its capacity if the stack is full
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void ContainerGrow(){
    int newSize = size*1.75;       // double size of original
    int *B = new int[newSize];  // allocate new memory

    for(int i=0;i<size;i++){    // copy values to new array
      B[i] = A[i];
    }

    delete [] A;                // delete old array

    size = newSize;             // save new size

    A = B;                      // reset array pointer

  }

 /**
  * Public void: ContainerShrik
  * 
  * Description:
  *      Resizes the container for the stack by time 0.5 of
  *      its capacity if top is smaller than half of its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void ContainerShrik(){
    int newSize = size*0.5;       // double size of original
    int *B = new int[newSize];  // allocate new memory

    for(int i=0;i<size;i++){    // copy values to new array
      B[i] = A[i];
    }

    delete [] A;                // delete old array

    size = newSize;             // save new size

    A = B; 
  }

 /**
  * Public void: CheckResize
  * Description:
  *      Check the stack is full or there is half of the stack
  *      are unless, and keep counting the number of resize
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void CheckResize(){
      if(Full()){
          ContainerGrow();
          counter1++;
      }
      else if(top<=(size*0.5-1)){
        if(!Empty()){
          ContainerShrik();
          counter1++;
        }
      }
  }

 /**
  * Public int: getCounter
  * Description:
  *      Get the counter of how many times that stack change
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      times of stack resize
  */
  int getCounter(){
    return counter1;
  }
};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
  ArrayStack stack;
  ifstream infile;                            
  ofstream outfile;
  infile.open("nums.dat");               //read infile
  outfile.open("outfile.txt");           //create outfile
  int x;                                 //infile data
  int counter = 0;                       //count the final size of stack
  int counterMax = 0;                    //count the max size of stack
  while(!infile.eof()){
    infile >> x;
    //stack.CheckResize();                 //check if stack need to resize
    if(x%2==0){
        stack.Push(x);                   //push the data in the infile to the stack
        counter++;
    }
    else if(x%2!=0){
        stack.Pop();                     //pop the stack value out of stack
        counter--;
    }
    if(counter > counterMax){
      counterMax = counter;
    }
    else if(counter <= 0){
      counter = 0;
    }
  }
  outfile << "######################################################################\n\n";
  outfile << "    Assignment 4 - Resizing the Stack\n";
  outfile << "    CMPS 3013\n";
  outfile << "    Yuankai Ma\n\n";
  outfile << "    Max Stack Size: " << counterMax << endl;
  outfile << "    End Stack Size: " << counter << endl;
  outfile << "    Stack Resize: " << stack.getCounter() << " times\n\n";
  outfile << "######################################################################\n";
  
  infile.close();
  outfile.close();
  return 0;
}