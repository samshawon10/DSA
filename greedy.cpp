#include<iostream>
#include<vector>
#include<algorithm>
 using namespace std;

 class activity
 {
 public:
          int start_time,finish_time;
          activity(int s, int f):start_time(s),finish_time(f){}

void display()
{
 cout<<"start time:"<<start_time<<" finish time:"<<finish_time<<endl;
}
 };

 bool cmpract(activity a1,activity a2)
 {
           return a1.finish_time<a2.finish_time;
 }


 void activityselection(vector<activity> activities)
 {
           sort(activities.begin(),activities.end(),cmpract);
           cout<<"After sorting"<<endl;

           for( activity a:activities)
           {
                     a.display();
           }

      vector<activity> selected ;
      selected.push_back(activities[0]);
      int l =0;
      int cnt=1;

      for(int m=1;m<activities.size();m++)
      {
                if(activities[l].finish_time+1 <= activities[m].start_time)
                {


                    selected.push_back(activities[m]);
                l=m;
                cnt++;
                }
      }
      cout<<"Maximum no of activities: "<<cnt<<endl;
      cout<<"Selected activities: "<<endl;
      for(activity a :selected)
      {
                a.display();
      }

 }

 int main()
 {
   vector<activity> activitylist={
   activity(8,12),activity(9,10),activity(8,10),activity(11,13),activity(10,12),activity(13,15)
   };
    activityselection(activitylist);
 }
