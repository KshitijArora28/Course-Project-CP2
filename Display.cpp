#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

void display(product * &p1,int n1){
  int maxlenpos=0;
  int w;
  for(int i=1;i<n1;i++){
    if(p1[i].name.length()>p1[maxlenpos].name.length()){
      maxlenpos=i;
    }
  }

  ofstream fout;
  fout.open("inventory_details.txt");
  if(fout.fail()){
    cout<<"Error in file opening !"<<endl;
    exit(1);
  }

  w=p1[maxlenpos].name.length();
  fout<<setw(w+4)<<"Name"<<setw(10)<<"Code"<<setw(10)<<"Stock"<<setw(10)<<"Cost"<<setw(14)<<"Sellprice"<<setw(10)<<"Sales"<<endl;
  cout<<setw(w+4)<<"Name"<<setw(10)<<"Code"<<setw(10)<<"Stock"<<setw(10)<<"Cost"<<setw(14)<<"Sellprice"<<setw(10)<<"Sales"<<endl;
  cout<<endl;
  for(int j=1;j<n1;j++){
    fout<<setw(w+4)<<p1[j].name<<setw(10)<<p1[j].code<<setw(10)<<p1[j].quantity<<setw(10)<<p1[j].cost<<setw(10)<<p1[j].selling_cost<<setw(10)<<p1[j].number_sold<<endl;
    cout<<setw(w+4)<<p1[j].name<<setw(10)<<p1[j].code<<setw(10)<<p1[j].quantity<<setw(10)<<p1[j].cost<<setw(10)<<p1[j].selling_cost<<setw(10)<<p1[j].number_sold<<endl;
  }
}
