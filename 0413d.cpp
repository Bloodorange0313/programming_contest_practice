#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define inf 10000000000 + 5

int n, k;
string s;
//priority_queue<int>Q;
vector<int>V, V1;
priority_queue<int>Q;
int answer = 0;

int main(){
  cin >> n >> k;
  cin >> s;
  //n = s.length();
  //for(int i = 0; i < k; ++i){
  //Q.push(0);
  V.push_back(-1);
  //s[-1] = '-1';
  for(int j = 0; j < n; ++j){
    if(s[j] == '1'){
      if(s[j - 1] != '1' || s[j + 1] == '0'){
        V.push_back(j);
      }
      /*
      if(s[j + 1] == '0'){
        V1.push_back(j);
      }
      */
      /*
      if(s[j + 1] == '0'){
        V.push_back(j + 1);
      }
      */
    }
  }
  
  for(int j = 0; j < V.size() - 1; ++j){
    Q.push(V[j + 1] - V[j]);
  }
  for(int i = 0; i < k; ++i){
    int tmp = Q.top();
    Q.pop();
    tmp += Q.top();
    Q.pop();
    answer += tmp;
  }
  /*
 while(!Q.empty()){
    std::cout << Q.top() << std::endl;
    Q.pop();
 }
 */
  
  cout << answer << endl;
}