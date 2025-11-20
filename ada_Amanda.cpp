/*
*OpenKattis
*ada
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;

    vector <int> V(N);
    for (int n = 0; n < N; n++)
        cin >> V[n];

    vector <int> lastdiff;
    int diff = INT_MAX;

    int M = N;
    int d = 1;
    while (true) {        
        for (int n = 1; n < M; n++)
            V[n - 1] = V[n] - V[n - 1];

        lastdiff.push_back(V[M - 2]);
        
        int m = 1;
        for (int n = 1; n < M - 1; n++) {
            if (V[n] != V[n - 1])
                break;
            m++;
        }

        if (m == M - 1)
            break;
        else {
            d++;
            M--;
            diff = INT_MAX;
        }
    }
    
    int lastV = V[N - 1];
    for (int n = 0; n < (int) lastdiff.size(); n++)
        lastV += lastdiff[n];

    cout << d << " " << lastV << endl;
    
    return 0;
}