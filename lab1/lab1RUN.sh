#! /usr/bin/bash

echo ""
echo -e "\e[36mCompile and Run Lab1\e[0m"
printf '%.s─' $(seq 1 $(tput cols))
echo -e "\e[32mcompiling...\e[0m"
make
make clean
echo -e "\e[32m...complete\e[0m"
printf '%.s─' $(seq 1 $(tput cols))
./lab1
echo $?
echo ""
echo "Opening processed image"
open processedClover.pgm
echo ""
