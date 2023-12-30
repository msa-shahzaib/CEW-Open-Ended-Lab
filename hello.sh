#!/usr/bin/sh

gcc -o test program.c -lcurl

while :
do
	./test
	sleep 1h

done
