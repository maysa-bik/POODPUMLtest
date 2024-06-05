cmake_minimum_required(VERSION 3.10)
project(towerDefense VERSION 0.1.0 LANGUAGES C CXX)

# Définir le chemin vers SFML
set(SFML_DIR "C:/Program Files/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/lib/cmake/SFML")

# Rechercher et inclure SFML
find_package(SFML 2.6.1 COMPONENTS graphics audio REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

# Ajouter les fichiers sources
add_executable(towerDefense 
        src/main.cpp
        src/Menu.cpp
)

# Ajouter les répertoires d'inclusion
target_include_directories(towerDefense PRIVATE include) # Ajoutez le chemin vers le dossier include

# Lier les bibliothèques SFML
target_link_libraries(towerDefense sfml-graphics sfml-audio)

# Ajouter les tests
include(CTest)
enable_testing()

# Configuration CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

