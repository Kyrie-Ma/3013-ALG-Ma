#include <iostream>
#include <string>
#define endl "\n"
using namespace std;
int main() {
  int c;
  cin >> c;
  while(c>0){
    int array[1440];
    int n, t, m, temp1, count, time, temp2; //count:number of trip, temp2: which car
    time = count = temp1 = temp2 = 0;       //time:how much time being use currently
    cin >> n >> t >> m;
    for(int i=1; i<=m;i++){
      cin >> temp1;                         //temp1:when the car arrived
      array[i] = temp1;
    }
    if(m%n!=0){
      time = array[1]+2*t;
      temp2++;
      count++;
    }
    for(int j = temp2+n;j<=m;j+=n){
      if(time >= array[j]){
        time = time + t*2;
        count++;
      }
      else{
        time = array[j] +t*2;
        count++;
      }
    }
    time = time-t;
    cout << time << " " << count << endl;
    c--;
  }
  cout << endl;
  return 0;
}
