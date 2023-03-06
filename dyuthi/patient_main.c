#include <stdio.h>
#include <patient_fns.h>
#include <string.h>

void main()
{
	//add_patient();
	//add_patient();
	int n; //number of records
	patient *c = read_patient(&n);
	/*
	for (int i = 0; i < n; i++) {
		printf("%s\n",c[i].name);
		printf("%s\n",c[i].phone_no);
		printf("%d\n",c[i].age);
		printf("%s\n",c[i].e_contact_name);
		printf("%s\n",c[i].e_contact_phone);
	}
	*/
	char name[30];
	scanf("%s",name);
	if(check_patient(name)==0)
		printf("no such patient");
	else
	{
		patient b;
		b = read_specific_patient(c,n,name);
		
		printf("%s\n",b.name);
		printf("%s\n",b.phone_no);
		printf("%d\n",b.age);
		printf("%s\n",b.e_contact_name);
		printf("%s\n",b.e_contact_phone);
	}

}

