#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void delete_commodity(product * &p1,int &n,string s1){
  if(p1[n-1].name==s1){
    n=n-1;
  }
  else{
    for(int i=1;i<n;i++){
      if(p1[i].name==s1){
        for(;i<n-1;i++){
          p1[i].name=p1[i+1].name;
          p1[i].quantity=p1[i+1].quantity;
          p1[i].e_dd=p1[i+1].e_dd;
          p1[i].e_mm=p1[i+1].e_mm;
          p1[i].e_year=p1[i+1].e_year;
          p1[i].cost=p1[i+1].cost;
          p1[i].selling_cost=p1[i+1].selling_cost;
        }
        n=n-1;
      }
    }
  }
}
