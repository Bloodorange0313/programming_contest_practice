#include<iostream>

using namespace std;

int a, b, t;
int answer;

int main(){
  cin >> a >> b >> t;
  answer = ((t + (1 / 2)) / a) * b;
  cout << answer << endl;
}