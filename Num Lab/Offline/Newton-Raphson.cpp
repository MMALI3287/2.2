#include<bits/stdc++.h>
using namespace std;
double fx(int func[],int n,double x)
{
    double result = func[n];
    for(int i=n-1;i>=0;i--)
    {
        result = result*x + func[i];
    }
    return result;
}

int main()
{
    cout<<"Enter the total no. of power::: ";
    int n;
    cin>>n;
    int poly[n+1];
    int der[n];
    cout<<"Enter the co-efficients of the polynomial:"<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<"x^"<<i<<"::";
        cin>>poly[i];
    }
    cout<<"The polynomial is :::  ";
    for(int i=n;i>=0;i--)
    {
        if(i!=n && poly[i]>=0)
            cout<<"+";
        cout<<poly[i]<<"x^"<<i<<" ";
    }
    cout<<"Enter the co-efficients of the derivative:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"x^"<<i<<"::";
        cin>>der[i];
    }
    cout<<"The derivative is :::  ";
    for(int i=n-1;i>=0;i--)
    {
        if(i!=n && der[i]>=0)
            cout<<"+";
        cout<<der[i]<<"x^"<<i<<" ";
    }
    cout<<"Intital x0---->";
    double x0;
    cin>>x0;
    cout<<"Tolerable error---->";
    double e;
    cin>>e;
    double x1;
    cout<<"****************************************"<<endl;
    cout<<"   ITERATION   X1    FX1    F'X1 "<<endl;
    cout<<"****************************************"<<endl;
    int iter = 1;
    double f1;
    cout<<setprecision(4)<<fixed;
    do
    {
        if(fx(der,n,x0)==0.0)
        {
            cout<<"mathematical error"<<endl;
            break;
        }
        x1 = x0 - fx(poly,n,x0)/fx(der,n-1,x0);
        x0 = x1;
        f1 = fx(poly,n,x1);
        cout<<"  "<<iter++<<"  "<<x1<<"  "<<f1<<"  "<<fx(der,n-1,x1)<<endl;
    }while(f1>e);
    cout<<"Root = "<<x1<<endl;
    return 0;
}
