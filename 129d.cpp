#include<iostream>

using namespace std;

int h, w;
char s[2050][2050];
int c[2050][2050];
int l[2050][2050], r[2050][2050], u[2050][2050], d[2050][2050];
int ans[2050][2050];

void solver(){
  int answer = 0;
  
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      if(c[i][j] == 0){
        l[i][j] = 0;
      }else if(j == 0){
        l[i][j] = 1;
      }else{
        l[i][j] = l[i][j - 1] + 1;
      }
    }
  }
  for(int i = 0; i < h; ++i){
    for(int j = w - 1; j >= 0; --j){
      if(c[i][j] == 0){
        r[i][j] = 0;
      }else if(j == w - 1){
        r[i][j] = 1;
      }else{
        r[i][j] = r[i][j + 1] + 1;
      }
    }
  }
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      if(c[i][j] == 0){
        u[i][j] = 0;
      }else if(i == 0){
        u[i][j] = 1;
      }else{
        u[i][j] = u[i - 1][j] + 1;
      }
    }
  }
  for(int i = h - 1; i  >= 0; --i){
    for(int j = 0; j < w; ++j){
      if(c[i][j] == 0){
        d[i][j] = 0;
      }else if(i == h - 1){
        d[i][j] = 1;
      }else{
        d[i][j] = d[i + 1][j] + 1;
      }
    }
  }
  
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      ans[i][j] = l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3;
      if(ans[i][j] > answer){
        answer = ans[i][j];
      }
      //cout << ans[i][j] << endl;
    }
  }

 cout << answer << endl;

  
}

int main(){
  cin >> h >> w;
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      cin >> s[i][j];
      if(s[i][j] == '.'){
        c[i][j] = 1;
      }else{
        c[i][j] = 0;
      }
      //cout << c[i][j];
    }
  }
  solver();
}