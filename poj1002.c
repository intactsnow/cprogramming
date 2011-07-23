#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STD_LEN 50

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int mapNum(char c)
{
	if ( c == 'A' || c == 'B' || c == 'C' )
		return 2;
	if ( c == 'D' || c == 'E' || c == 'F' )
		return 3;
	if ( c == 'G' || c == 'H' || c == 'I' )
		return 4;
	if ( c == 'J' || c == 'K' || c == 'L' )
		return 5;
	if ( c == 'M' || c == 'N' || c == 'O' )
		return 6;
	if ( c == 'P' || c == 'R' || c == 'S' )
		return 7;
	if ( c == 'T' || c == 'U' || c == 'V' )
		return 8;
	if ( c == 'W' || c == 'X' || c == 'Y' )
		return 9;
	return (c-'0');
}

void getStdForm(char *src, int *dst)
{
	int times = 1000000;
	*dst = 0;
	int i = 0;
	for ( ; i < STD_LEN; i++ )
	{
		if ( src[i] == 0 )
			return;
		if ( src[i] == '-' )
			continue;
		*dst += mapNum(src[i]) * times;
		times /= 10;
	}
	return;
}

int main()
{
	char str[STD_LEN];
	int *phone;
	int n = 0;
	int i = 0;

	scanf("%d", &n);
    phone = malloc(sizeof(int)*n);
    for ( i = 0; i < n; i++ )
    {
        memset(str, 0, STD_LEN);
        scanf("%s", str);
        getStdForm(str, &phone[i]);
    }

    qsort(phone, n, sizeof(int), cmp);

    int duplicates = 0;
    int m = 1;
    for ( i = 1; i < n; i++ )
    {
        if ( phone[i] == phone[i-1] )
            m++;
        else if ( m > 1 )
        {
            duplicates = 1;
            int former = phone[i-1] / 10000;
            int latter = phone[i-1] % 10000;
            printf("%03d-%04d %d\n", former, latter, m);
            m = 1;
        }
        else
            m = 1;
    }
    if ( m > 1 )
    {
        duplicates = 1;
        int former = phone[i-1] / 10000;
        int latter = phone[i-1] % 10000;
        printf("%03d-%04d %d\n", former, latter, m);
    }

    if ( !duplicates )
        printf("No duplicates.\n");

    free(phone);

	exit(0);
}
