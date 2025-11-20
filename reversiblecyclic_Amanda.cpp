/*
*OpenKattis
*reversiblecyclic
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string rev_S;
    cin >> rev_S;

    string orig_S = rev_S;
    reverse(rev_S.begin(), rev_S.end());

    string S = orig_S + orig_S;

    bool int_rev_cyc = true;
    auto pos = S.find(rev_S);
    if (pos == string::npos)
        int_rev_cyc = false;

    cout << int_rev_cyc << endl;

    return 0;
}