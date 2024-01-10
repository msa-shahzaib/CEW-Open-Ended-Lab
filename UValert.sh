#!/usr/bin/sh

case $1 in
'e')
	gcc -o alert alert.c mail.c
	./alert
	;;
	
'r')
	true > Report.txt
	gcc report.c -o report
	./report
	echo "\nReport Generated! \n";;
esac

