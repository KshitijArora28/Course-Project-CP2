
void economic(int n,product *p){
  int time_period;
  cout<<"Enter the time period (in number of days) for which the data has been collected: ";
  cin>>time_period;
  double *profit_list=new double[n];
  double *quantity_sold=new double[n];

  for (int i=1;i<n;i++){
    cout<<endl<<p[i].name<<" (Product code- "<<p[i].code<<") "<<"quantity sold in "<<time_period<<" days = "<<p[i].number_sold<<endl;
    cout<<"net profit in "<<time_period<<" days = "<<(p[i].selling_cost-p[i].cost)*p[i].number_sold<<endl;
    cout<<"Predicted Requirement (quantity) for next month (30 days) = "<<ceil((p[i].number_sold/time_period)*30)<<endl;
    profit_list[i]=(p[i].selling_cost-p[i].cost)*p[i].number_sold;
    quantity_sold[i]=p[i].number_sold;
  }

  int least_profitable=1;
  int least_sold=1;
  int most_profitable=1;
  int most_sold=1;
  for (int i=1;i<n;i++){
    if (profit_list[i]<profit_list[least_profitable]){
      least_profitable=i;
    }
  }
  cout<<endl<<"Product with least profit: "<<p[least_profitable].name<<" (Product code- "<<p[least_profitable].code<<") "<<endl;
  for (int i=1;i<n;i++){
    if (profit_list[i]>profit_list[most_profitable]){
      most_profitable=i;
    }
  }
  cout<<"Product with most profit: "<<p[most_profitable].name<<" (Product code- "<<p[most_profitable].code<<") "<<endl;
  for (int i=1;i<n;i++){
    if (quantity_sold[i]<quantity_sold[least_sold]){
      least_sold=i;
    }
  }
  cout<<"Product with least quantity sold: "<<p[least_sold].name<<" (Product code- "<<p[least_sold].code<<") "<<endl;
  for (int i=1;i<n;i++){
    if (quantity_sold[i]>quantity_sold[most_sold]){
      most_sold=i;
    }
  }
  cout<<"Product with most quantity sold: "<<p[most_sold].name<<" (Product code- "<<p[most_sold].code<<") "<<endl;
  cout<<"*Disclaimer* - There maybe other products with the same amount in profit or quantity sold; the above statistics are"<<endl<<"solely meant to portray one product of each extreme category."<<endl;
}
