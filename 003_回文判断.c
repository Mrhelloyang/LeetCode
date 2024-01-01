#include<stdbool.h>//bool需要这个头文件；
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

bool isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}
	int tmp = x;
	int xlen = 0;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		xlen++;
	}

	tmp = x;
	int* a = (int*)malloc(sizeof(int) * xlen);
	for (int i = 0; i < xlen; i++)
	{
		a[xlen - 1 - i] = tmp % 10;
		tmp = tmp / 10;
	}
	for (int i = 0; i < (xlen / 2); i++)
	{
		if (a[i] != a[xlen - 1 - i])
		{
			free(a);
			return false;
		}
	}
	free(a);
	return true;

}
int main()
{
	int x = 11;
	bool ret = isPalindrome(x);
	printf("%d\n", ret);

	printf("hellomike\n");
	return 0;
}