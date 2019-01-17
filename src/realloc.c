/*
** EPITECH PROJECT, 2018
** realloc
** File description:
** func for the realloc
*/

#include "my.h"

t_block	*do_realloc(void *ptr, size_t size)
{
	t_block *block_ptr = NULL;
	void	*block = NULL;

	block_ptr = get_block_ptr(ptr);
	if (block_ptr->size >= size)
		return (ptr);
	block = malloc(size);
	if (!block)
		return (NULL);
	memcpy(block, ptr, block_ptr->size);
	return (block);
}

void	*realloc(void *ptr, size_t size)
{
	void	*block = NULL;

	if ((int)size <= 0)
		return (NULL);
	size = align(size);
	if (!ptr)
		return (malloc(size));
	else
	{
		if ((block = do_realloc(ptr, size)) == NULL)
			return (NULL);
		free(ptr);
		return (block);
	}
	return (NULL);
}
