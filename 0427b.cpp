#include<iostream>

using namespace std;

int n;
int v[22];
int c[22];
int x;
int y;
int answer;

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }
  for(int i = 0; i < n; ++i){
    cin >> c[i];
    if(c[i] < v[i]){
      answer += (v[i] - c[i]);
    }
  }
  cout << answer << endl;
}