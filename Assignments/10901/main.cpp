#include <iostream>
#include<vector>
#include <queue>
#include <string>
#include <limits>
#define endl "\n"
using namespace std;

int main()
{   
  int c;
  cin >> c;                                                           //cin how many cases
  while (c>0){
    int n, t, m;
    int Time = 0;
    int LEFT = 0;
    int RIGHT = 1;
    int bankForFerry = LEFT;                                          //which side is ferry right now
    cin >> n >> t >> m;
    vector<queue<pair<int, int> > > cars(2);
    int arrUnloadTime[m-1];
    for (int i = 0; i < m; i++){
      int arrivalTime;
      string bank;                                                    //which side the car arrive
      cin >> arrivalTime >> bank;
      if (bank == "left"){
        cars[LEFT].push(pair<int, int>(i, arrivalTime));              //store the car of left side
      }
      else{
        cars[RIGHT].push(pair<int, int>(i,arrivalTime));              //store the car of left side
      }
    }
    while (!(cars[LEFT].empty() && cars[RIGHT].empty())){
      int carArrivedTime = numeric_limits<int>::max();
      if (!cars[LEFT].empty()){
        carArrivedTime = cars[LEFT].front().second;
      }
      if (!cars[RIGHT].empty()){
        carArrivedTime = min(carArrivedTime, cars[RIGHT].front().second);
      }
      Time = max(Time, carArrivedTime);                               //get the time when the car is upload
      int Count = 0;
      while (!cars[bankForFerry].empty() && cars[bankForFerry].front().second <= Time && Count < n){
        Count++;                                                      //count the number that on the ferry 
        arrUnloadTime[cars[bankForFerry].front().first] = Time + t;   //store the time that the car arrive the opposite side
        cars[bankForFerry].pop();                                     //pop out the car that have been upload
      }
      Time = Time + t;                                                //get the current time
      if(bankForFerry == LEFT){
        bankForFerry = RIGHT;                                         //move the ferry to the opposite side can get it
      }
      else{
        bankForFerry = LEFT;                                          //move the ferry to the opposite side can get it
      }
    }
    for (int i = 0; i < m; i++){
      cout << arrUnloadTime[i] << endl;                               //cout the time
    }
    cout << endl;
    c--;
  }
  return 0;
}
