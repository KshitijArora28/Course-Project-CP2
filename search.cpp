#include <iostream>
#include <string>
using namespace std;

void search(int n,product* prod){
  string *search_list=new string[n];
  char key;
  cout>>"Search by:-">>endl;
  cout>>"a. Name (case sensitive)">>endl;
  cout>>"b. Product Code">>endl;
  cout>>"Enter a or b: ";
  cin>>key;
  if (key=='a'){
    cout<<"Searching under names. Enter name: "<<endl;
  }
  else if(key=='b'){
    cout<<"Searching under product code. Enter code: "<<endl;
  }
  string search_item;
  cin<<search_item;
  int list_position=0;
  if (key=='a'){
      for (int i=0;i<n;i++){
        if(prod[i].name.find(search_item)!=string::npos){
          search_list[list_position]=prod[i];
          list_position++;
        }
      }
  }
  else if(key=='b'){
    for (int i=0;i<n;i++){
      if(prod[i].code.find(search_item)!=string::npos){
        search_list[list_position]=prod[i];
        list_position++;
      }
    }
  }
  else{
    cout<<"Invalid option."<<endl;
    return;
  }
  if (list_position==0){
    cout<<"No valid search result."
  }
  else{
    cout<<"Search Results are: "<<endl;
    for (int i=0;i<list_position;i++){
      cout<<search_list[i]<<endl;
    }
  }
}
