#include <iostream>
#include <string>
struct product{
  string code;
  string name;//given by user
  int quantity;//given by user
  int number_sold;
  char expiry_date[10];//given by user
  double cost;//gven by user
};
int main(){
  char choice;
  cout<<"Enter choice"<<endl;
  cout<<"D->Display inventory"<<endl;
  cout<<"I->Insert new commodities"<<endl;
  cout<<"C->Change commodity info"<<endl;
  cout<<"R->Remove commodity"<<endl;
  cout<<"E->Economic advise based on stock data"<<endl;
  cout<<"S->Search item"<<endl;
  cout<<"O->Sort items alpahbetically"<<endl;
  cout<<"T->Terminate code"<<endl;

  switch(choice){
    //switch (/* expression */) {
      case /* value */:
    }
  }
}
