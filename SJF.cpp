#include<iostream>
using namespace std;
class sjf
{
    public:
        string P[10];
        int A[10],B[10],W[10],C[10],T[10],n;
        int temp,temp1;
    void getdata()
    {
        cout<<"enter the no.of processess : ";
        cin>>n;

        for(int i=0;i<n;i++)
        {   
            cout<<"\nEnter the name of the process : ";
            cin>>P[i];
            cout<<"\nEnter the Burst time of the process :";
            cin>>B[i];
            cout<<"\nEnter the Arrival time of the process :";
            cin>>A[i];
        }

        

    }
    void sort()
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;i<n;i++)
            {
                if(A[i]>A[j])
                {
                    temp=A[i];
                    A[i]=A[j];
                    A[j]=temp;

                    string tempo=P[i];
                    P[i]=P[j];
                    P[j]=tempo;

                    temp=B[i];
                    B[i]=B[j];
                    B[j]=temp;
                    
                }
            }
        }
    }
    void show()
    {
        int i=0;
        cout<<"GANTT CHART";
        cout<<"\n0\t"<<P[i]<<"\t"<<B[i];
        cout<<"\n\nPROCESS\t BURST\t ARRIVAL \n";
        for(i=0;i<n;i++)
        {
          
          cout<<P[i]<<"  \t"<<B[i]<<"  \t "<<A[i];
          cout<<"\n";
        }
    }
    void bsort()
    {
        for(int i=1;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(B[i]>B[j])
                {
                    temp=B[i];
                    B[i]=B[j];
                    B[j]=temp;

                    temp=A[i];
                    A[i]=A[j];
                    A[j]=temp;

                    string tempo=P[i];
                    P[i]=P[j];
                    P[j]=tempo;
                }
            }
        }
    }
    void calculate()
    {
        int sum=0;
        for(int i=0;i<n;i++)    //Turnaround Time
        {
            sum=sum+B[i];
            T[i]=sum;
        
        }
        for(int i=0;i<n;i++)    // Completion time
        {
           C[i]=T[i]-A[i];
        }

        for(int i=0;i<n;i++)    // Waiting time
        {
            W[i]=C[i]-B[i];
        }
    }
    void lastshow()
    {
        cout<<"\nPROCESS\tBURST\tARRIVAL\t WAITING\t\tCOMPLETION\tTURNAROUND\n";
        for(int i=0;i<n ;i++)
        {
            cout<<"  "<<P[i]<<"\t   "<<B[i]<<"  \t   "<<A[i]<<"\t    "<<W[i]<<"   \t   "<<C[i]<<"  \t\t  "<<T[i];
            cout<<"\n";
        }
    }

};
int main()
{
    sjf ob;
    ob.getdata();
    ob.sort();
    ob.bsort();
    ob.show();
    ob.calculate();
    ob.lastshow();
    return(0);
}