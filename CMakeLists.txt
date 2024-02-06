cmake_minimum_required(VERSION 3.26)
project(Lab1_clion C)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS "/TC /Gz")
set(CMAKE_SHARED_LINKER_FLAGS "/DYNAMICBASE")
set(CMAKE_EXE_LINKER_FLAGS "/DYNAMICBASE")

add_definitions(-DECO_WINDOWS)
add_definitions(-D_DEBUG)
add_definitions(-DECO_DLL)
add_definitions(-DUGUID_UTILITY)
add_definitions(-DECO_WIN32)
add_definitions(-DWIN32)
add_definitions(-D_WINDOWS)
add_definitions(-D_CONSOLE)

include_directories(Lab1/HeaderFiles)
include_directories(Lab1/SharedFiles)
include_directories(UnitTest/HeaderFiles)

include_directories(
        $ENV{ECO_FRAMEWORK}/Eco.List1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Core1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.InterfaceBus1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.System1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.MemoryManager1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.FileSystemManagement1/SharedFiles
)


add_library(
        1F5DF16EE1BF43B999A434ED38FE8F3A
        SHARED
        Lab1/SourceFiles/CEcoLab1.c
        Lab1/SourceFiles/CEcoLab1Factory.c
        Lab1/SharedFiles/IdEcoLab1.h
        Lab1/SharedFiles/IEcoLab1.h
        Lab1/HeaderFiles/CEcoLab1.h
        Lab1/HeaderFiles/CEcoLab1Factory.h
)

add_executable(
        Lab1_clion
        UnitTest/SourceFiles/EcoLab1.c
        Lab1/SharedFiles/IdEcoLab1.h
        Lab1/SharedFiles/IEcoLab1.h
        Lab1/HeaderFiles/CEcoLab1.h
        Lab1/HeaderFiles/CEcoLab1Factory.h
)

target_link_libraries(Lab1_clion 1F5DF16EE1BF43B999A434ED38FE8F3A)
target_link_libraries(
        Lab1_clion
        $ENV{ECO_FRAMEWORK}/Eco.InterfaceBus1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000042757331.lib
        $ENV{ECO_FRAMEWORK}/Eco.MemoryManager1/BuildFiles/Windows/x86/StaticRelease/0000000000000000000000004D656D31.lib
        $ENV{ECO_FRAMEWORK}/Eco.FileSystemManagement1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000046534D31.lib
        $ENV{ECO_FRAMEWORK}/Eco.System1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000000000100.lib
)
