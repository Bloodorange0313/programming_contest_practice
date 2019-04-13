#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define inf 10000000000 + 5

long long int x, y, z, k;
long long int a[inf], b[inf], c[inf];
vector<long long int>A, B, C;

int main(){
  cin >> x >> y >> z >> k;
  for(int i = 0; i < x; ++i){
    cin >> a[i];
    A.push_back(a[i]);
  }
  for(int i = 0; i < y; ++i){
    cin >> b[i];
    B.push_back(b[i]);
  }
  for(int i = 0; i < z; ++i){
    cin >> c[i];
    C.push_back(c[i]);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  for(int i = 0; i < k; ++i){
    
  }
}