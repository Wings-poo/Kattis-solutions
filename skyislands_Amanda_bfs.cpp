/*
*OpenKattis
*skyislands
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N, M;
    cin >> N >> M;

    vector <vector <int>> neighbors (N);

    for (int m = 0; m < M; m++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        neighbors[A].push_back(B);
        neighbors[B].push_back(A);
    }

    queue <int> q;
    bool isvisited[N] = {false};

    q.push(0);

    while (q.size()) {
        auto v = q.front();
        q.pop();

        if (isvisited[v])
            continue;

        isvisited[v] = true;

        for (auto island : neighbors[v])
            q.push(island);
    }
    
    bool yes = true;
    for (int n = 0; (n < N) && yes; n++) {
        if (isvisited[n] == false)
            yes = false;
    }

    if (yes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}