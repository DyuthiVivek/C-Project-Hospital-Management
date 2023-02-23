#include <stdio.h>
#include "patient_fns.h"
extern patient *c;
void main()
{
	//add_patient();
	int n; //number of records
	patient *c = read_patient(&n);
	for (int i = 0; i < n; i++) {
		printf("%s\n",c[i].name);
		printf("%s\n",c[i].phone_no);
		printf("%s\n",c[i].e_contact_name);
		printf("%s\n",c[i].e_contact_phone);
	}
}

