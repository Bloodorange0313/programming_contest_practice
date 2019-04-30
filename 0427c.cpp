#include<iostream>
#include<algorithm>

using namespace std;

long long int n;
long long int a[100001];

long long int gcd(long long int s, long long int t){
  long long int tmp, r;
  if(s < t){
    tmp = s;
    s = t;
    t = tmp;
  }
  r = s % t;
  while(r != 0){
    s = t;
    t = r;
    r = s % t;
  }
  return t;
}

void solver(){
  long long int l[100001], r[100001], m[100001], maxi = 1000000001;
  l[0] = 0, r[n + 1] = 0;
  for(int i = 0; i <= n; ++i){
    l[i + 1] = gcd(l[i], a[i]);
    r[i] = gcd(r[i + 1], a[i]);
    //maxi = max(maxi, l[i], r[i + 1]);
    //m[i] = gcd(l[i], r[i + 1]);
    //cout << m[i] << endl;
    /*
    if(maxi > m[i]){
      maxi = m[i];
    }
    */
   //cout << l[i] << endl;
  }
  for(int i = 0; i < n; ++i){
    m[i] = gcd(l[i], r[i + 1]);
    //cout << m[i] << endl;
    if(maxi > m[i]){
      maxi = m[i];
    }
  }
  //return maxi;
  cout << maxi << endl;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  //cout << __gcd(2,4) << endl;
  //cout << gcd(2,4) << endl;
  //cout << solver() << endl;
  solver();
}