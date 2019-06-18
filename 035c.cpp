#include<iostream>
#include<string>

using namespace std;
using ll = long long;

int n, q;
//int l[2050], r[2050]; 
ll ans[200050];


int main(){
  cin >> n >> q;

  
  for(int i = 0; i < q; ++i){
    int l, r;
    cin >> l >> r;
    ans[l - 1] += 1;
    ans[r] -= 1;
  }
  for(int i = 1; i < n; ++i){
    ans[i] += ans[i - 1]; 
  }
  for(int i = 0; i < n; ++i){
    int num = ans[i] % 2;
    cout << num;
  }
  cout << endl;
  
}