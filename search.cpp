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
      if(prod[i].stock=='i'){
        search_list[list_position]=prod[i].name;
        list_position++;
      }
    }
  }
  else if(key=='d'){
    for (int i=1;i<n;i++){
      if(prod[i].stock=='o'){
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
