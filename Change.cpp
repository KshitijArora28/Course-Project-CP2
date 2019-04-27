#include <iostream>
#include <string>
using namespace std;

void Change(product * &p1,string nm1,int q1,int c1,int c2,int e1,int e2,int e3,int s){
  for(int i=1;i<s;i++){
    if(p1[i].name==nm1){
      if(q1!=0){
        p1[i].quantity=q1;
      }
      if(c1!=0){
        p1[i].cost=c1;
      }
      if(c2!=0){
        p1[i].selling_cost=c2;
      }
      if(e1!=0){
        p1[i].e_dd=e1;
      }
      if(e2!=0){
        p1[i].e_mm=e2;
      }
      if(e3!=0){
        p1[i].e_year=e3;
      }
    }
  }
}
