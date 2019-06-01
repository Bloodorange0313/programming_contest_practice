#include<iostream>

using namespace std;

int n; 
int a[3000 + 5];

int main(){
  cin >> n;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    ans += a[i] - 1;
  }
  cout << ans << endl;
}