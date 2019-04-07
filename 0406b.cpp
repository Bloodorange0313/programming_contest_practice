#include<iostream>

using namespace std;

int cell[5], k[5];
int sum = 0;
int tmp = 9;
int tmp_i = 0;

int main(){
  for(int i = 0; i < 5; ++i){
    cin >> cell[i];
    if(cell[i] % 10 <= tmp && cell[i] % 10 != 0){
      tmp = cell[i] % 10;
      tmp_i = i;
    }
    //sum += cell[i];
  }
  for(int i = 0; i < 5; ++i){
    if(i != tmp_i && (cell[i] % 10) != 0){
      k[i] = cell[i];
      k[i] += 10 - (cell[i] % 10);
      sum += k[i];
    }else{
      k[i] = cell[i];
      sum += cell[i];
    }
  }
  cout << sum << endl;
  //cout << tmp_i << endl;
  /*
  for(int i = 0; i < 5; ++i){
    cout << k[i] << endl;
  }
  */
  
}