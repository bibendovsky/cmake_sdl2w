# CMake wrapper for SDL2 / SDL2_net module.

## CMake variables for test program.
- TEST_CMAKE_SDL2W_USE_STATIC_LINKING - links the test program statically (default `OFF`).
- TEST_CMAKE_SDL2W_NET - enables SDL2_net (default `ON`).

## Notes
- If you are using target `SDL2W::SDL2Wmain` make sure it linked before `SDL2W::SDL2W`.
