/*

SDL2W - CMake wrapper for SDL2 module.
Test program.

Copyright (c) 2018-2021 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
OR OTHER DEALINGS IN THE SOFTWARE.

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
