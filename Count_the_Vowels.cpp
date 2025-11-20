/*
*OpenKattis
*Count the Vowels
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int vowel = 0;
    char c;

    c = getchar();
    while (c != EOF) {
        if ((c == 'a') || (c == 'A')
            || (c == 'e') || (c == 'E')
            || (c == 'i') || (c == 'I')
            || (c == 'o') || (c == 'O')
            || (c == 'u') || (c == 'U'))
            vowel++;
        
        c = getchar();
    }

    cout << vowel << endl;
    return 0;
}