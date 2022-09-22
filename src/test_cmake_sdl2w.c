/*
SDL2W - CMake wrapper for SDL2 module.
Test program.

Copyright (c) 2018-2021 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors.
SPDX-License-Identifier: MIT
*/


#include <stdio.h>

#include "SDL.h"

#if TEST_CMAKE_SDL2W_NET
#include "SDL_net.h"
#endif // TEST_CMAKE_SDL2W_NET


int main(
	int argc,
	char** argv)
{
	int sdl_result = SDL_Init(0);

	if (sdl_result)
	{
		printf("%s. %s\n", "Failed to initialize SDL.", SDL_GetError());
		return 1;
	}
	else
	{
#if TEST_CMAKE_SDL2W_NET
		int sdl_net_result = SDLNet_Init();

		if (sdl_net_result)
		{
			printf("%s. %s\n", "Failed to initialize SDL_net.", SDLNet_GetError());
			return 1;
		}
		else
#endif // TEST_CMAKE_SDL2W_NET
		{
			printf("%s\n", "Succeed.");
			return 0;
		}
	}
}
