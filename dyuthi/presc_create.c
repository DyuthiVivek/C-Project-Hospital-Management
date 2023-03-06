#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <patient_fns.h>


char *create_presc()
{
	char name[30];
	char dis[20];
	char med[50];
	char adv[1000];
	int n,flag = 0;
	int i=0;
	printf("Enter patient name\n"); //reading patient name 
	scanf("%s",name);

	patient *c = read_patient(&n);
	for(; i<n ; i++)
	{
		if(strcmp(name,c[i].name)==0) //checking if patient present in records
		{
			flag = 1;
			break;
		}
	}
	if(flag==0)
	{
		printf("No such patient exists\n"); //no patient found
		return NULL;
	}

	printf("Enter disease/ailment being treated for\n");
	scanf("%s",dis);
	getchar();
	dis[10] = '\0';
	strcpy(c[i].presc_file,c[i].name);
	strcat(c[i].presc_file,"_"); 
	strcat(c[i].presc_file,dis); //name of prescription file will contain patient name and disease

	FILE *f = fopen(c[i].presc_file,"w"); 

	while(1)
	{
		printf("Enter medicine name, n to quit\n"); //reading names of the medicines
		fgets(med,50,stdin);	
		if(strncmp(med,"n",1)==0)
			break;
		fprintf(f,"%s",med);
	}
	printf("Enter advice\n"); //reading advice
	fgets(adv, 1000, stdin);
	fputs(adv,f);
	fclose(f);
	return c[i].presc_file;


}

void main()
{
char *b = create_presc();
	if(b!=NULL)
		printf("%s\n",b);
}
