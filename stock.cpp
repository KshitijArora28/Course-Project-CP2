#include <iostream>
#include <string>
#include <cstdlib>

void stock(product &* p1[],string f1,int s1){
  for(int i=1;i<s1;i++){
    if(p1[i].name==f1){
      p1[i].number_sold=rand()%100;
      if(p1[i].number_sold<=p1[i].quantity){
        p1[i].quantity=p1[i].quantity-p1[i].number_sold;
      }
      if(p1[i].number_sold>p1[i].quantity){
        cout<<"Purchase quantity more than stock"<<endl;
        cout<<"Stock left is "<<p1[i].quantity<<endl;
        cout<<"Do you want to buy ?"<<endl;
        cout<<"Enter Y for yes and N for no: -"<<endl;
        char ch;
        cin>>ch;
        if(ch=='Y'){
          p1[i].quantity=0;
        }
      }
      cout<<"Stock left is "<<p1[i].quantity<<endl;
    }
    }
  }
}
