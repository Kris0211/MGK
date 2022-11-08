# CMakeList.txt: projekt CMake dla elementu MGK2, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (MGK2 "main.cpp"  "HVector.h" "HVector.cpp" "HMatrix4.h" "HMatrix4.cpp")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
