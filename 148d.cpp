#include<iostream>

using namespace std;

int n;
int a[200005];

void input(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
}

int solve(){
  int cnt = 0;
  int tmp = 1;
  for(int i = 0; i < n; ++i){
    if(a[i] != tmp){
      cnt++;
    }else{
      tmp++;
    }
  }
  if(cnt == n){
    return -1;
  }else{
    return cnt;
  }
}

int main(){
  input();
  cout << solve() << endl;
}