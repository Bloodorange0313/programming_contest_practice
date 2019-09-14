#include<iostream>
#include<algorithm>


using namespace std;

int n, m;
int p[100005];
int x[100005], y[100005];

int P[100005];
void init(int N){
  for(int i = 0; i < N; ++i){
    P[i] = i;
  }
}

int root(int a){
  if(P[a] == a) return a;
  return(P[a] = root(P[a]));
}

bool is_same_set(int a, int b){
  return root(a) == root(b);
}

void unit(int a, int b){
  P[root(a)] = root(b);
}

int main(){
  cin >> n >> m;
  init(n);
  for(int i = 0; i < n; ++i){
    cin >> p[i];
  }
  for(int i = 0; i < m; ++i){
    cin >> x[i] >> y[i];
    unit(x[i], y[i]);
  }
  int cnt = 0;
  for(int i = 0; i < n; ++i){
    if(is_same_set(p[i], i + 1)){
      cnt++;
    }
  }
  cout << cnt << endl;
}