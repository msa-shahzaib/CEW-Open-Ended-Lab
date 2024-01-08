#!/usr/bin/sh

gcc -o test program.c mail.c -lcurl
./test
