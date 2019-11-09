#include<iostream>
#include<string>

using ll = long long;
using namespace std;

string s;

void input(){
  cin >> s;
}

void solver(){
  ll cnt1 = 0;
  ll cnt0 = 0;
  for(int i = 0; i < s.length(); ++i){
    if(s[i] == '0'){
      cnt0++;
    }else{
      cnt1++;
    }
  }
  cout<< 2 * min(cnt1, cnt0) << endl;
}

int main(){
  input();
  solver();
}