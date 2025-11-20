/*
Union-Find
unionfind
*/
#include <bits/stdc++.h>
using namespace std;

int *saizu, *head;

int find (int A)
{
    if (head[A] == A)
        return A;
    return head[A] = find(head[A]);
}

void connect (int A, int B)
{
    if (A == B)
        return;
    
    int a = find(A), b = find(B);
    
    if (a == b)
        return;
    
    if (saizu[b] > saizu[a])
        swap(a,b);
    
    saizu[a] += saizu[b] + 1;
    head[b] = head[a];
    
    return;
}

int main ()
{
    int N, Q;
    scanf(" %d %d ", &N, &Q);

    head = (int*) malloc(N*sizeof(int));    //vector is slower than calloc (not so sure with malloc, not much diff eh)
    saizu = (int*) calloc(N, sizeof(int)); //malloc with one by one alloc is actually slower!
    for (int n = 0; n < N; n++) {
        head[n] = n;
    }
    
    vector < pair <int, int> > to_merge;
    for (int q = 0; q < Q; q++) {
        char c;
        int a, b;
        //cin >> c >> a >> b;
        scanf(" %c %d %d ", &c, &a, &b);
        
        if (c == '=') { //connecting here is slower for test case #5
            to_merge.push_back({{a}, {b}});
        }
        
        else if (find(a) == find(b))
            printf("yes\n");
        
        else {
            while (!to_merge.empty()) {
                connect(to_merge.back().first, to_merge.back().second);
                to_merge.pop_back();
            }
            
            if (find(a) == find(b))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    
    free(head);
    free(saizu);
    return 0;
}