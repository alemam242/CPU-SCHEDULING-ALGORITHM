#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Number of Processor: ";
    cin>>n;
    int CPUT[n],WT[n]= {0},TT[n],AT[n],PRO[n+2],TCPUT[n],counter=0,timer=0,smalest=9;
    float avgW=0,sumW=0,avgT=0,sumT=0;

    for(int i=0; i<n; i++)
    {
        cout<<"CPU Time of P "<<i+1<<": ";
        cin>>CPUT[i];
        TCPUT[i]=CPUT[i];

        cout<<"AT Time of P "<<i+1<<": ";
        cin>>AT[i];
    }

    CPUT[smalest]=9999;
    for(timer=0; counter!=n; timer++)
    {
        smalest=9;
        for(int i=0; i<n; i++)
        {
            if(AT[i]<=timer && CPUT[i]<CPUT[smalest] && CPUT[i]>0)
            {
                smalest=i;
            }
        }

        CPUT[smalest]--;
        if(CPUT[smalest]==0)
        {
            counter++;
            int endcounter;
            endcounter=timer+1;
            TT[smalest]=endcounter-AT[smalest];
            //cout<<"timer: "<<timer<<endl;
        }

    }



    for(int i=0; i<n; i++)
    {
        cout<<"TT of "<<i+1<<": "<<TT[i]<<endl;
    }


    for(int j=0; j<n; j++)
    {
        WT[j]=TT[j]-TCPUT[j];
        cout<<"WT of "<<j+1<<": "<< WT[j]<<endl;
    }

    return 0;
}
