#include <bits/stdc++.h>
 
using namespace std;
 
void Init ()
{
    const string FileINP = "A" + (string)".INP";
    const string FileOUT = "A. Donut Shops" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}
 
long long t, a, b, c;
 
void Solve (long long &a, long long &b, long long &c)
{
    if (a*b == c) printf ("%lld", b + 1);
    else if (a < c)
    {
        printf ("1");
    }
    else printf ("-1");
    printf (" ");
    if (a * b > c)
    {
        printf ("%lld", b);
    }
    else printf ("-1");
    printf ("\n");
}
 
int main ()
{
    //Init();
    scanf ("%lld", &t);
    for (long long i = 0; i < t; ++i)
    {
        scanf ("%lld %lld %lld", &a, &b, &c);
        Solve (a, b, c);
    }
    return 0;
}