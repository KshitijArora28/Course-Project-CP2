//stock below
//expiry date (According to UST)
//auto order
#include <ctime>

void alerts(product *p,int n){
  cout<<endl<<"**ALERTS**"<<endl;
  for (int i=0;i<n;i++){
    if (p[i].quantity<5){
      cout<<p[i].name<<" stock is low."<<endl;
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
