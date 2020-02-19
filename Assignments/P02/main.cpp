#include <iostream>
#include <string>
#include <fstream> 
#include<iomanip>
#include <iostream>
//#include "JsonFacade.hpp"       // need to grab a copy from resources folder
#include <time.h>
#include <chrono> 
#include "Timer.hpp"   
using namespace std;


struct Node{
  string word;
  string def;
  Node* Next;
  Node(string w){
    word = w;
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

  Dictionary(){
    Start = NULL;
  }

  ~Dictionary(){
    //cout<<
  }

  void Add(string word){

    word = LowerCase(word);
    // create new memory
    Node* temp = new Node(word);
  
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

  void Add2(string def){

    def = LowerCase(def);
    // create new memory
    Node* temp = new Node(def);
  
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

   Start = NewList;


  }

  void Print(){
    ofstream outfile;
    outfile.open("output.txt");
    Node* temp = Start;
    while(temp){
      outfile<<temp->word;
      if(temp->Next){
        outfile<<"->";
      }
      temp = temp->Next;
    }
    outfile<<endl;
  }

  void test(){
    Node* temp = Start;
    cout << temp->word;
  }


};
/////////////////////////////////////////////////////

int main() {
  Dictionary *W;

  W = new Dictionary;

  ifstream fin("test.txt");
  string word;
  string def;
  ofstream outfile;
  outfile.open("output.txt");
Timer T;
    T.Start();
   
    //T.Sleep(1500); //milliseconds
  while(fin>>word){
    W->Add(word);
    //W->Add2(def);
    //W->test();
  }
    T.End(); 

    double s = T.Seconds();
    //long m = T.MilliSeconds();

    outfile <<s << " seconds" <<endl;
    //outfile <<m << " milli" <<endl;


  //W.Add("Ant");
  //W->Add("Dog");
  //W.Add("Aaron");
  //W.Add("Aardvark");
  //W->Add("Cow");
  //W.Add("Rabbit");


  //W->Print();

  //W->ReOrder();

  //W->Print();

  delete W;
  //outfile.close();
}