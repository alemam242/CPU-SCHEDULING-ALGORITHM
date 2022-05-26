#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Number of process: ";
    cin >> n;
    int p[n], cpu[n], pr[n], tat[n], wt[n], gc[n + 1];
    gc[0] = wt[0] = 0;

    int totalwt=0,totaltat=0;
    double avgwt=0,avgtat=0;
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        cout << "CPU time of P" << p[i] << ": ";
        cin >> cpu[i];
        cout << "Priority of P" << p[i] << ": ";
        cin >> pr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                swap(pr[i],pr[j]);
                swap(p[i],p[j]);
                swap(cpu[i],cpu[j]);

            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        gc[i] = gc[i - 1] + cpu[i - 1];
    }

    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + cpu[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = cpu[i] + wt[i];
    }

    cout << "Giant Chart: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "| P" << p[i] << "\t";
    }
    cout << "|" << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << gc[i] << "\t";
    }
    cout << endl;
    cout << "\nPRO\tCPU\tWT\tTAT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t" << cpu[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        totalwt+=wt[i];
        totaltat+=tat[i];
    }
    avgwt=(double)totalwt/n;
    avgtat=(double)totaltat/n;
    cout << "Average Waiting Time: " << avgwt << endl;
    cout << "Average Turn Around Time: " << avgtat << endl;
}
