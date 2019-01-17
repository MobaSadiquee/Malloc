/*
** EPITECH PROJECT, 2018
** show_alloc_mem
** File description:
** func for showing the memory
*/

#include "my.h"
#include <stdio.h>

extern void *base;

void	show_alloc_mem(void)
{
	t_block	*nb;

	nb = base;
	printf("break: %p\n", sbrk(0));
	while (nb)
	{
		if (nb->free == 0)
			printf("%p - %p : %lu nbytes\n",
				nb, nb + nb->size, nb->size);
		nb = nb->next;
	}
}
