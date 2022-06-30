#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int>prev(n,0);

    for (int i = 0; i < n; i++)
    {
        vector<int>cur(n,0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                cur[j] = 1;
                continue;
            }

            int up=0,left=0;
            if (i>0){
                up = prev[j];
            }
            if(j>0){
                left = cur[j-1];
            }

            cur[j] = up+left;

        }
         prev = cur;
    }

    cout << prev[m - 1] << endl;
    return 0;
}

/*
Time Complexity: O(M*N)

Reason: There are two nested loops

Space Complexity: O(N)

Reason: We are using an external array of size ‘N’ to store only one row.

*/