//Alphabetical
//product Code
//stock low to high
//reverse

void sort(int n,product *&p){
  struct node{
    product details;
    product* next;
  }
  node *head=new node;
  head->details=p[0];
  node *current=head
  for (int i=1;i<n;i++){
    product *q=new node;
    q->details=p[i];
    current->next=q;
    current=q;
  }
  current=head;
  string key;
  cout<<"Sort in the order of:"<<endl;
  cout<<"a.Alphabetical order of the name."<<endl;
  cout<<"b.Product Code order.(lexicographical order)"<<endl;
  cout<<"c.Stock left.(Highest to Lowest)"<<endl;
  cout<<"d.Reverse the current order."<<endl;
  cout<<"Enter a,b,c or d: "<<endl;
  cin>>key;
  switch(key){
    case 'a':
      for(int i=0;i<n;i++){
        string min=p[i];
        for(int j=0;j<=i;j++){
          if(min.compare(p[j])>0){
            min=p[j]
          }
        }
      }
    case 'b':

    case 'c':

    case 'd':

  }
}
