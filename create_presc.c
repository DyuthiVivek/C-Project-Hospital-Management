//INCOMPLETE, DO NOT USE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient_fns.h"

extern patient *c;

void create_presc()
{
	char name[30];
	char dis[20];
	char med[1000];
	char * token;
	int n,flag = 0;
	printf("Enter patient name");
	scanf("%s",name);
	c = read_patient(&n);
	for(int i=0; i<n ; i++)
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
	strcpy(c.presc_file,c.name);
	strcat(c.presc_file,dis);

	FILE *f = fopen(c.presec_file,"w"); 
	printf("Enter names of the medicines, space separated\n");
	fgets(med, 1000, stdin);
	token = strtok(med, " ");
	while( token != NULL )
       	{
		//if check_avail(token)
			printf( "%s not available\n",token); //printing each token
		token = strtok(NULL, " ");
	}
	fclose(f);
	



}
