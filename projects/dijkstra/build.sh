#!/bin/bash


# make this file executable
# $ chmod 700 simplecompile.sh
# redirect the output and stderr from this file to output.txt
# $ ./simplecompile.sh > output.txt 2>&1


date

echo -e "*** compiling with clang++ to create an executable called myprogram \n"

clang++ --version
clang++ -std=c++17 -Wall -Wextra -Wno-sign-compare *.cpp -g -o myprogram


echo -e "*** running myprogram\n"

./myprogram

# valgrind will detect memory leaks
# echo "*** running with valgrind"
# valgrind --leak-check=full ./myprogram.exe

echo -e "\n\n*** cleaning up, deleting myprogram. See you"
rm myprogram

date
