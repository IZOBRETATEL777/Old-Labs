#include <cstdio>
#include <windows.h>
unsigned long long int  fib (unsigned long long int n){
    if (n == 1 || n == 2)
        return n;
    if (n == 3)
        return 4;
    return (fib(n - 1) + fib (n - 2) + fib(n - 3));
}


int main(int argc, char **argv)
{
	short int n;
    scanf("%hu", &n);
    printf("%lld\n", fib(n));
    system("pause");
	return 0;
}
