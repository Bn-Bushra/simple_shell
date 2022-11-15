#include "shell.h"

/**
  * interactive - returns true if shell is in interactive
  * mode
  * @info: struct address
  *
  * Return: 1 if interactive mode, 0 otherwise
  */
int interactive(info_t *info)
{
	return(isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
  * is_delim - checks for delimiting character.
  * @c: the character to be checked
  * @delim: the delimeter string
  *
  * Return: 1 if true, 0 if false
  */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
  * _isalpha(int c)
  * @c: value to checked
  *
  * Return: 1 if true, otherwise 0.
  */
int _isalpha(int c)
{
	if ((c >= 97) && (c <= 122))
		return (1);
	else if((c >= 65) && (c <= 90))
		return (1);
	else
		return (0);
}

/**
  * _atoi - converts a string to an integer
  * @s: the string to be converted
  *
  * Return: 0 if no numbers in string else return the
  * converted number.
  */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
