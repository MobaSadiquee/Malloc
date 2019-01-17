/*
** EPITECH PROJECT, 2018
** calloc
** File description:
** Calloc function for malloc
*/

#include "my.h"

void	*calloc(size_t nb, size_t size)
{
	void	*new;
	size_t	calc;

	if ((int)nb < 0 || (int)size < 0)
		return (NULL);
	calc = nb * size;
	new = malloc(calc);
	if (new)
		memset(new, 0, size);
	return (new);
}
