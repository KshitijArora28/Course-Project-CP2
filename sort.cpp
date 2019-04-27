//alphabetical
//product code
include <iostream>
include <string>

void sort(int n,program *p){
  struct node{
      program details;
      node *next;
  };
  node *head=new node
  node *current=head;
  for (int i=1;i<n;i++){
    current->details=p[i];
    node *q=new node;
    current->next=q;
    current=q;
  }

}
