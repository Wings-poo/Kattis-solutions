/*
*OpenKattis
*beekeeper
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    vector <string> pair_of_vowels = {"aa", "ee", "ii", "oo", "uu", "yy"};

    int N;

    while (cin >> N) {
        string ans = "ehe~";
        int most_occ = 0;

        for (int n = 0; n < N; n++) {
            string word;
            cin >> word;

            int occ = 0;
            for (int i = 0; i < (int) pair_of_vowels.size(); i++) {
                for (int j = 0; j < (int) word.size() - 1; j++) {
                    string pair_of_letters = "";
                    pair_of_letters.push_back(word[j]);
                    pair_of_letters.push_back(word[j+1]);

                    if (pair_of_letters == pair_of_vowels[i])
                        occ++;
                }
            }

            if (occ >= most_occ) {
                most_occ = occ;
                ans = word;
            }
        }

        if (ans != "ehe~")
            cout << ans << endl;
    }

    return 0;
}