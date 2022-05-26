#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "\nHow many process: ";
    cin >> n;
    int at[n], cput[n], ct[n + 1], tat[n], wt[n], time = 0;
    double ctavg = 0, tatavg = 0, wtavg = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Arrival time for P" << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter cpu time for P" << i + 1 << ": ";
        cin >> cput[i];
    }
    int gc[n + n], j = 1, x = 1;
    gc[0] = ct[0] = 0;
    int tt = 0;
    for (int i = 0; i < n;)
    {
        int t = 0;
        for (int k = i; k < n; k++)
        {
            if (at[k] <= time)
            {
                t += cput[k];
                tt += cput[k];
                ct[x++] = tt;
                i++;
            }
            else
            {
                t++;
                tt++;
            }
            break;
        }
        time += t;
        gc[j++] = time;
    }
    cout << "\nValue of gantt chart: ";
    for (int i = 0; i < j; i++)
    {
        cout << gc[i] << " ";
    }
    cout << "\n\nCompletion time: ";
    for (int i = 1; i < x; i++)
    {
        ctavg += ct[i];
        cout << ct[i] << " ";
    }
    cout << "\n\nTurn around time: ";
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i + 1] - at[i];
        tatavg += tat[i];
        cout << tat[i] << " ";
    }
    cout << "\n\nWaiting time: ";
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - cput[i];
        wtavg += wt[i];
        cout << wt[i] << " ";
    }
    cout << "\n\n\nAverage Complition time: " << ctavg / n << endl;
    cout << "\nAverage turn around time: " << tatavg / n << endl;
    cout << "\nAverage waiting time: " << wtavg / n << endl;
    // cout << "\n\nResponse time is same as waiting time for non premptive FCFS" << endl;
}