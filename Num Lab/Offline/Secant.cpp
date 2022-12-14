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
    cout<<"Intital x1---->";
    double x1;
    cin>>x1;
    cout<<"Intital x0---->";
    double x0;
    cin>>x0;
    cout<<"Tolerable error---->";
    double e;
    cin>>e;
    cout<<"*******************************************"<<endl;
    cout<<"   ITERATION   x1   x2   x3   f(x1)   f(x2)"<<endl;
    cout<<"*******************************************"<<endl;
    int iter = 1;
    double f1;
    cout<<setprecision(4)<<fixed;
    double x2;
    do
    {
        double fx0 = fx(poly,n,x0);
        double fx1 = fx(poly,n,x1);
        x2 = (x0 * fx1 - x1 * fx0)/(fx1 - fx0);
        cout<<"  "<<iter++<<"  "<<x0<<"  "<<x1<<"  "<<x2<<"  "<<fx0<<"  "<<fx1<<endl;
        x0 = x1;
        x1 = x2;
    }while(fabs(fx(poly,n,x2))>e);
    cout<<"Root = "<<x2<<endl;
    return 0;
}

