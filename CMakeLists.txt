#[[

CMake find module wrapper for SDL2.
Test program.


Copyright (c) 2018 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors.

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

]]


cmake_minimum_required(VERSION 3.1.3 FATAL_ERROR)
project(test_cmake_sdl2w VERSION 1.0.0 LANGUAGES C)

# Options.
#
option(TEST_CMAKE_SDL2W_USE_STATIC_LINKING "Use static linking." OFF)


# Setup components.
#
set(TEST_CMAKE_SDL2W_COMPONENTS "")

if (TEST_CMAKE_SDL2W_USE_STATIC_LINKING)
	set(TEST_CMAKE_SDL2W_COMPONENTS "${TEST_CMAKE_SDL2W_COMPONENTS};static")
endif ()


# Find packages.
#
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(SDL2W 2.0.0 REQUIRED COMPONENTS ${TEST_CMAKE_SDL2W_COMPONENTS})


# Target.
#
add_executable(${PROJECT_NAME} "")


# Target properties.
#
if (WIN32)
	set_target_properties(
		${PROJECT_NAME}
		PROPERTIES
			WIN32_EXECUTABLE TRUE
	)
endif ()

# Dependencies.
#
if (MINGW)
	target_link_libraries(
		${PROJECT_NAME}
		PRIVATE
			-mconsole
	)
endif ()

if (TEST_CMAKE_SDL2W_USE_STATIC_LINKING)
	if (NOT WIN32 OR MINGW)
		target_link_libraries(
			${PROJECT_NAME}
			PRIVATE
				-static
		)
	endif ()
endif ()

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
		SDL2W
)

# Linking options.
#
if (MSVC)
	set_target_properties(
		${PROJECT_NAME}
		PROPERTIES
			LINK_FLAGS "/SUBSYSTEM:CONSOLE"
	)
endif ()

# Source files.
#
target_sources(
	${PROJECT_NAME}
	PRIVATE
		src/test_cmake_sdl2w.c
)

# Install.
#
install(
	TARGETS
	${PROJECT_NAME}
		RUNTIME DESTINATION "."
)
