///////////////////////////////////////////////////////////////////////////////
//
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
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
    return (top >= size-1);
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
    if(!Empty()){
      return A[top--];
    }

    return -99; // some sentinel value
                // not a good solution
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
  void Push(int x){
    if(!Full()){
      A[++top] = x;
    }
  }

 /**
  * Public void: Resize
  * 
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
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


  int CheckResize(){
    int counter1 = 0;
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
      return counter1;
  }
};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
  ArrayStack stack;
  int r = 0;
  ifstream infile;
  infile.open("num.dat");
  ofstream outfile;
  outfile.open("outfile.txt");
  int x;
  int counter = 0;
  int counterMax = 0;
  while(infile>>x){
    stack.CheckResize();
    if(x%2==0){
        stack.Push(x);
        counter++;
    }
    else if(x%2!=0){
        stack.Pop();
        counter--;
    }
    if(counter > counterMax){
      counterMax = counter;
    }
    if(counter <= 0){
      counter = 0;
    }
  }
  outfile << "######################################################################\n\n";
  outfile << "    Assignment 4 - Resizing the Stack\n";
  outfile << "    CMPS 3013\n";
  outfile << "    Yuankai Ma\n\n";
  outfile << "    Max Stack Size: " << counterMax << endl;
  outfile << "    End Stack Size: " << counter << endl;
  outfile << "    Stack Resize: " << stack.CheckResize() << " times\n\n";
  outfile << "######################################################################\n";
  infile.close();
  outfile.close();
  return 0;
}