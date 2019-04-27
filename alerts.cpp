//stock below
//expiry date (According to UST)
//auto order
#include <ctime>

void alerts(product * &p,int n){
  cout<<endl<<"**ALERTS**"<<endl;
  for (int i=1;i<n;i++){
    if (p[i].quantity<5){
      if (p[i].stock='O'){
          cout<<p[i].name<<" is out-of-stock."<<endl;
          cout<<endl;
      }
      else{
        cout<<p[i].name<<" stock is low.(less than 5 units remaining)"<<endl;
        cout<<endl;
      }
    }
  }
  time_t now = time(0);
  tm *gmtm = gmtime(&now);
  for (int i=1;i<n;i++){
    if (p[i].e_year-1900<=tm_year && p[i].e_year!=0){
      if (p[i].e_year-1900<tm_year){
        cout<<p[i].name<<" expiry date is up."<<endl;
        cout<<endl;
        continue;
      }
      if(p[i].e_mm-1<=tm_mon){
        if(p[i].e_mm-1<tm_mon){
          cout<<p[i].name<<" expiry date is up."<<endl;
          cout<<endl;
          continue
        }
        if(p[i].dd<tm_mday){
          cout<<p[i].name<<" expiry date is up."<<endl;
          cout<<endl;
        }
      }
    }
  }
}
