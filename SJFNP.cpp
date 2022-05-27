#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Number of Processor: ";
    cin>>n;
    int CPUT[n],WT[n]={0},TT[n],AT[n],PRO[n+2];
    float avgW=0,sumW=0,avgT=0,sumT=0;

    for(int i=0;i<n;i++)
    {
        PRO[i]=i+1;
        cout<<"CPU Time of P "<<i+1<<": ";
        cin>>CPUT[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(CPUT[i]>CPUT[j])
            {
                int tmp=CPUT[i];
                CPUT[i]=CPUT[j];
                CPUT[j]=tmp;

                int tmp2=PRO[i];
                PRO[i]=PRO[j];
                PRO[j]=tmp2;
            }
        }
    }

    for(int i=1;i<n;i++)
    {
        WT[i]=CPUT[i-1]+WT[i-1];
    }

    for(int i=0;i<n;i++)
    {
        TT[i]=CPUT[i]+WT[i];
    }


    cout<<"P CPU WT TT"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<PRO[i]<<" "<<CPUT[i]<<" "<<WT[i]<<" "<<TT[i]<<endl;
    }

    for(int i=0;i<n;i++)
    {
        sumW+=WT[i];
        sumT+=TT[i];
    }

    avgT=sumT/n;
    avgW=sumW/n;

    cout<<"WT Avg: "<<avgW<<endl;
    cout<<"TT Avg: "<<avgT<<endl;

    cout<<"\n|";
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<PRO[i]<<"|";
    }

    cout<<"\n0 ";
     for(int i=0;i<n;i++)
    {
        cout<<" "<<TT[i];
    }

    return 0;
}

