#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

bool compare(const pair<string, int>&i, const pair<string, int>&j)
{
    return i.second > j.second;
}
bool compare1(const pair<string, int>&i, const pair<string, int>&j)
{
    return i.first < j.first;
}


int n;
string s[105];
int p[105];
vector<pair<string, int> >V;
map<int, int>M;

char in[105];
pair<pair<string,int>,int> pd[110];

int main(){
  cin >> n;
  
  for(int i = 0; i < n; ++i){
    int t;
    cin >> in >> t;
    string tmp = in;
    //V.push_back(make_pair(s[i], p[i]));
    pd[i]=make_pair(make_pair(in, -t),i);
    //M[p[i]] = i;
    
  }
  //sort(V.begin(), V.end(), compare);
  //sort(V.begin(), V.end(), compare1);
  sort(pd, pd + n);
  
  for(int i = 0; i < n; ++i){
    cout << pd[i].second + 1 << endl;
  }
}