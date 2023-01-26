# CMakeList.txt: projeto de CMake para LitoEngine, incluir origem e definir
# lógica específica a um projeto aqui.
#
#cmake_minimum_required (VERSION 3.8)
#
#project ("LitoEngine")
#
## Adicione a origem ao executável deste projeto.
#add_executable (LitoEngine "LitoEngine.cpp" "LitoEngine.h")
#
# TODO: Adicione testes e instale destinos, se necessário.

# CMakeList.txt: projeto de CMake para LitoEngine, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.0.0)

project ("LitoEngine")

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_library(
    LITO_ENGINES STATIC
    engines/Engine_OpenGl.h engines/Engine_OpenGl.cpp
    engines/Engine_SDL.h    engines/Engine_SDL.cpp
    shaders/Shader.h        shaders/Shader.cpp
)
target_link_libraries(LITO_ENGINES PUBLIC SDL2 GLEW)
target_include_directories(
    LITO_ENGINES PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/engines"
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders"
)

add_library(
    LITO_ALGEBRA INTERFACE
)
target_link_directories(LITO_ALGEBRA INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/algebra")
target_include_directories(
    LITO_ALGEBRA INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/algebra"
)

add_library(
    LITO_FISICA INTERFACE
)
target_link_directories(LITO_FISICA INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/fisica")
target_include_directories(
    LITO_FISICA INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/fisica"
)

# Adicione a origem ao executável deste projeto.
add_executable (LitoEngine "LitoEngine.cpp" "LitoEngine.h")
target_link_libraries(LitoEngine LITO_ENGINES)