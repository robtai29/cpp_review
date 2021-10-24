#!/bin/bash


# make this file executable
# $ chmod 700 simplecompile.sh
# redirect the output and stderr from this file to output.txt
# $ ./simplecompile.sh > output.txt 2>&1
#TO ENABLE CLANGTIDY do this EVERYTIME on linux lab: scl enable llvm-toolset-7.0 bash

date
echo "Time to get some coding done!"
echo -e "*** compiling with clang++ to create an executable called myprogram \n"

clang++ --version
clang++ -std=c++17 -Wall -Wextra -Wno-sign-compare *.cpp -g -o main


echo -e "*** running myprogram\n"

chmod +x ./main
./main file.txt

# valgrind will detect memory leaks
# echo "*** running with valgrind"
# valgrind --leak-check=full ./myprogram.exe

echo -e "\n\n*** cleaning up, deleting myprogram. See you"
rm myprogram

date