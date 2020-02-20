#include <iostream>
#include <time.h>
#include <chrono> 
#include <vector>
#include "Timer.hpp"                                              // need to grab a copy from resources folder
#include "JsonFacade.hpp"                                         // need to grab a copy from resources folder
#include "Dictionary.cpp"                                         // need to grab a copy from resources folder
#include "mygetch.hpp"                                            // need to grab a copy from resources folder
using namespace std;

int main(){
    Timer T;
    Dictionary D;
    JsonFacade J("dict_w_defs.json");                             // create instance of json class               
    string key;
    string defs;                                                  // key variable to access json object
    int count=0;                                                  // number of character that input
    vector<string> keys = J.getKeys();                            //create a vector to store the words from infile
    cout << "Yuankai MA\n";
    cout<<"Number of the words in the infile is " <<keys.size()<<endl;
    for(int i = 2; i < keys.size(); i++){                         //store all words and defs into linked list
      key = (J.getKey(i));
      defs = (J.getValue(key));
      D.Add(key,defs);
    }

    char k;                                                       // holder for character being typed
    string Word = "";                                             // var to concatenate letters to
    cout<<"Type keys and watch what happens. Type capital Z to quit."<<endl;
    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z') {                                
        Word += k;                                                // append char to word
        if((int)k != 10){                                         // if k is not a space print it
            cout << "Key: " << k << endl;
            cout << "Word: " << Word << endl;
            while(Word[count] != '\0'){
              count++;
            }
            T.Start();                                            //calculate time start
            D.findWords(Word,count);
            T.End();                                              //calculate time stop
            double s = T.Seconds();
            cout << D.wordNum() << " words is found in " << s << " seconds\n";
            D.tenWords();                                         //cout first up to 10 words
            D.Delete();                                           //delete the vector
        }

        // hitting enter sets word back to empty
        if((int)k == 10 ){
            cout<<"----------------------------------------------------------------------\n\n";
            cout<<"Enter pressed ... refinding words..."<<endl;
            Word = "";
            count =0;
            cout<<"Type keys and watch what happens. Type capital Z to quit."<<endl << endl;
        }
    }
}
