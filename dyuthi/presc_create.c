#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient_fns.h"

extern patient *c;

void create_presc()
{
	char name[30];
	char dis[20];
	char med[10];
	char adv[1000];
	int n,flag = 0;
	int i=0;
	printf("Enter patient name\n");
	scanf("%s",name);
	patient *c = read_patient(&n);
	for(; i<n ; i++)
	{
		if(strcmp(name,c[i].name)==0)
		{
			flag = 1;
			break;
		}
	}
	if(flag==0)
	{
		printf("No such patient exists\n");
		return;
	}

	printf("Enter disease/ailment being treated for\n");
	scanf("%s",dis);
	dis[10] = '\0';
	strcpy(c[i].presc_file,c[i].name);
	strcat(c[i].presc_file,dis);

	FILE *f = fopen(c[i].presc_file,"w"); 
	int k = 1;

	while(1)
	{
		printf("Enter medicine name, n to quit\n");
		scanf("%s",med);
		getchar();
		if(strcmp(med,"n")==0)
			break;
		fprintf(f,"%s\n",med);
	}
	printf("Enter advice, n if nothing\n");
	fgets(adv, 1000, stdin);
//	if(strcmp(adv,"n")!=0)
	fputs(adv,f);
	fclose(f);
}

void main()
{
	create_presc();

