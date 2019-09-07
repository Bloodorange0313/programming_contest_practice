#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include <sstream>
#include <iomanip>



using namespace std;
using ll = long long;

int n, m, p[100005], a, b;
ll y[100005];
unordered_map<ll, int>M;
vector<pair<int, ll> >V;
vector<pair<int, string> >ANS;
string S[100005];

int main(){
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> p[i] >> y[i];
    M[y[i]] = i;
    V.push_back(make_pair(p[i], y[i]));
  }
  sort(V.begin(), V.end());
  int tmp = 0;
  int cnt = 0;
  for(int i = 0; i < m; ++i){
    //cout << V[i].first << " " << V[i].second << endl;
    //cout << M[V[i].second] << endl;
    
    if(tmp != V[i].first){
      cnt = 0;
    }
    cnt++;
    a = V[i].first;
    b = cnt;
    ostringstream x, y;
    x << setw(6) << setfill('0') << to_string(a);
    string s_1(x.str());
    y << setw(6) << setfill('0') << to_string(b);
    string s_2(y.str());
    S[i] = s_1 + s_2;
    //cout << S[i] << endl;
    ANS.push_back(make_pair(M[V[i].second], S[i]));
    tmp = V[i].first;
    
  }
  sort(ANS.begin(), ANS.end());
  for(int i = 0; i < m; ++i){
    cout << ANS[i].second << endl;
  }


}