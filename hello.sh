#!/usr/bin/sh

gcc -o test program.c mail.c -lcurl
while :
do 
	./test
	sleep 1h
done
