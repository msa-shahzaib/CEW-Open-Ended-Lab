#!/usr/bin/sh

case $1 in
'e')
	gcc -o alert alert.c mail.c
	./alert
	;;
	
'r')
	echo "report generated";;
esac
