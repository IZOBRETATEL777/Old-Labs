/*
Find max number via BiteRotate
by IZOBRETATEL777
*/

#include <iostream>
#include <bitset>
const short MAXBITESIZE = 4;
using namespace std;
void bitRoatate (int &arg)
{
    bitset <MAXBITESIZE> biteMask;
    biteMask = arg;
    short temp;
    temp = biteMask[0];
    for (short i = 0; i < MAXBITESIZE - 1; i++)
        biteMask[i] = biteMask[i+1];
    biteMask[MAXBITESIZE - 1] = temp;
    arg = (int)biteMask.to_ulong();
}


int main()
{
    int n;
    cin >> n;
    int n1 = n, maxN = n;
    bitRoatate(n);
    while (n1 != n)
    {
        maxN = max(maxN, n);
        bitRoatate(n);
    }
    cout << maxN <<endl;
    return 0;
}
