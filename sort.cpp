#include <iostream>
#include <string>
#include <bits/stdc++.h>

bool compare_code(product a, product b){
  if (a.code.compare(b.code)<0){
    return true;
  }
  else{
    return false;
  }
}

bool compare_name(product a, product b){
  if (a.name.compare(b.name)<0){
    return true;
  }
  else{
    return false;
  }
}

void defsort(int n,product *p){
  char option;
  cout<<"Sorting the products according to -"<<endl;
  cout<<"a. Alphabetical Order of name."<<endl;
  cout<<"b. Product Code(lexicographical order)."<<endl;
  cout<<"c. Reverse current order."<<endl;
  cout<<"Enter a,b or c: ";
  cin>>option;
  if (option=='a'){
    sort(p, p+n, compare_name);
  }
  if (option=='b'){
    sort(p, p+n, compare_code);
  }
  if (option=='c'){
      product temp;
        for (int i=1;i<(n/2.0);i++){
        temp=p[i];
        p[i]=p[n-i];
        p[n-i]=temp;
      }
  }
}
