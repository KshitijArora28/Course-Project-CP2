#include <iostream>
#include <string>
#include <cstdlib>

void delete_commodity(product *& p1[],int n,string s1){
  if(p1[n-1].name==s1){
    n=n-1;
  }
  else{
    for(int i=1;i<n-1;i++){
      if(p1[i].name==s1){
        for(int j=i;j<n-1;j++){
          p1[j].name=p1[i+1].name;
          p1[j].quantity=p1[i+1].quantity;
          p1[j].expiry_date=p1[i+1].expiry_date;
          p1[j].cost=p1[i+1].cost;
          p1[j].selling_cost=p1[i+1].sellin_cost;
        }
        n=n-1;
      }
    }
  }
}
