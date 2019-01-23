/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Enums
*/

#ifndef ENUMS_HPP_
#define ENUMS_HPP_

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <thread>
#include <vector>

const size_t FILL_PERCENTAGE = 75;
const size_t BONUS_DROP_PERCENTAGE = 25;
const size_t MAP_SIZE = 11;
const size_t NB_PLAYERS = 4;
const size_t BOMB_TIMER_MS = 3000;

enum Element
{
	WALL,
	PATH,
	CRATE,
	BOMB,
	BONUS,
	P1,
	P2,
	P3,
	P4,
	BLAST,
	NONE,
};

enum Directions
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	DROP,
	SPEC,
	STOP
};

#endif /* !ENUMS_HPP_ */
