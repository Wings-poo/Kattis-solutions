/*
*OpenKattis
*fibonacci
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int case_num = 1;

    map <int, string> fib_str;
    fib_str[0] = "0";
    fib_str[1] = "1";

    for (int i = 2; i <= 10; i++) {
        string fib_next = fib_str[i - 1] + fib_str[i - 2];
        fib_str[i] = fib_next;
    }

    map <string, int> fib_num;
    for (int i = 0; i <= 10; i++)
        fib_num[fib_str[i]] = i;

    int n;
    string p;
    while (cin >> n >> p) {
        int gap = n - fib_num[p];
        long long ans = 1, ans_prev = 0;

        cout << fib_num[p] << " " << gap << endl;
        for (int i = 0; i < gap; i++) {
            long long new_ans = ans + ans_prev;
            ans_prev = ans;
            ans = new_ans;
        }

        cout << "Case " << case_num << ": " << ans << endl;
        case_num++;
    }

    return 0;
}