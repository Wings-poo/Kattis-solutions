/*
*OpenKattis
*sevenwonders
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{ 
    string TCG;
    cin >> TCG;

    int T = 0, C = 0, G = 0;
    for (int i = 0; i < (int) TCG.size(); i++) {
        if (TCG[i] == 'T')
            T++;
        if (TCG[i] == 'C')
            C++;
        if (TCG[i] == 'G')
            G++;
    }

    int TCG_cnt = min(T, min(C, G));

    cout << T*T + C*C + G*G + TCG_cnt*7 << endl;
    
    return 0;
}