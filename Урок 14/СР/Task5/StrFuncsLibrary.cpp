#include <iostream>

int mystrlen(const char* str)
{
	int len = 0;
	for (; str[len] != '\0'; len++);
	return len;
}

char* mystrcpy(char* str1, const char* str2)
{
	while (*str2 != '\0')
	{
		*str1++ = *str2++;
	}
	*str1 = '\0';

	return str1;
}

char* mystrcat(char* str1, const char* str2)
{
	while (*str1 != '\0') 
	{
		str1++;
	}
	mystrcpy(str1, str2);

	return str1;
}

char* mystrchr(char* str, char s)
{
	while (*str != '\0')
	{
		if (*str == s)
		{
			return str;
		}
		str++;
	}
	return nullptr;
}

char* mystrstr(char* str1, char* str2)
{
	if (*str2 == '\0') return str1;

	char* p1 = str1;
	while (*p1 != '\0')
	{
		char* p1Begin = p1, * p2 = str2;

		while (*p1 && *p2 && *p1 == *p2)
		{
			p1++;
			p2++;
		}

		if (*p2 == '\0') return p1Begin;

		p1 = p1Begin + 1;
	}
	return nullptr;
}