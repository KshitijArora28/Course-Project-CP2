#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

struct product{
  string code;
  string name;//given by user
  int quantity=0;//given by user
  int number_sold=0;
  int e_dd=0,e_mm=0,e_year=0;//expiry date given by user
  char stock='O';
  double cost=0;//given by user
  double selling_cost=0;//gven by user
};


void insert_item(product * &p1,int &m1,int &m2){
  product * temp;
  if(m2>m1){
    temp=new product[m2];
    for(int i=1;i<m1;i++){
      temp[i]=p1[i];
    }
    delete [] p1;
    p1=temp;
   }
    for(int j=m1;j<m2;j++){
      cout<<"Please enter details for new item"<<j<<endl;
      cout<<"Enter product name: -"<<endl;
      cin>>p1[j].name;
      cout<<"Enter product quantity: -"<<endl;
      cin>>p1[j].quantity;
      cout<<"Enter product expiry date: -"<<endl;
      cin>>p1[j].e_dd>>p1[j].e_mm>>p1[j].e_year;
      cout<<"Enter product cost: -"<<endl;
      cin>>p1[j].cost;
      cout<<"Enter product selling price: -"<<endl;
      cin>>p1[j].selling_cost;
      p1[j].stock='I';
    }
    m1=m2;
}

void code(int n,product *&p){
  for (int i=1;i<n;i++){
    int f=i%1000;
    stringstream num;
    num<<f;
    string num_string=num.str();
    if (num_string.length()==1){
      num_string.insert(0,"00");
    }
    if (num_string.length()==2){
      num_string.insert(0,"0");
    }
    p[i].code=p[i].name.substr(0,3)+num_string;
  }
}

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

