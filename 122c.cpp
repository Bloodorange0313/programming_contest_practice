#include<iostream>
#include<string>

using namespace std;

int n, q;
string s;
int l, r;
int ans[100005];

int main(){
  cin >> n >> q;
  cin >> s;
  s[n] = '0';
  for(int i = 0; i < n; ++i){
    ans[i] = 0;
  }
  for(int i = 0; i < n; ++i){
    if(s[i] == 'A' && s[i + 1] == 'C'){
      ans[i + 1] = ans[i] + 1;
      //cout << ans[i + 1] << endl;
    }else{
      ans[i + 1] = ans[i];
    }
  }
  //cout << ans[n - 1] << endl;
  for(int i = 0; i < q; ++i){
    cin >> l >> r;
    cout << ans[r - 1] - ans[l - 1] << endl;
  }
}