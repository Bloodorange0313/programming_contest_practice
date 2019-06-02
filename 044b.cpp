#include<iostream>
#include<map>
#include<string>
#include<set>

using namespace std;

string s;
map<int, char>mp;
set<string>st;
int c[105];
bool ans = true;


int main(){
  cin >> s;
  //int cnt = 0;
  for(int i = 0; i < s.size(); ++i){
    c[s[i] - 'a']++;
    //cout << s[i] - 'a' << endl;
  }
  for(int i = 0; i < 26; i++){
    if(c[i] % 2 == 1){
      ans = false;
    }
  }
  
  if(ans == true){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}