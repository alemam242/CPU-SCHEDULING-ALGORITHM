#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, tq;
    cout << "Number of process: ";
    cin >> n;
    int p[n], tat[n], wt[n], cpu[n], rem_cpu[n], timer = 0, counter = 0, i = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        cout << "CPU time of P" << p[i] << ": ";
        cin >> cpu[i];
        rem_cpu[i] = cpu[i];
    }
    cout << "Time Quantam: ";
    cin >> tq;
    for (timer = 0, i = 0; counter != n;)
    {
        flag = 0;
        if (rem_cpu[i] <= tq && rem_cpu[i] > 0)
        {
            timer += rem_cpu[i];
            rem_cpu[i] = 0;
            flag = 1;
        }
        else if (rem_cpu[i] > 0)
        {
            timer += tq;
            rem_cpu[i] -= tq;
        }

        if (rem_cpu[i] == 0 && flag == 1)
        {
            counter++;
            tat[i] = timer;
        }
        i++;
        i = i % n;
    }

    for (int j = 0; j < n; j++)
    {
        wt[j] = tat[j] - cpu[j];
    }

    cout << "PRO\tCPU\tTAT\tWT\n";
    for (int j = 0; j < n; j++)
    {
        cout << p[j] << "\t" << cpu[j] << "\t" << tat[j] << "\t" << wt[j] << endl;
    }
}