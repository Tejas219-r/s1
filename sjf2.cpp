#include<iostream>   //wrong
#include<cstring>
using namespace std;
class schedule
{
 public:
   int A[10],B[10],n,WT[10],TAT[10],pr[10];
   string P[10];
   schedule()
    {
     for(int i=0;i<n;i++)
       {
        A[i]=B[i]=WT[i]=TAT[i]=0;
       }
    }
   void getdata();
   void show();
   void sort();
   void calculate(); 
};
void schedule::getdata()
{ 
  cout<<"\nenter the number of processes:";
  cin>>n;
 { 
   for(int i=0;i<n;i++)
      {
      cout<<"\nEnter the process:";
      cin>>P[i]; 
      
      cout<<"\nenter the burst time for process:";
      cin>>B[i];
      cout<<"\nEnter the priority";
      cin>>pr[i];
      
      } 
    }
}
void schedule::show()
{
  cout<<"\nPN\tBt\tpr \tWT\tTAT";
  for(int i=0;i<n;i++)
  {
   cout<<"\n"<<P[i]<<"\t"<<B[i]<<"\t"<<pr[i]<<"\t"<<WT[i]<<"\t"<<TAT[i]<<"\n";
  }
}
void schedule::sort()
{
 for(int i=0;i<n;i++)
   {
     for(int j=i+1;j<n;j++)
       {
          if(pr[i]>pr[j])
            {
               string temp=P[i];
               P[i]=P[j];
               P[j]=temp;
               
               int temp1=pr[i];
               pr[i]=pr[j];
               pr[j]=temp1;
               
               int temp2=B[i];
               B[i]=B[j];
               B[j]=temp2;

            }
       } 
   }
}
void schedule::calculate()
{
  sort();
 WT[0]=0;
 for(int j=0;j<n;j++)
  {
    TAT[j]=WT[j]+B[j];
    WT[j+1]=TAT[j];
  }

}
int main()
{
schedule s;
s.getdata();
s.calculate();
s.show();

return 0;
}
