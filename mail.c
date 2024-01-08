#include <stdio.h>
#include <stdlib.h>
#include "mail.h"

void writeMail(const char *fileName,float uv){
	FILE *f;
	char str[400];
	if (uv>6.0){
		f = fopen(fileName,"w");
		fprintf(f,"From: \"Abdul Moiz\"\nTo: \"Shahzaib\"\nSubject: Greetings\n");
		fprintf(f,"The UV index is currently %.1f\n",uv);
		fprintf(f,"If you are outside make sure to get into shed\n");
		fclose(f);
		system("curl --ssl-reqd --url 'smtps://smtp.gmail.com:465' --user 'cisabdulmoiz136@gmail.com:xaiw dopm fzbg dkvp' --mail-from 'cisabdulmoiz136@gmail.com' --mail-rcpt 'amoizmateen777@gmail.com' --upload-file mail.txt");
		printf("Mail Sent");
	}
	else
	{
		printf("UV is currently low\n");
	}
}

