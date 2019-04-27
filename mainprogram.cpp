#include <iostream>
#include <string>
#include <cstdlib>

struct product{
  string code;
  string name;//given by user
  int quantity;//given by user
  int number_sold;
  string expiry_date;//given by user
  double cost;//gven by user
  char stock;
  int stk;
  int sales;
};

int main(){
  char choice;
  cout<<"Enter choice:"<<endl;
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
  product * p[]=new product[1];
  while(choice!='T'){
  switch(choice){
    //switch (/* expression */) {
      case 'I':
      int n;
      cout<<"Enter the number of commodities to be appended: -"<<endl;
      cin>>n;
      new_size=or_size+n;
      insert_item(p,or_size,new_size);
      break;

      case 'C':
      cout<<"Enter product name to change info: -"<<endl;
      string nm;
      cin>>nm;
      cout<<"Enter new quantity"<<endl;
      cout<<"If new and old quantity are same enter 0"<<endl;
      int q;
      cin>>q;
      cout<<"Enter new cost"<<endl;
      cout<<"If new and old cost are same enter 0"<<endl;
      int c;
      cin>>c;
      cout<<"Enter new expiry date"<<endl;
      cout<<"If new and old expiry date are same enter N"<<endl;
      string e;
      cin>>e;
      change(p,nm,q,c,e,or_size);
      break;

      case 'R':
      cout<<cout<<"Enter product name to delete: -"<<endl;
      string s;
      cin>>n;
      delete_commodity(p,or_size,s);
      break;

      case 'Q':
      cout<<"Enter product name to check stock: -"<<endl;
      string f;
      cin>>f;
      stock(p,f,or_size);
      break;
    }
  cout<<"Enter next choice:"<<endl;
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
  return 0;
}

