#include<iostream>
#include<deque>

using namespace std;
using ll = long long;

int n;
ll a;
deque<ll>Q, D;

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a;
    Q.push_back(a);
  }
  ll cnt = n;
  while(!Q.empty()){
    if(cnt % 2 == 1){
      D.push_front(Q.front());
      Q.pop_front();
    }else{
      D.push_back(Q.front());
      Q.pop_front();
    }
    cnt--;
  }
  while(!D.empty()){
    cout << D.front() << " ";
    D.pop_front();
  }
  cout << endl;
}

