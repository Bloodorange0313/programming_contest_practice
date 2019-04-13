#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define inf 10000000000 + 5

int a, b;
int answer;

int main(){
  cin >> a >> b;
  if(a > b){
    answer += a;
    a--;
  }else{
    answer += b;
    b--;
  }
  if(a > b){
    answer += a;
    a--;
  }else{
    answer += b;
    b--;
  }
  cout << answer << endl;
}