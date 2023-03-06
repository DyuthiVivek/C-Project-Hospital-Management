#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char str[100];
	char cmd[100];

	sprintf(cmd,"ls %s*","Anya");
	FILE *fp=popen(cmd,"r");
	while(fgets(str,100,fp)) {
		printf("***%s",str);
	}
	pclose(fp);
}
