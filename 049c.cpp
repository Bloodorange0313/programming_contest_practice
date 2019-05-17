#include<iostream>
#include<string>

using namespace std;

string s;

int main(){
  cin >> s;
  int cnt = 0;
  while(cnt != s.length()){
    string result1 = s.substr(cnt, 7);
    //cout << result1 << endl;
    string result2 = s.substr(cnt, 6);
    string result3 = s.substr(cnt, 5);
    if(result1 == "dreamer" && s.substr(cnt, 8) != "dreamera"){
      cnt += 7;
    }else if(result2 == "eraser" && s.substr(cnt, 7) != "erasera"){
      cnt += 6;
    }else if(result3 == "dream" || result3 == "erase"){
      cnt += 5;
    }else{
      break;
    }
  }
  if(cnt == s.length()){
    cout <<  "YES" << endl;
    //cout << cnt << endl;
  }else{
    cout << "NO" << endl;
    //cout << cnt << endl;
  }
  
}