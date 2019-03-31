#include<iostream>
#include<string>

using namespace std;

int n;
string s;
int red = 0;
int blue = 0;

int main(){
  cin >> n;
  cin >> s;
  for(int i = 0; i < s.length(); ++i){
    if(s[i] == 'R'){
      red++;
    }else if(s[i] == 'B'){
      blue++;
    }
  }
  if(red > blue){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}