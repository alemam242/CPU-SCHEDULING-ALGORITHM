#include<bits/stdc++.h>
using namespace std;
int main()
{
    int bn;
    cout << "Enter number of Block: ";
    cin>>bn;
    int bsize[bn],tmpbsize[bn];
    for(int i=0;i<bn;i++)
    {
        cout << "Size of B" << i+1 << ": ";
        cin>>bsize[i];
        tmpbsize[i]=bsize[i];
    }
    int pn;
    cout << "Enter number of Processor: ";
    cin>>pn;
    int psize[pn],fit[pn];
    for(int i=0;i<pn;i++)
    {
        fit[i]=-1;
        cout << "Size of P" << i+1 << ": ";
        cin>>psize[i];
    }

    for(int i=0;i<pn;i++)
    {
        for(int j=0;j<bn;j++)
        {
            if(psize[i]<=bsize[j])
            {
                fit[i]=j;
                bsize[j]-=psize[i];
                break;
            }
        }
    }

    cout << "Pro\tBlock\tSize\n";
    for(int i=0;i<pn;i++)
    {
        if(fit[i]!=-1)
        {
            cout << "P"<<i+1<<"\t"<<fit[i]<<"\t"<<tmpbsize[fit[i]] << endl;
        }
        else
        {
            cout << "P" << i+1 << "\tNot Allocated\n";
        }
    }
    //sort(bsize,bsize+bn); /// Ascending order
    //sort(bsize,bsize+bn,greater<int>()); /// Descending order

    //for(int i=0;i<bn;i++)
    //{
        //cout << bsize[i] << " ";
    //}
}
