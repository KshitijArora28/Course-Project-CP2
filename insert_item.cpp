void insert_item.cpp(product &* p1[],&m1,&m2){
  product * temp;
  if(m2>m1){
    temp=new product[m2];
    for(int i=0;i<m1;i++){
      temp[i]=p1[i];
    }
    delete [] p1;
    p1=temp;
    for(int j=m1;j<m2;j++){
      cout<<"Please enter details for new item"<<j<<endl;
      cout<<"Enter product name: -"<<endl;
      cin>>p1[j].name;
      cout<<"Enter product quantity: -"<<endl;
      cin>>p1[j].quantity;
      cout<<"Enter product expiry date"<<endl;
      cin>>p1[j].expiry_date;
      cout<<"Enter product cost"<<endl;
      cin>>p1[j].cost;
    }
    m1=m2;
  }
}
