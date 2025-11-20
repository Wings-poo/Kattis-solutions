/*
*OpenKattis
*costumecontest
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;

    string costume;
    map <string, int> costume_count;
    
    for (int n = 0; n < N; n++) {
        cin >> costume;

        if (costume_count.find(costume) == costume_count.end())
            costume_count[costume] = 1;
        else
            costume_count[costume]++;
    }

    int min = 10000;
    for (auto i : costume_count)
        if (i.second < min)
            min = i.second;
    
    for (auto i : costume_count)
        if (i.second == min)
            cout << i.first << endl;

    return 0;
}