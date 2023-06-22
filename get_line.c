#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * custom_getline: Function that reads data from standard input
 * @lineptr: Pointer to line to be read`
 * @n: NUmber of bytes
 * @stream: Stream to be read from
 *
 * Return; An integer
 */

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int ch;
	char * new_lineptr;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);

		if (*lineptr == NULL)
		{
			return -1;
		}
	}

	while ((ch = fgetc(stream)) != EOF)
	{
		if (pos + 1 >= *n)
		{
			*n *= 2;
			new_lineptr = realloc(*lineptr, *n);

			if (new_lineptr == NULL)
			{
				return -1;
			}
			*lineptr = new_lineptr;
		}
		(*lineptr)[pos++] = ch;
		if (ch == '\n')
		{
			break;
        	}
	}

	if (pos == 0)
	{
		return -1;
	}

	(*lineptr)[pos] = '\0';
	return pos;
}
