#include<iostream>
#include<string>

using namespace std;

int h, w;
char s[55][55];
bool cell[55][55];
bool judge = true;

int main(){
  for(int i = -1; i <= h; ++i){
    for(int j = -1; j <= w; ++j){
      cell[i][j] = 0;
    }
  }
  cin >> h >> w;
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      cin >> s[i][j];
      //cout << s[i][j] << endl;
      if(s[i][j] == '#'){
        cell[i][j] = 1;
      }
      //cout << cell[i][j] << endl;
    }
  }
  
  
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      //cout << cell[i][j] << endl;
      if(cell[i][j] == 1){
        if(!(cell[i - 1][j] == 1 || cell[i + 1][j] == 1 || cell[i][j - 1] == 1 || cell[i][j + 1] == 1)){
          judge = false;
        }
      }
    }
  }
  if(judge == true){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}