#include<stdio.h>
void fn (int a, int b, int c) {
    printf("%d %d %d\n", a, ++b, c++);
}
int main() {
    long long n = 0;
    for (int a = 1; a < 10001; a++) 
        for (int b = 1; b < 10001; b++) 
            for (int c = 1; c < 10001; c++) 
                if ((a + b + c) % 5 == 0) 
                    n++;

    printf("%lld\n", n);

}