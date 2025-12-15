#include<iostream>
#include<vector>
#include<algorithm>
 using namespace std;



 class Item
 { public :
           string name;
           double weight,value,per_unit_value;

           Item(string n,double w,double v):name(n),weight(w),value(v),per_unit_value(v/w){}

           void display()
           {
                     cout<<"name:"<<name<<" W:"<<weight<<" V:"<<value<<" Per unit value:"<<per_unit_value<<endl;
           }


 };
 bool cmpr(Item a1 ,Item a2)
 {
           return a1.per_unit_value>a2.per_unit_value;
 }

 void knapsack(vector<Item> itemlist,int n, int W)
 {
           sort(itemlist.begin(),itemlist.end(),cmpr);
           cout<<"After sorting"<<endl;
           for(Item it :itemlist) it.display();

           cout<<"Selected Items"<<endl;
           int i=0;
           double profit=0;
           while(W>0 && i<n)
           {
                     if(itemlist[i].weight<W)
                     {

                               profit+=itemlist[i].value;
                               W=W-itemlist[i].weight;
                               itemlist[i].display();
                     }
                     else{
                              int weight_taken=W;
                              double p=weight_taken*itemlist[i].per_unit_value;
                              profit+=p;
                              W=0;

                              string name= itemlist[i].name;
                              double unite_value= itemlist[i].per_unit_value;
                              cout<<"name:"<<name<<" W:"<<weight_taken<<" v:"<<p<<" unite value"<<unite_value<<endl;
                     }
                     i++;

           }
           cout<<"Maximum Profit: "<<profit<<endl;

 }




 int main()
 { vector<Item> items={
 Item("Potato",3,60),Item("Onion",2,160),Item("Sugar",3,300),Item("Salt",6,90)

 };

 int n=items.size();
 int W=20;
 knapsack(items,n,W);

 }
