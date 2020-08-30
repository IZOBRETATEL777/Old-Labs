#include <stdio.h>
#include <windows.h>
int main()
{
    int a[50], p[50], sizeOfSub;
    scanf("%d", &sizeOfSub);
    for (int i = 0; i < sizeOfSub; i++)
        scanf("%d", &a[i]);

    p[sizeOfSub - 1] = 1;
    for (int  i = sizeOfSub - 2; i >= 0; i--){
        int maxCount = 0;
        for (int  j = i + 1; j < sizeOfSub; j++)
            if (a[i] < a[j])
                if (p[j] > maxCount)
                    maxCount = p[j];
        p[i] = maxCount + 1;
    }
    printf("%d\n", p[0]);
    system("pause");
	return 0;
}
