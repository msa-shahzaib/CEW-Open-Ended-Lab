#include <stdio.h>
#include "mail.h"

int main(){
	FILE *f;
	float uv;
	f = fopen("data.txt","r");
	fseek(f,-4,SEEK_END);
	fscanf(f,"%f",&uv);
	fclose(f);
	writeMail("mail.txt",uv);
	return 0;
}
