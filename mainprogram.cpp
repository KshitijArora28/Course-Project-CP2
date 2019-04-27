#include <iostream>
#include <string>
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

int main(){
  cout<<"**Welcome to Inventory Management System**"<<endl;
  char choice;
  cout<<"Enter choice"<<endl;
  cout<<"Choices for Operation are :-"<<endl;
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
    int n;
    string nm;
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
