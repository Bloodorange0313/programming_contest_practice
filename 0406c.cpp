#include<iostream>

using namespace std;

long long int n;
long long int answer = 0;
long long int cell[6];
long long int tmp;

int main(){
  cin >> n;
  tmp = n;
  for(int i = 0; i < 5; ++i){
    cin >> cell[i];
    answer += 1;
  }
  for(int i = 0; i < 5; ++i){
    if(cell[i] < tmp){
      /*
      if((tmp % cell[i]) != 0){
        answer += (tmp / cell[i]);
      }else{
        answer += (tmp / cell[i]) - 1;
      }
      */
      tmp = cell[i];
    }
  }
  if(n > tmp){
    if(n % tmp != 0){
      answer += (n / tmp);
    }else{
      answer += (n / tmp) - 1;
    }
    
  }
  
  cout << answer << endl;
}