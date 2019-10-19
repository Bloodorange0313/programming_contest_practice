#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>


using namespace std;
using ll = long long;

int n;
int l[2005];
vector<int>V;

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> l[i];
    V.push_back(l[i]);
  }
  sort(V.begin(), V.end());
  int ans = 0;
  for(int i = 0; i < n; ++i){
    //int tmp = V[i] * 2;
    for(int j = i + 2; j < n; ++j){
      int tmp = j - 1;
      while(tmp > i){
        if(V[j] >= V[i] + V[tmp]){
          break;
        }else{
          ans++;
          tmp--;
        }
      }
    }
  }
  cout << ans << endl;
}