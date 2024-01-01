#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
char* longestCommonPrefix(char** strs, int strsSize)
{
	int j = 1, i = 1;
	int s = 1000;
	int len = 0;
	for (int i = 0; i <= 20; i++)//i是字符有多少位；
	{
		j = 1;
		while (1)
		{
			if (strs[0][i] != strs[j][i])//j是第几个字符；
			{
				goto END;
			}
			if (j == strsSize - 1)
			{
				len++;
				break;
			}
			j++;
		}

	}
END:
	{
		char* p = (char*)malloc(sizeof(char) * (len + 1));
		strncpy(p, strs[0], len);//要看拷贝多少；
		p[len] = '\0';
		printf("%s\n", p);
		return p;
	}
}
int main()
{
	char* strs[] = { "flpower","flpow","flpight" };
	char* ret = longestCommonPrefix(strs, 3);
	printf("%s\n", ret);
	return 0;
}
