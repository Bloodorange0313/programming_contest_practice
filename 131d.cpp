#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int n;
ll a, b;
ll ans = 0;
vector<pair<ll, ll> >V;
bool judge = true;

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a >> b;
    V.push_back(make_pair(b, a));
  }
  sort(V.begin(), V.end());
  for(int i = 0; i < V.size(); ++i){
    ans += V[i].second;
    //cout <<"check: " << ans << " " << V[i].first << endl;
    if(ans > V[i].first){
      judge = false;
      //break;
    }
  }
  if(judge == true){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}