#include "main.h"

/**
 *_strlen - calculates the len of a string
 *@s: formal parameter
 *Return: string length
 */

int _strlen(char *s)
{
	int str_len = 0;

	while (s[str_len] != '\0')
		str_len++;
	return (str_len);
}


/**
 *_strcpy - Copies string source to destination
 *@src: this is the source string
 *@dest: the destination of the source string
 *Return: string copied to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 *_strcat - joins two strings
 *@dest: formal parameter
 *@src: the formal parameter of the source string
 *Return: string dest
 */

char *_strcat(char *dest, char *src)
{
	int length, index;

	for (length = 0; dest[length]; length++)
		;
	index = 0;
	while (src[index])
	{
		dest[length] = src[index];
		length++;
		index++;
	}
	dest[length] = '\0';
	return (dest);
}

/**
 *_strcmp -  comapares two strings
 *@s1: first str
 *@s2: second sttring
 *Return: changes after comparism
 */

int _strcmp(char *s1, char *s2)
{
	int index = 0, d;

	while (s1[index] || s2[index])
	{
		d = s1[index] - s2[index];
		if ((s1[index] > s2[index]) || (s1[index] < s2[index]))
			break;
		index++;
	}
	return (d);
}


/**
 *_strncmp - this comapares two strings
 *@s1: first one as formal parameter
 *@s2: second one as formal parameter
 *@n: characters comp
 *Return: difference or changes
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i = 0, changes;

	while ((s1[i] || s2[i]) && (i < n))
	{
		changes = s1[i] - s2[i];
		if ((s1[i] > s2[i]) || (s1[i] < s2[i]))
			break;
		i++;
	}
	return (changes);
}
