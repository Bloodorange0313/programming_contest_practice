#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define inf 10000000000 + 5

string s;
int n;
int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0; 
int answer = 0;
int answer1 = 0;
int answer2 = 0;

int main(){
  cin >> s;
  n = s.length();
  for(int i = 0; i < n; ++i){
    
    if(i % 2 == 0){
      cnt4++;
      if(s[i] == '0'){
        cnt1++;
      }
    }
    if(i % 2 == 1){
      cnt3++;
      if(s[i] == '0'){
        cnt2++;
      }
    }
  }
  //cout << cnt2 << endl;
  //cout << cnt4 - cnt1 << endl;
  /*
  if(min(cnt1, cnt4 - cnt1)  < min(cnt2, cnt3 - cnt2)){
    if(cnt1 < cnt4 - cnt1){
      answer += cnt1 + (cnt3 - cnt2);
      //cout << "a" << endl;
    }else{
      answer += (cnt4 - cnt1) + cnt2;
      //cout << "b" << endl;
    }
  }else{
    if(cnt2 < cnt3 - cnt2){
      answer += cnt2 + (cnt4 - cnt1);
      //cout << "c" << endl;
      //cout << cnt2 << endl;
    }else{
      answer += (cnt3 - cnt2) + cnt1;
      //cout << "d" << endl;
    }
  }
  */
  answer1 += cnt1 + (cnt3 - cnt2);
  answer2 += (cnt4 - cnt1) + cnt2;

  answer = min(answer1, answer2);
  cout << answer << endl;
  //cout << answer1 << endl;
  //cout << answer2 << endl;
}