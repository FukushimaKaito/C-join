#include <stdio.h>
#include <stdlib.h>

int join(int len, char *dst, int n, char **sar)
{
    int k = 0;
    char *p = dst;
    for (int i = 0; k < n - 1 && k <= len; i++)
    {
        for (int j = 0; sar[i][j]; j++)
        {
            *p++ = sar[i][j];
            k++;
        }
        *p++ = '-';
    }
    *--p = '\0';
    return k;
}

int main(void)
{
    char *sar[] = {"AB", " D", "\t", "E"}, *dst;
    int i, n, len;

    n = 0;
    for (i = 0; i < sizeof(sar) / sizeof(*sar); i++) //文字列の個数
    {
        for (int j = 0; sar[i][j] != '\0'; j++) //文字列の長さ
        {
            n++;
        }
    }
    len = n + i;

    //動的確保
    dst = (char *)malloc(sizeof(char) * len);
    if (!dst)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    join(BUFSIZ, dst, n, sar);
    printf("%s\n", dst);

    free(dst);
    return 0;
}