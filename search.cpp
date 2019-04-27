#include <iostream>
#include <string>
using namespace std;

void search(int n,product* prod){
  string *search_list=new string[n];
  char key;
  cout<<"Search by:-"<<endl;
  cout<<"a. Name (case sensitive)"<<endl;
  cout<<"b. Product Code"<<endl;
  cout<<"c. Inventory Status(All In-stock products)"<<endl;
  cout<<"d. Inventory Status(All Out-of-stock products)"<<endl;
  cout<<"Enter a,b,c or d: ";
  cin>>key;
  if (key=='a'){
    cout<<"Searching under names. Enter name: "<<endl;
  }
  else if(key=='b'){
    cout<<"Searching under product code. Enter code: "<<endl;
  }
  else if(key=='c'){
    cout<<"Searching under in-stock"<<endl;
  }
  else if(key=='d'){
    cout<<"Searching under out-of-stock"<<endl;
  }
  string search_item;
  int list_position=0;
  if (key=='a'){
      cin>>search_item;
      for (int i=1;i<n;i++){
        if(prod[i].name.find(search_item)!=string::npos){
          search_list[list_position]=prod[i].name;
          list_position++;
        }
      }
    }
  else if(key=='b'){
    cin>>search_item;
    for (int i=1;i<n;i++){
      if(prod[i].code.find(search_item)!=string::npos){
        search_list[list_position]=prod[i].code;
        list_position++;
      }
    }
  }
  else if(key=='c'){
    for (int i=1;i<n;i++){
      if(prod[i].stock=='I'){
        search_list[list_position]=prod[i].name;
        list_position++;
      }
    }
  }
  else if(key=='d'){
    for (int i=1;i<n;i++){
      if(prod[i].stock=='O'){
        search_list[list_position]=prod[i].name;
        list_position++;
      }
    }
  }
  else{
    cout<<"Invalid option."<<endl;
    return;
  }
  if (list_position==0){
    cout<<"No valid search result."<<endl;
  }
  else{
    cout<<"Search Results are: "<<endl;
    for (int i=0;i<list_position;i++){
      cout<<search_list[i]<<endl;
    }
  }
}

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

void stock(product * &p1,string f1,int s1){
  for(int i=1;i<s1;i++){
    if(p1[i].name==f1){
      p1[i].number_sold=rand()%100;
      if(p1[i].number_sold<=p1[i].quantity){
        p1[i].quantity=p1[i].quantity-p1[i].number_sold;
      }
      if(p1[i].number_sold>p1[i].quantity){
        cout<<"Purchase quantity "<<p1[i].number_sold<<" more than stock !"<<endl;
        cout<<"Stock left is: - "<<p1[i].quantity<<endl;
        cout<<"Do you want to buy ?"<<endl;
        cout<<"Enter Y for yes and N for no: -"<<endl;
        char ch;
        cin>>ch;
        if(ch=='Y'){
          p1[i].quantity=0;
        }
      }
      if(p1[i].quantity!=0){
        p1[i].stock='I';
      }
      else{
        p1[i].stock='O';
      }
      }
      cout<<"Stock left is "<<p1[i].quantity<<endl;
    }
    }

    void economic(int n,product *p){
      int time_period;
      cout<<"Enter the time period (in number of days) for which the data has been collected: ";
      cin>>time_period;
      double *profit_list=new double[n];
      double *quantity_sold=new double[n];

      for (int i=1;i<n;i++){
        cout<<endl<<p[i].name<<" (Product code- "<<p[i].code<<") "<<"quantity sold in "<<time_period<<" days = "<<p[i].number_sold<<endl;
        cout<<"net profit in "<<time_period<<" days = "<<(p[i].selling_cost-p[i].cost)*p[i].number_sold<<endl;
        cout<<"Predicted Requirement (quantity) for next month (30 days) = "<<ceil((p[i].number_sold/time_period)*30)<<endl;
        profit_list[i]=(p[i].selling_cost-p[i].cost)*p[i].number_sold;
        quantity_sold[i]=p[i].number_sold;
      }

      int least_profitable=1;
      int least_sold=1;
      int most_profitable=1;
      int most_sold=1;
      for (int i=1;i<n;i++){
        if (profit_list[i]<profit_list[least_profitable]){
          least_profitable=i;
        }
      }
      cout<<endl<<"Product with least profit: "<<p[least_profitable].name<<" (Product code- "<<p[least_profitable].code<<") "<<endl;
      for (int i=1;i<n;i++){
        if (profit_list[i]>profit_list[most_profitable]){
          most_profitable=i;
        }
      }
      cout<<"Product with most profit: "<<p[most_profitable].name<<" (Product code- "<<p[most_profitable].code<<") "<<endl;
      for (int i=1;i<n;i++){
        if (quantity_sold[i]<quantity_sold[least_sold]){
          least_sold=i;
        }
      }
      cout<<"Product with least quantity sold: "<<p[least_sold].name<<" (Product code- "<<p[least_sold].code<<") "<<endl;
      for (int i=1;i<n;i++){
        if (quantity_sold[i]>quantity_sold[most_sold]){
          most_sold=i;
        }
      }
      cout<<"Product with most quantity sold: "<<p[most_sold].name<<" (Product code- "<<p[most_sold].code<<") "<<endl;
      cout<<"*Disclaimer* - There maybe other products with the same amount in profit or quantity sold; the above statistics are"<<endl<<"solely meant to portray one product of each extreme category."<<endl;
    }


    void alerts(product * &p,int n){
      cout<<endl<<"**ALERTS**"<<endl;
      for (int i=1;i<n;i++){
        if (p[i].quantity<5){
          if (p[i].stock=='I'){
              cout<<p[i].name<<" is out-of-stock."<<endl;
          }
          else{
            cout<<p[i].name<<" stock is low.(less than 5 units remaining)"<<endl;
          }
        }
      }
      time_t now = time(0);
      tm *gmtm = gmtime(&now);
      for (int i=1;i<n;i++){
        if (p[i].e_year-1900<=gmtm->tm_year && p[i].e_year!=0){
          if (p[i].e_year-1900<gmtm->tm_year){
            cout<<p[i].name<<" expiry date is up."<<endl;
            continue;
          }
          if(p[i].e_mm-1<=gmtm->tm_mon){
            if(p[i].e_mm-1<gmtm->tm_mon){
              cout<<p[i].name<<" expiry date is up."<<endl;
              continue;
            }
            if(p[i].e_dd<gmtm->tm_mday){
              cout<<p[i].name<<" expiry date is up."<<endl;
            }
          }
        }
      }
    }
