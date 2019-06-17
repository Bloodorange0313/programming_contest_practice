#include<iostream>
#include<cstdio>

using namespace std;

int n;
bool f[105][11];
int p[105][12];

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < 10; ++j){
      cin >> f[i][j];
    }
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < 11; ++j){
      cin >> p[i][j];
    }
  }
  int res = -(1 << 30);
  //cout << res << endl;
  for ( int b =1; b <(1 <<10); b ++){
    int cc = 0;
    for(int i = 0; i < n; ++i){
      int c = 0;
      for ( int j =0; j <10; ++j){
        if (( b >> j&1)&& f[i][j]) c ++; //&1は1ビット目を取り出すため
      }
      cc += p[i][c];
    }
    if(res < cc) res = cc;
  }
  cout << res << endl;
}