#include <iostream>
#include <string>
using namespace std;
struct product{
  string code;
  string name;//given by user
  int quantity;//given by user
  int number_sold;
  int e_dd,e_mm,e_year;//expiry date given by user
  double cost;//gven by user
  double selling_cost;//gven by user
};

int main(){
  char choice;
  cout<<"Choices for Operation"<<endl;
  cout<<"D->Display inventory"<<endl;
  cout<<"I->Insert new commodities"<<endl;
  cout<<"C->Change commodity info"<<endl;
  cout<<"R->Remove commodity"<<endl;
  cout<<"E->Economic advise based on stock data"<<endl;
  cout<<"S->Search for an item"<<endl;
  cout<<"O->Sort items"<<endl;
  cout<<"T->Terminate code"<<endl;
  cout<<"Enter choice: ";
  cin>>choice;
  int or_size=0;
  int new_size=0;
  product * p[]=new product[0];
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
      cout<<"Enter new expiry date"<<endl;
      cout<<"If new and old expiry date are same enter N"<<endl;
      string e;
      cin>>e;
      change(p,nm,q,c,e,or_size);
      break;

      case 'S':
      search(or_size,p)
      break

      case 'O':
      sort(or_size,p)

      case 'E':
      void economic(int n,product *p)
      break

    }
  cout<<"Enter next choice:"<<endl;
  cout<<"D->Display inventory"<<endl;
  cout<<"I->Insert new commodities"<<endl;
  cout<<"C->Change commodity info"<<endl;
  cout<<"R->Remove commodity"<<endl;
  cout<<"E->Economic advise based on stock data"<<endl;
  cout<<"S->Search item"<<endl;
  cout<<"O->Sort items alpahbetically"<<endl;
  cout<<"T->Terminate code"<<endl;
  cin>>choice;
  }
  return 0;
}
