#include<iostream>
#include<set>

using namespace std;

int n;
int a;
set<int> st;

int main(){
  cin >> n;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    cin >> a;
    //cout << st.count(a) << endl;
    if(st.count(a) == 1){
      st.erase(a);
      ans--;
    }else{
      st.insert(a);
      ans++;
    }
  }
  cout << ans << endl;
}