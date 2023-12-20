#!/usr/bin/sh

echo "shell created \n"
touch data.txt
gcc -o test program.c -lcurl


while :
do
	./test
	echo "\n"
	sleep 30

done
