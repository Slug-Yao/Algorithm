#include<iostream>
using namespace std;

double bsearch(double x)
{
    const double eps=1e-6;
    double l=-x,r=x;
    while(l<r)
    {
        double mid=(l+r)/2;
        if(mid*mid>=x)r=mid;
        else l=mid;
    }
    return l;
     
}

int main()
{
    double bsearch(double x);
    double n;
    cin>>n;
    cout<<bsearch(n);

}