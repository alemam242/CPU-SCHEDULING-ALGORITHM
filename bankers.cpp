#include <bits/stdc++.h>
using namespace std;
int main()
{
    int need[3][4], it = 0, flag = 0, t = 3;
    int finish[3] = {0}, sequence[3] = {-1};
    int maxim[3][4] = {{7, 5, 3, 2}, {3, 2, 2, 9}, {9, 0, 2, 3}};
    int alloc[3][4] = {{0, 1, 0, 2}, {2, 0, 0, 3}, {3, 0, 2, 1}};
    int avail[4] = {1,1,1,1};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            need[i][j] = maxim[i][j] - alloc[i][j]; // calculation of need matrix
        }
    }

    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            if (finish[i] == 0)
            {
                flag = 0;
                for (int j = 0; j < 4; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    //cout << i << endl;
                    sequence[it++] = i;
                }
            }
        }
    }

    if (it == 3)
    {
        cout << "SAFE" << endl;
    }
    else
    {
        cout << "UNSAFE" << endl;
    }
    cout << "Sequence is: ";
    for (int i = 0; i < it; i++)
    {
        if(i==it-1)
        {
            cout << "P" << sequence[i]+1 << endl;
        }
        else
        {
            cout << "P" << sequence[i]+1 << "->";
        }

    }
}
