/*
*OpenKattis
*palindromesubstring
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string S;
    while (cin >> S) {

        set <string> all_pal_t;
        for (int i = 2; i < (int) S.size(); i++) {
            for (int j = 0; j < (int) S.size() - i + 1; j++) {
                string t = S.substr(j, i);
                string new_t = t;
                reverse(t.begin(), t.end());
                if (new_t == t)
                    all_pal_t.insert(t);
            }
        }

        for (auto t : all_pal_t)
            cout << t << endl;
        
        cout << endl;
    }

    return 0;
}