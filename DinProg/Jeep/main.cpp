#include <windows.h>
#include <cmath>
#include <cstdio>


float foo (float distance, float fuel, float m, int k)
{
    if ((distance - (float) (fuel / (2 * k - 1)) < 0))
    {
        m += distance *(2 * k - 1);
        return ceil(m);

    }
    m += fuel;
    distance -= (float) (fuel / (2 * k - 1));
    k++;
    return foo(distance, fuel, m, k);

}

int main()
{

    float distance, fuel;
    scanf("%f%f", &distance, &fuel);
    printf("%.0f\n", foo (distance, fuel, 0, 1));
    system("pause");
    return 0;
}
