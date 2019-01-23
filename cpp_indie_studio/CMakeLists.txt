cmake_minimum_required(VERSION 3.0)

project(bomberman)

add_definitions(-Wall -W -lIrrlicht -lGL -lGLU -lXxf86vm -lX11 -lSDL_mixer -lSDL)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_LIBRARIES "-Wall -W -lIrrlicht -lGL -lGLU -lXxf86vm -lX11 -lSDL_mixer -lSDL")
include_directories(include)

file(GLOB SRCS
"src/*.cpp"
)

file(GLOB LIB "installsrc/lib*")

install(FILES ${LIB} DESTINATION /usr/lib)
install(FILES installsrc/mikmod.h DESTINATION /usr/include)
install(DIRECTORY installsrc/irr DESTINATION /usr/include)
install(DIRECTORY installsrc/SDL DESTINATION /usr/include)

set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY TRUE)

add_executable(bomberman ${SRCS})