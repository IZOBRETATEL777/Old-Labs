#include <stdio.h>
#include <windows.h>
int main(int argc, char **argv)
{
	int  k;
    scanf("%d", &k);
    k++;
    int **d = new int *[k];
    for (int  i = 1; i < k; i++)
        d[i] = new int[10];
    d[1][0] = 0; d[2][0] = 0;
    for(int  i = 1; i < 10; i++){
        d[1][i] = 1;
    }
    d[2][1] = 2;
    d[2][2] = 2;
    d[2][3] = 2;
    d[2][4] = 3;
    d[2][5] = 0;
    d[2][6] = 3;
    d[2][7] = 2;
    d[2][8] = 2;
    d[2][9] = 2; 
    
    
    
    for (int i = 3; i < k; i++){
    
    d[i][1] = d[i - 1][6] + d[i - 1][8]; 
    d[i][2] = d[i - 1][7] + d[i - 1][9]; 
    d[i][3] = d[i - 1][4] + d[i - 1][8]; 
    d[i][4] = d[i - 1][3] + d[i - 1][9] + d[i - 1][0]; 
    d[i][6] = d[i - 1][1] + d[i - 1][7] + d[i - 1][0]; 
    d[i][7] = d[i - 1][2] + d[i - 1][6]; 
    d[i][8] = d[i - 1][1] + d[i - 1][3]; 
    d[i][9] = d[i - 1][4] + d[i - 1][2]; 
    d[i][0] = d[i - 1][4] + d[i - 1][6];
    d[i][5] = 0;
    }
    
    for (int i = 1; i < 10; i++){
        printf("%d ", d[k - 1][i]);
        if (i % 3 == 0)
            printf("\n");
    }
    printf("\t%d\n", d[k - 1][0]);
    int s = 0;
    for (int i = 0; i < 10; i++)
        s += d[k - 1][i];
    printf("%d\n", s);
    system("pause");
	return 0;
}
