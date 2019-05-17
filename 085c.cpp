#include<iostream>

using namespace std;

int n;
long long int y;
int x = 0, y1 = 0, z = 0;

int tmp1, tmp2, tmp3;
bool judge = false;
int sum1, sum2, sum3;

int main(){
  cin >> n >> y;
  int sum = y;
  tmp1 = sum / 1000;
  //cout << tmp1 << endl;
  for(int i = 0; i < tmp1; ++i){
    //x = i;
    sum1 = sum - i * 1000;
    //cout << sum1 << endl;
    tmp2 = sum1 / 5000;
    for(int j = 0; j < tmp2; ++j){
      sum2 = sum1 - j * 5000;
      int k = n - i - j;
      if(sum2 - k*10000 == 0){
        x = k;
        y1 = j;
        z = i;
        judge = true;
        break;
      }
    }
  }
  if(judge == true){
    cout << x << " " << y1 << " " << z << endl;
  }else{
    cout << -1 << " " << -1 << " " << -1 << endl;
  }
}