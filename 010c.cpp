#include<iostream>
#include<cmath>

using namespace std;

pair<int, int>start;
pair<int, int>goal;
int v, t;
int n;
pair<int, int> pd[1050];
double eps = 0.01;

int maximum_distance(){
  return v * t;
}

bool solver(){
  bool judge = false;
  for(int i = 0; i < n; ++i){
    double distance_one = sqrt((start.first - pd[i].first) * (start.first - pd[i].first) + (start.second - pd[i].second) * (start.second - pd[i].second));
    double distance_sec = sqrt((goal.first - pd[i].first) * (goal.first - pd[i].first) + (goal.second - pd[i].second) * (goal.second - pd[i].second));
    double distance = distance_one + distance_sec;
    if(distance <= maximum_distance() + eps){
      judge = true;
    }
  }
  return judge;
}

int main(){
  cin >> start.first >> start.second >> goal.first >> goal.second >> t >> v ;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> pd[i].first >> pd[i].second;
    //cout << (start.first - pd[i].first) * (start.first - pd[i].first) << endl;
    //cout << sqrt((start.first - pd[i].first) * (start.first * pd[i].first) + (start.second - pd[i].second) * (start.second - pd[i].second)) << endl;
  }
  if(solver() == true){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  //cout << maximum_distance() << endl;
  
}