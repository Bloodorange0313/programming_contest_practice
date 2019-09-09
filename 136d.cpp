#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string S;
int ans[100005];

int main(){
  cin >> S;
  int cnt1 = 0, cnt2 = 0;
  int n = S.size();
  int tmp1 = 0, tmp2 = 0;
  S[-1] = 'R';
  S[n] = 'L';  
  for(int i = 0; i <= n; ++i){
    if((S[i] == 'R' && S[i - 1] == 'L') || (i == n)){
      if((cnt1 + cnt2) % 2 == 0){
        ans[tmp1] = (cnt1 + cnt2) / 2;
        ans[tmp2] = (cnt1 + cnt2) / 2;
        //cout << i << endl;
      }else{
        int s = max(cnt1, cnt2);
        if(s % 2 == 0){
          if(cnt1 < cnt2){
            ans[tmp1] = ((cnt1 + cnt2) + 1) / 2;
            ans[tmp2] = ((cnt1 + cnt2) - 1) / 2;
            //cout << i << endl;
          }else{
            ans[tmp1] = ((cnt1 + cnt2) - 1) / 2;
            ans[tmp2] = ((cnt1 + cnt2) + 1) / 2;
            //cout << i << endl;
          }
        }else{
          if(cnt1 < cnt2){
            ans[tmp1] = ((cnt1 + cnt2) - 1) / 2;
            ans[tmp2] = ((cnt1 + cnt2) + 1) / 2;
          }else{
            ans[tmp1] = ((cnt1 + cnt2) + 1) / 2;
            ans[tmp2] = ((cnt1 + cnt2) - 1) / 2;
          }
          
        }
      }
      cnt1 = 0;
      cnt2 = 0;
    }
    if(S[i] == 'R'){
      cnt1++;
      tmp1 = i;
      tmp2 = tmp1 + 1;
    }
    if(S[i] == 'L'){
      cnt2++;
    }
  }
  for(int i = 0; i < n; ++i){
    cout << ans[i] << " ";
  }
  cout << endl;
}