#include<iostream>
#include<string>

using namespace std;
using ll = long long;

int sx, sy, tx, ty;

void input(){
  cin >> sx >> sy >> tx >> ty;
}


string first_time(){
  string s;
  int y = ty - sy;
  int x = tx - sx;
  for(int i = 0; i < y; ++i){
    s.append("U");
  }
  for(int i = 0; i < x; ++i){
    s.append("R");
  }
  for(int i = 0; i < y; ++i){
    s.append("D");
  }
  for(int i = 0; i < x; ++i){
    s.append("L");
  }
  return s;
}

string second_time(){
  string s;
  int y = ty - sy;
  int x = tx - sx;
  s.append("L");
  for(int i = 0; i <= y; ++i){
    s.append("U");
  }
  for(int i = 0; i <= x; ++i){
    s.append("R");
  }
  s.append("D");
  s.append("R");
  for(int i = 0; i <= y; ++i){
    s.append("D");
  }
  for(int i = 0; i <= x; ++i){
    s.append("L");
  }
  s.append("U");
  return s;
}

int main(){
  input();
  cout << first_time() << second_time() << endl;
}