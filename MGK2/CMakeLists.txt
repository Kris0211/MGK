﻿# CMakeList.txt: projekt CMake dla elementu MGK2, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (MGK2 "main.cpp"  "HVector.h" "HVector.cpp" "HMatrix4.h" "HMatrix4.cpp" "HMatrix3.h" "HMatrix3.cpp"   "HVector4.h" "HVector4.cpp" "HQuat.h" "HQuat.cpp"    "HUtils.h" "HUtils.cpp" "HLine.h" "HLine.cpp" "HPlane.h" "HPlane.cpp" "HSegment.h" "HSegment.cpp" "HSphere.h" "HSphere.cpp" "HRTX.h" "HRTX.cpp" "HCube.h" "HCube.cpp")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
