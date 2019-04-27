void Change(prouct &* p1[],nm1,q1,c1,c2,e1,e2,e3,s){
  for(int i=1;i<s;i++){
    if(p1[i].name==nm1){
      if(q1!=0){
        p1[i].quantity=q1;
      }
      if(c1!=0){
        p1[i].cost=c1;
      }
      if(c2!=0){
        p1[i].selling_cost=c2;
      }
      if(e1!==){
        p1[i].e_dd=e1;
      }
      if(e2!==){
        p1[i].e_mm=e2;
      }
      if(e3!==){
        p1[i].e_year=e3;
      }
    }
  }
}
