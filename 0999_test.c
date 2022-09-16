#include <stdio.h>

char *funcReverse(char input[])
{
    int size = (int)strlen(input);
    cout << size << endl;
    char *res = (char *)malloc(size);
    for (int i = size - 1; i >= 0; i--)
    {
        unsigned char temp = static_cast<unsigned char>(input[i]);
        res[size - 1 - i] = static_cast<char>(temp);
        // some operation ?
    }
    return res;
}

int main(void)
{
    // your code goes here
    char input[6] = {0xAB, 0x78, 0x61, 0xB3, 0x30, NULL};
    char *P;
    P = funcReverse(input);
    free(P);
    return 0;
}
