/*
** EPITECH PROJECT, 2018
** malloc.c
** File description:
** function for the malloc
*/

#include "my.h"

size_t		current = 0;
void		*base = NULL;
pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

t_block	*find_next(t_block **last, size_t size)
{
	t_block	*block = base;

	while (block && !(block->free && block->size >= size))
	{
		*last = block;
		block = block->next;
	}
	return (block);
}

bool	split_memory(size_t size)
{
	void	*request;

	if (current < size + STRUCT_SIZE)
	{
		while (current < size + STRUCT_SIZE)
		{
			request = sbrk(getpagesize());
			if (request == (void*) -1)
				return (false);
			current = current + getpagesize();
		}
	}
	return (true);
}

t_block	*space(t_block* last, size_t size)
{
	t_block	*block;

	if (!last)
		block = sbrk(0);
	else
		block = (void*)(last + 1) + last->size;
	if ((split_memory(size)) == false)
		return (NULL);
	current = current - (size + STRUCT_SIZE);
	if (last)
		last->next = block;
	block->size = size;
	block->next = NULL;
	block->free = 0;
	return (block);
}

bool	lunch_malloc(t_block **last, t_block **block, size_t size)
{
	pthread_mutex_lock(&mutex);
	*block = find_next(last, size);
	if (*block)
		(*block)->free = 0;
	else
	{
		*block = space(*last, size);
		if (!*block)
			return (true);
	}
	pthread_mutex_unlock(&mutex);
	return (false);
}

void	*malloc(size_t size)
{
	t_block	*block;
	t_block	*last;

	if (size <= 0)
		return (NULL);
	size = align(size);
	if (base) {
		last = base;
		if (lunch_malloc(&last, &block, size) == true)
			return (NULL);
	}
	else {
		pthread_mutex_lock(&mutex);
		if ((block = space(NULL, size)) == NULL)
			return (NULL);
		base = block;
		pthread_mutex_unlock(&mutex);
	}
	return (block + 1);
}
