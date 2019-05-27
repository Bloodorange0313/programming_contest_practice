 #include<iostream>

 using namespace std;

int n, m;
int l[100015], r[100015];
int mini, maxi;

int solver(){  
  mini = 1;
  maxi = n;
  for(int i = 1; i < m + 1; ++i){
    if(mini < l[i]){
      mini = l[i];
    }
    if(maxi > r[i]){
      maxi = r[i];
    }
  }
  if(mini <= maxi){
    return maxi - mini + 1;
  }else{
    return 0;
  }
  
}

 int main(){
   cin >> n >> m;
   for(int i = 1; i < m + 1; ++i){
     cin >> l[i] >> r[i];
   }
   cout << solver() << endl;
 }