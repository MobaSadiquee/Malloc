/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header for the func
*/

#ifndef	MY_H_
# define MY_H_

#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct s_block
{
	size_t	size;
	struct s_block  *next;
	int	free;
	void	*ptr;
}	t_block;

#define align(x) (((((x) -1) >>2) <<2) + 4)
#define STRUCT_SIZE (sizeof(struct s_block))

/* malloc.c */
t_block	*find_next(t_block **last, size_t size);
t_block *space(t_block* last, size_t size);
bool	split_memory(size_t size);	
bool	lunch_malloc(t_block **last, t_block **block, size_t size);
void	*malloc(size_t size);

/* free.c */
t_block	*get_block_ptr(void *ptr);
int	valid_addr(void *ptr);
t_block	*fusion(t_block *block);
void	free(void *ptr);

/* realloc.c */
t_block *do_realloc(void *ptr, size_t size);
void	*realloc(void *ptr, size_t size);

/* calloc.c */
void	*calloc(size_t nb, size_t size);

/* show_alloc_mem.c */
void	show_alloc_mem(void);

#endif	/* MY_H_ */
