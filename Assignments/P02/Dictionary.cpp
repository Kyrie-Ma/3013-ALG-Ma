///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Yuankai Ma
// Email:            1106935335@qq.com
// Title:            Dictionary.cpp
//
// Description:
//          This class is to create a linked list to store all the words and 
//            the definitions from the json infile, and create a vector to 
//            store the word found start from the keyboard input
//          
// Usage:
//          
//      
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
using namespace std;

struct Node{
  string word;
  string defs;
  Node* Next;
  Node(string w,string d){
    word = w;
    defs = d;
    Next = NULL;
  }
};

class Dictionary {
private:
  Node* Start;

  string LowerCase(string input){
    for(int i=0;i<input.length();i++){
      if((int)input[i] < 96){
        input[i] += 32;
      }
    }
    return input;
  }


public:
  //vector store all the words fit the input
  vector <string> vWords;   
       
 /**
  * Dictionary(): constructor that create a linked list
  * 
  * Params:
  *      
  */
  Dictionary(){
    Start = NULL;
  }

 /**
  * Dictionary(): destructor
  * 
  * Params:
  *      
  */
  ~Dictionary(){
    //cout<<
  }

 /**
  * ADD(): add the words and definitions from the infile to the linked list
  * 
  * Params:
  *      word, defs
  */
  void Add(string word,string defs){
    word = LowerCase(word);
    // create new memory
    Node* temp = new Node(word,defs);
  
    // if list is empty hook in new Node
    if(Start == NULL){
      Start = temp;
    }else{
      // get ready to walk the list
      Node* traverse = Start;
      while(traverse->Next != NULL){
        // walks the list
        traverse = traverse->Next;
      }
      // now at proper place to link in new memory
      traverse->Next = temp;
    }
  }

 /**
  * Remoe(): remove the word in the linked list (may not use this)
  * 
  * Params:
  *      key
  */
  string Remove(string key){
    string temp = "";

    if(!Start){
      return "";
    }else{
      Node* cptr = Start;
      Node* prev = Start;
      while(cptr && cptr->word != key){
        prev = cptr;
        cptr = cptr->Next;
      }
      // if cptr then we found the word
      if(cptr){
        temp = cptr->word;
        prev->Next = cptr->Next;
        delete cptr;
      }else{
        // no word, return empty
        temp = "";
      }
      return temp;
    }


    return temp;
  }

 /**
  * ReOrder(): reorder the linked list from a to z
  * 
  * Params:
  *      
  */
  void ReOrder(){
    // pointers for new list
    Node* NewList = NULL;
    Node* Tail=NULL;

    int i;

   while(Start != NULL){

    // helper pointers to manipulate lists
    Node* Ptr = Start;
    Node* Min = Start;
    Node* Prev = Start;
    Node* MinPrev = Start;
   

      // find one minimum word in old list
      while(Ptr != NULL){
        if(Ptr->word < Min->word){
          MinPrev = Prev;
          Min = Ptr;
        }

        Prev = Ptr;
        Ptr = Ptr->Next;
      }
      //end finding one word in old list

      // add one word to new list

      if(!NewList){
        NewList = Min;
      }else{
        Tail->Next = Min;
      }

      Tail = Min;
      if(MinPrev == Start){
        Start = Start->Next;
      }else{
        MinPrev->Next = Min->Next;
      }
      
      Min->Next = NULL;
      i++;

      // if(i>=6){
      //   break;
      // }
      // adding one word to new list

      // Node* Temptemptmemp = NewList;

      // while(Temptemptmemp){
      //   cout<<Temptemptmemp->word<<" ";
      //   Temptemptmemp = Temptemptmemp->Next;
      // }
      // cout<<endl;
   }

   //Start = NewList;


  }

 /**
  * Print(): print all the words and defs
  * 
  * Params:
  *      
  */
  void Print(){
    Node* temp = Start;
    while(temp){
      cout<<temp->word << endl;
      cout<< temp->defs << endl;
      if(temp->Next){
        cout<<"->";
      }
      temp = temp->Next;
    }
    cout<<endl;
  }

 /**
  * findWords: find the words that start by the character that keyboard input
                 and store them in to a vector
  * 
  * Params:
  *      str, count
  */
  void findWords(string str,int count){
    Node* temp = Start;
    int count1 = 0;                   //number that the character of words equal to input
    while(temp != NULL){
      for(int i = 0; i< count; i++){
        if(temp->word[i] == str[i])
        {
          count1++;
        }
      }
      if(count1 == count){
        vWords.push_back(temp->word);  // store the word that fit the input into vector
      }
      temp = temp->Next;
      count1 = 0;
    }
  }

 /**
  * wordNum: return the size of the vector
  * 
  * Params:
  *      
  */
  int wordNum(){
    return vWords.size();
  }

 /**
  * tenWords(): cout the first up to 10 words in vector
  * 
  * Params:
  *      
  */
  void tenWords(){
    if(vWords.size()<10){
        for(int i=0;i<vWords.size();i++){
          cout << "[ "<< vWords[i] << " ] " ;
      }
    }
    else{
      for(int i=0;i<10;i++){
        cout << "[ " << vWords[i] << " ] ";
      }
    }
    cout << endl;
  }

 /**
  * Delete(): delete all elements in the vector
  * 
  * Params:
  *      
  */
void Delete(){
    vWords.clear();
  }
};
