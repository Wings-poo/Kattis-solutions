/*
*OpenKattis
*greedilyincreasing
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int L;

    cin >> L;
    int GIS[L];
    int idx = 0;
    for (int l = 0; l < L; l++) {
        int temp;
        cin >> temp;
        if (!idx) {
            GIS[idx] = temp;
            idx++;
        } else if (temp > GIS[idx-1]) {
            GIS[idx] = temp;
            idx++;
        }   
    }

    cout << idx << endl;
    for (int l = 0; l < idx; l++) {
        cout << GIS[l] << " ";
    }

    return 0;
}