/*
*OpenKattis
*skyislands
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int find (int parents[], int A)
{
    if (parents[A] == A)
        return A;
    return parents[A] = find(parents, parents[parents[A]]);
}

void connect (int parents[], int saizu[], int A, int B)
{
    int parentA = find(parents, A), parentB = find(parents, B);
    if (parentA == parentB)
        return;

    if (saizu[parentA] > saizu[parentB])
        swap(parentA, parentB);

    parents[parentA] = parentB;
    saizu[parentB] += saizu[parentA];
    saizu[parentA] = 0;
}

int main ()
{
    int N, M;
    cin >> N >> M;

    int islands[N], saizu[N];
    for (int n = 0; n < N; n++) {
        islands[n] = n;
        saizu[n] = 1;
    }

    for (int m = 0; m < M; m++) {
        int A, B;
        cin >> A >> B;
        connect(islands, saizu, A - 1, B - 1);
    }

    bool yes = true;
    int prevparent = find(islands, 0);
    for (int n = 1; (n < N) && yes; n++) {
        if (prevparent != find(islands, n))
            yes = false;
    }

    if (yes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}