#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct patient{
	char name[30]; 
	char phone_no[12];
	int age;
	char gender[2];
	char e_contact_name[30];
	char e_contact_phone[12];
	char history_file[34]; //name of file which contains history of patient's illness
	char presc_file[40]; //name of file with list of precription files
} patient;

void add_patient()
{
	FILE *fp;
	patient a,b;
	char history_file[34]; //name of history file
	char buf[1000];
	

	fp = fopen("patient_details.bin","ab+"); //opening in append mode
	printf("Enter name\n");
	scanf("%s",a.name);
	getchar();

	printf("Enter gender (M - male, F - female, O - other)\n");
	scanf("%s",a.gender);
	getchar();

	printf("Enter age\n");
	scanf("%d",&a.age);
	getchar();

	printf("Enter phone number\n");
	scanf("%s",a.phone_no);
	getchar();

	printf("Enter emergency contact's name\n");
	scanf("%s",a.e_contact_name);
	getchar();

	printf("Enter emergency contact's phone number\n");
	scanf("%s",a.e_contact_phone);
	getchar();


	printf("Enter previous medical history\n"); 
	strcpy(history_file,a.name);//copying patient name
	strcat(history_file,&a.phone_no[6]); //copying last 4 digits of phone number
	strcpy(a.history_file,history_file); //name of history file : patient name + last 4 digits of phone number
	fgets(buf, 1000, stdin); //collecting medical history information
	FILE *f = fopen(a.history_file,"w"); //new file with history details
	fputs(buf,f);
	fclose(f);

	fwrite(&a,sizeof(patient),1,fp); //writing into patient_details file
	fclose(fp);
}
	
patient *read_patient(int *no_of_rec)
{
	FILE* fp;
	patient *c; //array of struct patient
	fp = fopen("patient_details.bin", "rb");
	fseek(fp, 0L, SEEK_END); //moving file pointer to end
	size_t size = ftell(fp); //finding the size of file
	fseek(fp, 0L, SEEK_SET); //moving file pointer to beginning
	c = (patient *)malloc(size); //allocating memory for the array
	*no_of_rec = size/sizeof(patient); //number of records in the file
	fread(c,sizeof(patient),*no_of_rec,fp); //reading into the array
    	fclose(fp);
	return c;
}


