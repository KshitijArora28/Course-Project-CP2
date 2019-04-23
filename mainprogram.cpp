#include <iostream>
#include <string>
struct product{
  string code;
  string name;
  int quantity;
  int number_sold;
  char expiry_date[8];
  double cost;
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
