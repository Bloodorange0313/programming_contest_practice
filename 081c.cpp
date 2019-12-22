#include<iostream>
#include<unordered_map>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int n, k;
int a[200005];
map<int, int>M;
vector<int>V;
vector<pair<int, int>> vec;

void input(){
  cin >> n >> k;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    M[a[i]]++;
  }
}

void count(){
  
  map<int, int> :: iterator it2;
  for (it2=M.begin(); it2!=M.end(); it2++){
    vec.push_back(make_pair(it2->second, it2->first));
    //cout << it2->second << endl;
  }
  sort(vec.begin(), vec.end());
}

int solve(){
  if(vec.size() < k){
    //cout << 0 << endl;
    return 0;
  }else{
    int ans = 0;
    for(int i = 0; i < vec.size() - k; ++i){
      ans += vec[i].first;
    }
    return ans;
  }
  
}

int main(){
  input();
  count();
  cout << solve() << endl;
}