#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Number of process: ";
    cin >> n;
    int pr[n], bt[n], at[n], tat[n], wt[n], ct[n + n];
    double avgct = 0, avgwt = 0, avgtat = 0;
    tat[0] = wt[0] = ct[0] = 0;
    for (int i = 0; i < n; i++)
    {
        pr[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time for p" << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter burst time for p" << i + 1 << ": ";
        cin >> bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (at[i] == 0)
        {
            continue;
        }
        else
        {
            for (int j = i + 1; j < n; j++)
            {

                if (bt[i] > bt[j])
                {
                    int t = bt[j];
                    bt[j] = bt[i];
                    bt[i] = t;

                    t = pr[j];
                    pr[j] = pr[i];
                    pr[i] = t;

                    t = at[j];
                    at[j] = at[i];
                    at[i] = t;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << pr[i] << "  " << bt[i] << endl;
    }
    // findout ct and avgct
    for (int i = 1; i <= n; i++)
    {
        ct[i] = ct[i - 1] + bt[i - 1];
        avgct += ct[i];
    }
    //
    for (int i = 1; i <= n; i++)
    {
        cout << ct[i] << " ";
    }
    cout << "\navgct: " << avgct / n << endl;
    // findout wt and avg wt
    for (int i = 0; i < n; i++)
    {
        wt[i] = ct[i] - at[i];
        avgwt += wt[i];
    }
    //
    for (int i = 0; i < n; i++)
    {
        cout << wt[i] << " ";
    }
    cout << "\navgwt: " << avgwt / n << endl;
    // findout tat and avg tat
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avgtat += tat[i];
    }
    //
    for (int i = 0; i < n; i++)
    {
        cout << tat[i] << " ";
    }
    cout << "\navgtat: " << avgtat / n << endl;

    cout << "PR\tAT\tWT\tCT\tTAT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << pr[i] << "\t" << at[i] << "\t" << wt[i] << "\t" << ct[i + 1] << "\t" << tat[i] << endl;
    }
}