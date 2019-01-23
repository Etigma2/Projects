/*
** EPITECH PROJECT, 2018
** 
** File description:
**
*/

#include <stdio.h>
#include "test.h"
#include <unistd.h>

void *start = NULL;

void *create_block_origin(size_t size)
{
        void *ptr = sbrk(size);
	void *save = ptr;
	
	if (ptr == (void*) -1)
		return (NULL);
	size -= 32;
	*(size_t*) ptr = 0;
	ptr += sizeof(size_t);
	*(size_t*) ptr = size;
	ptr += sizeof(size_t) + size;
	*(size_t*) ptr = 0;
	ptr += sizeof(size_t);
        *(size_t*) ptr = 0;
	return (save + 16);
}

void free(void *ptr)
{
	void *save = ptr;

	if (ptr == NULL)
		return ;
	*(size_t*) (ptr - 16) = 0;
	while (*(size_t*) (ptr - 16) == 0 &&
	       (*(size_t*) (ptr + *(size_t*) (ptr - 8) + 8) != 0))
	{
		ptr += *(size_t*) (ptr - 8) + 16;
	}
	if (*(size_t*) (ptr + *(size_t*) (ptr - 8) + 8) == 0)
	{
		brk((void*) ((size_t) ptr - (size_t) save));
		*(size_t*) (save - 8) = 0;
	}
}

void *realloc(void *ptr, size_t size)
{
	void *save;
	size_t to_cpy;

	save = malloc(size);
        if (ptr == NULL)
                return (save);
	if (size <  *(size_t*) (ptr - 8))
		to_cpy = size;
	else
		to_cpy = *(size_t*) (ptr - 8);
	memcpy(save, ptr, to_cpy);
        free(ptr);
	return (save);
}
