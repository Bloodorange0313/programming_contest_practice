#include<iostream>
#include<algorithm>
 
using namespace std;
 
long long int n;
long long int a[100005];
 
 
 
long long int gcd(int a,int b){
  if(a%b==0)
    return b;
  else
    return gcd(b,a%b);
}
 
void solver(){
  long long int l[100005], r[100005], m[100005], maxi = 0;
  l[0] = 0, r[n] = 0;
  for(int i = 0; i < n; ++i){
    l[i + 1] = gcd(l[i], a[i]);
  }
  
  for(int i = n - 1; i >= 0; --i){
    r[i] = gcd(r[i + 1], a[i]);
  }
  
  for(int i = 0; i < n - 1; ++i){
    m[i] = gcd(l[i], r[i + 1]);
    if(maxi < m[i]){
      maxi = m[i];
    }
    //cout << m[i] << endl;
  }
  
  cout << maxi << endl;
  
}
 
int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  solver();
}