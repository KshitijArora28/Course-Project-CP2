void Change(prouct &* p1[],nm1,q1,c1,e1,s){
  for(int i=0;i<s;i++){
    if(p1[i].name==nm1){
      if(q1!=0){
        p1[i].quantity=q1;
      }
      if(c1!=0){
        p1[i].cost=c1;
      }
      if(e1!="N"){
        p1[i].expiry_date=e1;
      }
    }
  }
}
