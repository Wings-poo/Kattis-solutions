/*
*OpenKattis
*skyislands
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000

int main ()
{
    int N, M;
    cin >> N >> M;

    int distance[N][N];
    for (int n = 0; n < N; n++)
        for (int m = 0; m < N; m++) { 
            if (n == m)
                distance[n][m] = 0;
            else
                distance[n][m] = INF;
        }

    for (int m = 0; m < M; m++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        distance[A][B] = 1;
        distance[B][A] = 1;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) {
                if (distance[i][j] > (distance[i][k] + distance[k][j]))
                    distance[i][j] = (distance[i][k] + distance[k][j]);
            }

    bool yes = true;
    for (int n = 0; (n < N) && yes; n++)
        for (int m = 0; (m < N) && yes; m++) { 
            if (distance[n][m] == INF)
                yes = false;
        }

    if (yes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}