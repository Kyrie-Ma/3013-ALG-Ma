//This is all i can got, i got the answer but not the best one
//------------------------------------------------------------

#include <iostream>
#include <string>
#include<queue>
#include <fstream>
#include <iomanip>
#define endl "\n"
using namespace std;
int main() {
  int c;
  cin >> c;
  for(int i=0;i<c;i++){
    int ferryLenth, carLenth, sumL, sumR;
    sumL = sumR =0;
    queue<int> carQueue;
    queue<string> sideQueue;
    cin >> ferryLenth;
    ferryLenth *=100;
    cin >>carLenth;
    while(carLenth!=0){
      carQueue.push(carLenth);
      cin >> carLenth;
    }
    int temp1 = 0;
    temp1 = carQueue.size();
    for(int j=0;j<temp1;j++){
      if(sumL<ferryLenth || sumR<ferryLenth){
        if(sumL+carQueue.front()<ferryLenth){
          sumL+=carQueue.front();
          carQueue.pop();
          sideQueue.push("port");
          //cout << "testL\n";
        }
        else if(sumR+carQueue.front()<ferryLenth){
          sumR+=carQueue.front();
          carQueue.pop();
          sideQueue.push("starboard");
          //cout << "testR\n";
        }
        else {
          carQueue.pop();
          //cout << "test\n";
        }
      } 
    }
    int temp2 = 0;
    temp2 = sideQueue.size();
    cout << temp2 << endl;
    for(int z=0;z<temp2;z++){
      cout << sideQueue.front() << endl;
      sideQueue.pop();
    }
  }
  return 0;
}
