#include<bits/stdc++.h>
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int n=A.size();
    int counter[100000];
    int max=0;
    if (n==1)
        if(A[0]!=1)
            return 0;
    for(long long i=0;i<100000;i++)
    {
        counter[i]=0;
    }
    for (int i=0;i<n;i++)
    {
        counter[A[i]-1]++;
        if (A[i]>max)
            max=A[i];
    }
    for(long long i=0;i<max;i++)
    {
        if(counter[i]!=1)
            return 0;
    }
    return 1;
}
