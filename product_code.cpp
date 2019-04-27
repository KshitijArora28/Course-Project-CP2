#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void code(int n,product *&p){
  for (int i=1;i<n;i++){
    int f=i%1000;
    stringstream num;
    num<<f;
    string num_string=num.str();
    if (num_string.length()==1){
      num_string.insert(0,"00");
    }
    if (num_string.length()==2){
      num_string.insert(0,"0");
    }
    p[i].code=p[i].name.substr(0,3)+num_string;
  }
}
