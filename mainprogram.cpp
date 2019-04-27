#include <iostream>
#include <string>

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

int main(){
  char choice;
  cout<<"Choices for Operation"<<endl;
  cout<<"D->Display inventory"<<endl;
  cout<<"I->Insert new commodities"<<endl;
  cout<<"C->Change commodity info"<<endl;
  cout<<"R->Remove commodity"<<endl;
  cout<<"E->Economic advise based on stock data"<<endl;
  cout<<"S->Search item"<<endl;
  cout<<"O->Sort items alpahbetically"<<endl;
  cout<<"Q->Sell and check stock"<<endl;
  cout<<"T->Terminate code"<<endl;  cin>>choice;
  int or_size=1;
  int new_size;
  product * p[]=new product[1];

  while(choice!='T'){
  switch(choice){
      case 'I':
      int n;
      cout<<"Enter the number of commodities to be appended: -"<<endl;
      cin>>n;
      new_size=or_size+n;
      insert_item(p,or_size,new_size);
      break;

      case 'C':
      cout<<"Enter product name to change info (case-sensitive): -"<<endl;
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
      cout<<"Enter new selling price"<<endl;
      cout<<"If new and old selling price are same enter 0"<<endl;
      int sp;
      cin>>sp;
      cout<<"Enter new expiry date"<<endl;
      cout<<"If new and old expiry date are same enter 0"<<endl;
      int ed;
      cin>>ed;
      cout<<"Enter new expiry month"<<endl;
      cout<<"If new and old expiry month are same enter 0"<<endl;
      int em;
      cin>>em;
      cout<<"Enter new expiry year"<<endl;
      cout<<"If new and old expiry year are same enter 0"<<endl;
      int ey;
      cin>>ey;
      change(p,nm,q,c,sp,ed,em,ey,or_size);
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

      case 'D':
      display(p,or_size);
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
