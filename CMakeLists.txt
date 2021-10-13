cmake_minimum_required(VERSION 3.10)

# set the project name
project(rpge-4ume)

find_package(directxtk CONFIG REQUIRED)
find_package(directxmath CONFIG REQUIRED)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(LDtkLoader REQUIRED)

# add the executable
add_executable(${PROJECT_NAME} WIN32 Game.cpp Main.cpp pch.cpp  "Entity.cpp" resource.rc "BestiaryEntry.h" "BestiaryEntry.cpp" "Rand.h"  "TargetDialogue.h" "TargetDialogue.cpp")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

set(DIRECTXTK_LIBRARIES "Microsoft::DirectXTK")
target_link_libraries(${PROJECT_NAME} PRIVATE d3d11.lib dxgi.lib dxguid.lib uuid.lib kernel32.lib user32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib ${DIRECTXTK_LIBRARIES})

set(DIRECTX_MATH_LIBRARIES "Microsoft::DirectXMath")
target_link_libraries(${PROJECT_NAME} PRIVATE ${DIRECTX_MATH_LIBRARIES})

set(LDTKLOADER_LIBRARIES "LDtkLoader")
target_link_libraries(${PROJECT_NAME} PRIVATE ${LDTKLOADER_LIBRARIES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})