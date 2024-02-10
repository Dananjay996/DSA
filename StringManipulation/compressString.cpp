#include <bits/stdc++.h>

using namespace std;

string compressString(string s){
  string result = "";

  int length = s.length();

  for(int i=0; i<length; i++){
    int count = 1, j=i+1;
    char currChar = s[i];
    while(j < length){
      if(s[j] != currChar){
        break;
      }
      count++;
      j++;
    }

    if(count > 3){
     result += to_string(count) + 'X' + currChar; 
     i = j-1;
    }else{
     result += currChar;
    }

  }

  return result;
}

int main(){
  string s;
  cin >> s;

  string result = compressString(s);
  cout << "Result is: " << result << endl;

  return 0;
}
