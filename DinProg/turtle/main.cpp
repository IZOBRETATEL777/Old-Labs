#include <cstdio>
#include <algorithm>
 
int main()
{
    long long int n, i, j;
    scanf("%lld", &n);
    long long int **a = new long long int *[n];
    for (i = 0; i < n; i++)
    {
        a[i] = new long long int [n];
        for (j = 0; j < n; j++)
            scanf("%lld",&a[i][j]);
    }
    for (i = 1; i < n; i++)
        a[i][n - 1] += + a[i - 1][n - 1];
    for (j = n - 2; j >= 0; j--)
        a[0][j] += a[0][j + 1];
    for (i = 1; i < n; i++)
        for (j = n - 2; j >= 0; j--)
            a[i][j] += std::max(a[i - 1][j], a[i][j + 1]);
    printf("%lld\n", a[n - 1][0]);
    system("pause");
    return 0;
}