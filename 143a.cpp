#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>


using namespace std;
using ll = long long;


int a, b;
int main(){
  cin >> a >> b;
  int c = 2 * b;
  if(a > c){
    cout << a - c << endl;
  }else{
    cout << 0 << endl;
  }
}