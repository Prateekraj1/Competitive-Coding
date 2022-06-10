#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cas;
    cin >> cas;

    while (cas--)
    {
        int itera;
        cin >> itera;

        vector<int> lst(itera);
        for (int i = 0; i < itera; i++)
            cin >> lst[i];

        int flag = 1;

        int mini = lst[0], maxi = lst[0];

        for (int i = 1; i < itera; i++)
        {
            if (lst[i] < mini)
                mini = lst[i];
            else if (lst[i] > maxi)
                maxi = lst[i];

            if (lst[i] == mini or lst[i] == maxi)
            {
                continue;
            }
            else{
                flag = 0;
                break;
            }
        }

        if (flag)
            cout << "Yes";
        else
            cout << "No";

        cout << endl;
    }

    return 0;
}