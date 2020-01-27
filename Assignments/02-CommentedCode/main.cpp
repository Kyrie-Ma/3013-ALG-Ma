///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           (Yuankai Ma)
// Email:            (1106935335@qq.com)
// Label:            (program's label from assignment list)
// Title:            (short title from assignment, if any)
// Course:           (CMPS 3013-201)
// Semester:         (Spring 2020)
//
// Description:
//       This program is to create to linked list and insert the value into
//       it, and add to linked list together.
//
// Usage:
//       
//
// Files:
//      Assignment-2.cpp    :main function, struct Node and the class List
/////////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

int A[100];                  //Create a array that holds 100 value in it
/**
 * Node
 *
 * Description:
 *      This is a struct called Node that has a value and a pointer to another node
 *
*Methods:
 *                   Node()
 *                   Node(int n)
 *      
 * Usage:
 *      
 */
struct Node {
    int x;
    Node* next;
    Node() 
    {
        x = -1;
        next = NULL;
    }
    Node(int n) 
    {
        x = n;
        next = NULL;
    }
};
/**
 * List
 *
 * Description:
 *      This class create a linked list and have all the function to
 *      deal with this linked list.
 *
 * Public Methods:
 *                   List()
 *      void         Push(int val)
 *      void         Insert(int val)
 *      void         PrintTail()
 *      int          Pop()
 *      List         operator+(const List& Rhs)
 *      int          operator[](int index)
 *      friend       ostream& operator<<(ostream& os, List L)
 *
 * Private Methods:
 *      
 *
 * Usage:
 *      L1 List();                                          //create a object L1 for the List
 *      L1.Push(int val);                                   //push the value into the linked list
 *      L1.Insert(int val)                                  //insert the value into the linked list
 *      L1.PrintTail()                                      //Print the tail of the linked list
 *      L1.Pop()                                            //Pop the value out of the linked list
 *      L1.operator+(const List& Rhs)                       //Overloading the operator +
 *      L1.operator[](int index)                            //Overloading the operator []
 *      L1.ostream& operator<<(ostream& os, List L)         //Overloading the operator <<
 */
class List 
{
private:
    Node* Head;
    Node* Tail;
    int Size;
public:
    /**
     * Function List:
     *      This is a constructor of this class  
     *
     * Params:
     *
     * Returns:
     *      
     */
    List() 
    {
        Head = Tail = NULL;
        Size = 0;
    }
    /**
     * Function Push:
     *      This function is to push the current value of the linked list
     *      to the next one
     *
     * Params:
     *      [int] val
     * Returns:
     *      This linked list has the value that pass into this function as
     *      as the next value.
     */
    void Push(int val) 
    {
        // allocate new memory and init node
        Node* Temp = new Node(val);
        if (!Head && !Tail) 
        {
            Head = Tail = Temp;
        }
        else 
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }
    /**
     * Function :
     *      This funtion is to insert the value that pass into this function
     *      into the linked list
     * Params:
     *      [int] val
     * Returns:
     *      This funtion is to insert the value that pass into this function
     *      into the linked list
     */
    void Insert(int val) 
    {
        // allocate new memory and init node
        Node* Temp = new Node(val);
        // figure out where it goes in the list
        Temp->next = Head;
        Head = Temp;
        if (!Tail) 
        {
            Tail = Head;
        }
        Size++;
    }
   /**
    * Function PrintTail:
            This function is to print the value of the linked list tail
    *
    * Params:
    *       
    * Returns:
    *       The value of the tail
    */
    void PrintTail() 
    {
        cout << Tail->x << endl;
    }
    /**
     * Function Print:
     *       This function is to print the value of the linked list
     * Params:
     *       
     * Returns:
     *       The linked list
     */
    string Print() 
    {
        Node* Temp = Head;
        string list;
        while (Temp != NULL) 
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }
        return list;
    }
    // not implemented
    /**
     * Function Pop:
     *       This function is to pop the value out of the linked list
     * Params:
     *
     * Returns:
     *       0
     */
    int Pop() 
    {
        Size--;
        return 0; //
    }
    /**
     * Function operator+:
     *       This function is to overloading the operator +
     * Params:
     *       [List] Rhs
     * Returns:
     *       NewList
     */
    List operator+(const List& Rhs) 
    {
        // Create a new list that will contain both when done
        List NewList;
        // Get a reference to beginning of local list
        Node* Temp = Head;
        // Loop through local list and Push values onto new list
        while (Temp != NULL) 
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }
        // Get a reference to head of Rhs
        Temp = Rhs.Head;
        // Same as above, loop and push
        while (Temp != NULL) 
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }
        // Return new concatenated version of lists
        return NewList;
    }
    /**
     * Function operator[]:
     *         This function is overloading the operator []
     * Params:
     *         [int] index
     * Returns:
     *         This function returns an int value as if the list were an array.
     */
    int operator[](int index) 
    {
        Node* Temp = Head;
        if (index >= Size) 
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else  
        {
            for (int i = 0; i < index; i++) 
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }
    /**
     * Function operator<<:
     *         This function is overloading the operator [] as friend function
     * Params:
     *         [ostream] os, [List] L
     * Returns:
     *         os
     */
    friend ostream& operator<<(ostream& os, List L) 
    {
        os << L.Print();
        return os;
    }
};



int main(int argc, char** argv) 
{
    List L1;                            // L1 is the first object created for the List
    List L2;                            // L2 is the second object created for the List
    for (int i = 0; i < 25; i++) 
    {
        L1.Push(i);                     // Call the push function for L1
    }
    for (int i = 50; i < 100; i++) 
    {
        L2.Push(i);                     // Call the push function for L2
    }
    //cout << L1 << endl;
    L1.PrintTail();                     // Call the PrintTail function for L1
    L2.PrintTail();                     // Call the PrintTail function for L2
    List L3 = L1 + L2;                  // Add L1 and L2 to L3 by call operator+ function
    cout << L3 << endl;                 // Cout the L3
    cout << L3[5] << endl;              // Cout the fifth number of L3
    return 0;
}