void stock(product * &p1,string f1,int s1){
  for(int i=1;i<s1;i++){
    if(p1[i].name==f1){
      p1[i].number_sold=rand() % 100;
      if(p1[i].number_sold<=p1[i].quantity){
        p1[i].quantity=p1[i].quantity-p1[i].number_sold;
      }
      if(p1[i].number_sold>p1[i].quantity){
        cout<<"Purchase quantity is "<<p1[i].number_sold<<" which is more than stock !"<<endl;
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
      cout<<"Stock left is "<<p1[i].quantity<<endl;
      cout<<endl;
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

void alerts(product * &p,int n){
  cout<<endl<<"**ALERTS**"<<endl;
  cout<<endl;
  for (int i=1;i<n;i++){
    if (p[i].quantity<5){
      if (p[i].stock=='O'){
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
    if (p[i].e_year-1900<=gmtm->tm_year && p[i].e_year!=0){
      if (p[i].e_year-1900<gmtm->tm_year){
        cout<<p[i].name<<" expiry date is up."<<endl;
        cout<<endl;
        continue;
      }
      if(p[i].e_mm-1<=gmtm->tm_mon){
        if(p[i].e_mm-1<gmtm->tm_mon){
          cout<<p[i].name<<" expiry date is up."<<endl;
          cout<<endl;
          continue;
        }
        if(p[i].e_dd<gmtm->tm_mday){
          cout<<p[i].name<<" expiry date is up."<<endl;
          cout<<endl;
        }
      }
    }
  }
}

void economic(int n,product * &p){
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
      fout<<setw(w+4)<<"Name"<<setw(10)<<"Code"<<setw(10)<<"Stock"<<setw(10)<<"Cost"<<setw(14)<<"Sellprice"<<setw(10)<<"Sales"<<setw(14)<<"Expiry date"<<endl;
      cout<<setw(w+4)<<"Name"<<setw(10)<<"Code"<<setw(10)<<"Stock"<<setw(10)<<"Cost"<<setw(14)<<"Sellprice"<<setw(10)<<"Sales"<<setw(14)<<"Expiry date"<<endl;
      cout<<endl;
      for(int j=1;j<n1;j++){
        fout<<setw(w+4)<<p1[j].name<<setw(10)<<p1[j].code<<setw(10)<<p1[j].quantity<<setw(10)<<p1[j].cost<<setw(14)<<p1[j].selling_cost<<setw(10)<<p1[j].number_sold<<setw(10)<<p1[j].e_dd<<" "<<p1[j].e_mm<<" "<<p1[j].e_year<<endl;
        cout<<setw(w+4)<<p1[j].name<<setw(10)<<p1[j].code<<setw(10)<<p1[j].quantity<<setw(10)<<p1[j].cost<<setw(14)<<p1[j].selling_cost<<setw(10)<<p1[j].number_sold<<setw(10)<<p1[j].e_dd<<" "<<p1[j].e_mm<<" "<<p1[j].e_year<<endl;
      }
      fout.close();
    }

    int main(){
      char choice;
      cout<<"Enter choice"<<endl;
      cout<<"Choices for Operation"<<endl;
      cout<<"D->Display inventory"<<endl;
      cout<<"I->Insert new commodities"<<endl;
      cout<<"C->Change commodity info"<<endl;
      cout<<"R->Remove commodity"<<endl;
      cout<<"E->Economic advise based on stock data"<<endl;
      cout<<"S->Search item"<<endl;
      cout<<"O->Sort items alpahbetically"<<endl;
      cout<<"Q->Sell and check stock"<<endl;
      cout<<"T->Terminate code"<<endl;
      cin>>choice;
      int or_size=1;
      int new_size;
      product * p=new product[or_size];

      while(choice!='T'){
        string nm;
        int n;
        int q;
        int c;
        int sp;
        int ed;
        int em;
        int ey;
        string s;
        string f;
      switch(choice){
          case 'I':
          cout<<"Enter the number of commodities to be appended: -"<<endl;
          cin>>n;
          new_size=or_size+n;
          insert_item(p,or_size,new_size);
          code(or_size,p);
          break;

          case 'C':
          cout<<"Enter product name to change info (case-sensitive): -"<<endl;
          cin>>nm;
          cout<<"Enter new quantity: -"<<endl;
          cout<<"(If new and old quantity are same enter 0)"<<endl;

          cin>>q;
          cout<<"Enter new cost: -"<<endl;
          cout<<"(If new and old cost are same enter 0)"<<endl;

          cin>>c;
          cout<<"Enter new selling price: -"<<endl;
          cout<<"(If new and old selling price are same enter 0)"<<endl;

          cin>>sp;
          cout<<"Enter new expiry date: -"<<endl;
          cout<<"(If new and old expiry date are same enter 0)"<<endl;

          cin>>ed;
          cout<<"Enter new expiry month: -"<<endl;
          cout<<"(If new and old expiry month are same enter 0)"<<endl;

          cin>>em;
          cout<<"Enter new expiry year: -"<<endl;
          cout<<"(If new and old expiry year are same enter 0)"<<endl;

          cin>>ey;
          Change(p,nm,q,c,sp,ed,em,ey,or_size);
          break;

          case 'R':
          cout<<"Enter product name to delete: -"<<endl;

          cin>>s;
          delete_commodity(p,or_size,s);
          break;

          case 'Q':
          cout<<"Enter product name to check sales and new stock: -"<<endl;

          cin>>f;
          stock(p,f,or_size);
          break;

          case 'D':
          display(p,or_size);
          break;

          case 'S':
          search(or_size,p);
          break;

          case 'O':
          defsort(or_size,p);
          break;

          case 'E':
          economic(or_size,p);
          break;

          default:
          cout<<"Invalid input"<<endl;
        }
      cout<<endl<<"Enter next choice:"<<endl;
      cout<<"D->Display inventory"<<endl;
      cout<<"I->Insert new commodities"<<endl;
      cout<<"C->Change commodity info"<<endl;
      cout<<"R->Remove commodity"<<endl;
      cout<<"E->Economic advise based on stock data"<<endl;
      cout<<"S->Search item"<<endl;
      cout<<"O->Sort items alpahbetically"<<endl;
      cout<<"Q->Sell and check stock"<<endl;
      cout<<"T->Terminate code"<<endl;
      cin>>choice;
      }
      delete [] p;
      exit(1);
    }
