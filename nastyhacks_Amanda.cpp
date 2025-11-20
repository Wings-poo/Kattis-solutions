/*
*OpenKattis
*nastyhacks
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int R, E, C;
        cin >> R >> E >> C;

        if (R < (E - C))
            cout << "advertise" << endl;
        else if (R == (E - C))
            cout << "does not matter" << endl;
        else
            cout << "do not advertise" << endl;
    }
    return 0;
}