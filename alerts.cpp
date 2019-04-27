//stock below
//expiry date (According to UST)
//auto order
#include <ctime>

void alerts(product *p,int n){
  cout<<endl<<"**ALERTS**"<<endl;
  for (int i=0;i<n;i++){
    if (p[i].quantity<5){
      if (p[i].quantity==0){
          cout<<p[i].name<<" is out-of-stock."<<endl;
      }
      else{
        cout<<p[i].name<<" stock is low.(less than 5 units remaining)"<<endl;
      }
    }
  }
  time_t now = time(0);
  tm *gmtm = gmtime(&now);
  for (int i=0;i<n;i++){
    if (p[i].year<=tm_year-1900 && p[i].year!=0){
      if (p[i].year<tm_year-1900){
        cout<<p[i].name<<" expiry date is up."<<endl;
        continue;
      }
      if(p[i].mm<=tm_mon-1){
        if(p[i].mm<tm_mon-1){
          cout<<p[i].name<<" expiry date is up."<<endl;
          continue
        }
        if(p[i].dd<tm_mday){
          cout<<p[i].name<<" expiry date is up."<<endl;
        }
      }
    }
  }
}
