/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef TEST_H_
# define TEST_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define ACCESS (1UL << 63)

extern void *start;

void *create_block(size_t, void*);
void *create_block_origin(size_t);
void *my_malloc(size_t);
void *find_the_way(size_t, size_t, void*);

#endif
