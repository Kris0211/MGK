# CMakeList.txt: plik projektu CMake najwyższego poziomu, wykonaj konfigurację globalną
# i uwzględnij podprojekty w tym miejscu.
#
cmake_minimum_required (VERSION 3.8)

project ("MGK2")

# Uwzględnij podprojekty.
add_subdirectory ("MGK2")
