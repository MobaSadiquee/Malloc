/*
** EPITECH PROJECT, 2018
** free.c
** File description:
** free for the malloc
*/

#include "my.h"

extern void		*base;
extern pthread_mutex_t	mutex;

t_block	*get_block_ptr(void *ptr)
{
	char *tmp;

	tmp = ptr;
	tmp -= STRUCT_SIZE;
	return (ptr = tmp);
}

int	valid_addr(void *ptr)
{
	if (base)
	{
		if (ptr > base && ptr < sbrk(0))
			return (ptr == (get_block_ptr(ptr))->ptr);
	}
	return (0);
}

t_block	*fusion(t_block *block)
{
	if (block->next && block->next->free)
	{
		block->size += STRUCT_SIZE + block->next->size;
		block->next = block->next->next;
	}
	return (block);
}

void	free(void *ptr)
{
	t_block	*block;

	block = NULL;
	if (valid_addr(ptr))
	{
		block = get_block_ptr(ptr);
		pthread_mutex_lock(&mutex);
		block->free = 1;
		if (block->next)
			fusion(block);
		pthread_mutex_unlock(&mutex);
	}
}
