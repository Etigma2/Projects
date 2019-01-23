/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "test.h"

void *create_block(size_t size, void *ptr)
{
        void *save = ptr;
        size_t old_size;

        *(size_t*) ptr = 1;
        ptr += sizeof(size_t);
        old_size = *(size_t*) ptr - size - 24;
        *(size_t*) ptr = size;
        ptr += 1 * sizeof(size_t) + size;
        if (*(size_t*) ptr != 1)
                *(size_t*) ptr = 0;
        ptr += sizeof(size_t);
        *(size_t*) ptr = old_size;
        return (save);
}

void *malloc(size_t size)
{
        size_t size_map = size + 32;
        void *find;

        if (size == 0)
                return (NULL);
        if (size_map % getpagesize() != 0)
                size_map = (size_map + (getpagesize()
                                        - size_map % getpagesize()));
        if (start == NULL) {
                start = sbrk(0);
                if (create_block_origin(size_map) == NULL)
                        return (NULL);
        }
        if (size% 16 != 0)
                size = (size+ (16 - size % 16));
        find = start;
        return (find_the_way(size, size_map, find) + 16);
}

void *find_the_way(size_t size, size_t size_map, void *find)
{
	size_t finish = 0;
	
	while (*(size_t*) (find + 8) != 0 && finish == 0) {
		if (*(size_t*) (find + 8) >= size && *(size_t*) find == 0) {
			find = create_block(size, find);
			finish = 1;
		}
                if (finish == 0)
			find += 16 + *(size_t*) (find + 8);
	}
        if (finish == 0 && find != NULL) {
		find = create_block_origin(size_map) - 16;
		if (find == NULL)
			return (NULL);
		find = create_block(size, find);
	}
	return (find);
}
