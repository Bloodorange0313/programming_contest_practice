#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>

using namespace std;

char s[222];

int main(){
  cin >> s;
  int n = strlen(s);
  for(int i = n - 2; i >= 0; i -= 2){
    if(strncmp(s, s + i / 2, i / 2) == 0){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}