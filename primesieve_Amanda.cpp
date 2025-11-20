/*
*OpenKattis
*primesieve
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    long long N, Q;
    cin >> N >> Q;

    vector <long long> primes_under_N;
    if (N >= 2)
        primes_under_N.push_back(2);
    for (long long n = 3; n <= 100000000; n += 2) {
        bool isprime = true;
        for (auto i : primes_under_N) {
            if (n%i == 0) {
                isprime = false;
                break;
            }
            if (i > sqrt(n))
                break;
        }

        if (isprime)
            primes_under_N.push_back(n);
    }

    cout << primes_under_N.size() << endl;

    for (int q = 0; q < Q; q++) {
        long long x;
        cin >> x;

        cout << binary_search(primes_under_N.begin(), primes_under_N.end(), x) << endl;
    }
    
    return 0;
}