#[[
SDL2W - CMake wrapper for SDL2.
Test program.

Copyright (c) 2018-2024 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors.
SPDX-License-Identifier: MIT
]]


cmake_minimum_required(VERSION 3.5.0 FATAL_ERROR)
project(test_cmake_sdl2w VERSION 1.0.6 LANGUAGES C)

# Options.
#
option(TEST_CMAKE_SDL2W_USE_STATIC_LINKING "Use static linking." OFF)
option(TEST_CMAKE_SDL2W_NET "Use SDL_net." ON)

# Setup components.
#
set(TEST_CMAKE_SDL2W_COMPONENTS "")
set(TEST_CMAKE_SDL2W_NET_COMPONENTS "")

if (TEST_CMAKE_SDL2W_USE_STATIC_LINKING)
	set(TEST_CMAKE_SDL2W_COMPONENTS "${TEST_CMAKE_SDL2W_COMPONENTS};static")

	if (TEST_CMAKE_SDL2W_NET)
		set(TEST_CMAKE_SDL2W_NET_COMPONENTS "${TEST_CMAKE_SDL2W_NET_COMPONENTS};static")
	endif ()
endif ()


# Find packages.
#
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(SDL2W 2.0.0 REQUIRED COMPONENTS ${TEST_CMAKE_SDL2W_COMPONENTS})

if (TEST_CMAKE_SDL2W_NET)
	find_package(SDL2W_net 2.0.0 REQUIRED COMPONENTS ${TEST_CMAKE_SDL2W_NET_COMPONENTS})
endif ()


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

# Compile definitions.
#
if (TEST_CMAKE_SDL2W_NET)
	target_compile_definitions(
		${PROJECT_NAME}
		PRIVATE
			TEST_CMAKE_SDL2W_NET
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

if (TEST_CMAKE_SDL2W_NET)
	target_link_libraries(
		${PROJECT_NAME}
		PRIVATE
			SDL2W_net::SDL2W_net
	)
endif ()

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
		SDL2W::SDL2Wmain
		SDL2W::SDL2W
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
	RUNTIME
	DESTINATION "."
)
