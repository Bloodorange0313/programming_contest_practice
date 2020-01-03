#include<vector>
#include<algorithm>
#include<iostream>


using namespace std;
using ll = long long;

int n;
ll m;
int a[100005];
vector<int>V;

void input(){
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    V.push_back(a[i]);
  }
  sort(V.begin(), V.end(), greater<int>());
}

ll solve2(){
  
}

ll solve(){
  ll ans = 0;
  ll cnt = 0;
  ll s = 0;
  ll tmp = 0;
  while(cnt < m){
    cnt++;
    if(tmp % 3 == 0){
      ans += V[s] + V[s];
      //s++;
      tmp++;
      cout << V[s] << " " << V[s] << endl;
    }else if(tmp % 3 == 1){
      ans += V[s] + V[s + 1];
      tmp++;
      cout << V[s] << " " << V[s + 1] << endl;
    }else{
      s++;
      ans += V[s] + V[s - 1];
      tmp++;
      cout << V[s] << " " << V[s - 1] << endl;
    }
    if(s > V.size()){
      break;
    }
    cout << ans << endl;
    //cout << cnt << endl;
    //cout << V[s] << " " << V[s + 1] << endl;
  }
  return ans;

}


int main(){
  input();
  cout << solve() << endl;
}