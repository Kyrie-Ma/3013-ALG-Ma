#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

struct node{
    string word, def;
    node *next;
};
class linked_list{
private:
    node *head, *tail;
public:
    linked_list(){
        head = NULL;
        tail = NULL;
    }

};