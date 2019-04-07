#include<iostream>

using namespace std;

int a, b, c, d, e, k;
int cell[5];

bool judge(){
  bool dis = true;
  /*
  if(b - a > k){
    dis = false;
  }else if(c - b > k){
    dis = false;
  }else if(d - c > k){
    dis = false;
  }else if(e - d > k){
    dis = false;
  }else{
    dis = true;
  }
  */
 for(int i = 0; i < 5; ++i){
   for(int j = i + 1; j < 5; ++j){
     if(cell[j] - cell[i] > k){
       dis = false;
     }
   }
 }
  return dis;
}

int main(){
  cin >> a >> b >> c >> d >> e >> k;
  for(int i = 0; i < 5;++i){
    cell[0] = a;
    cell[1] = b;
    cell[2] = c;
    cell[3] = d;
    cell[4] = e;
  }
  if(judge() == true){
    cout << "Yay!" << endl;
  }else{
    cout << ":(" << endl;
  }
}