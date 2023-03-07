#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <patient_fns.h>
#include <presc_fns.h>
#include <pharma_fns.h>


void create_presc() //creates prescription with input information for a specific patient, returning name of prescription
{
	char name[31];
	char dis[20];
	char med[50];
	char adv[1000];
	char presc_file[30];
	int n,flag = 0;
	int i=0;

	printf("Enter patient name\n"); //reading patient name 
	fgets(name,30,stdin);
	name[strlen(name)-1] = 0;

	patient *c = read_patient(&n); //reading the list of patients into an array
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
		return;
	}

	printf("Enter disease/ailment being treated for\n"); //name of disease
	fgets(dis,20,stdin);
	dis[strlen(dis)-1] = 0;
	dis[10] = '\0';

	strcpy(presc_file,c[i].name);
	strcat(presc_file,"_"); 
	strcat(presc_file,dis); //name of prescription file will contain patient name and disease

	FILE *f = fopen(presc_file,"w"); //creating prescription file
	int k;
	while(1)
	{
		printf("Enter medicine name, n to quit\n"); //reading names of the medicines
		fgets(med,50,stdin);	
		med[strlen(med)-1] = 0;
		if(strncmp(med,"n",1)==0)
			break;
		fprintf(f,"%s\n",med);
	
	}
	fclose(f);
}

