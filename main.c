#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <patient_fns.h>
#include <presc_fns.h>
#include <patient_login.h>
#include <pharmacist_login.h>
#include <appointment_fns.h>
#include <employeenew.h>
#include <doc_admin_login.h>



int main()
{
	while(1)
	{
		printf("1. Doctor\n");
		printf("2. Patient\n");
		printf("3. Pharmacist\n");
		printf("4. Admin\n\n");

		printf("Enter choice\n");
		char c[2];
		fgets(c,2,stdin);
		getchar();
		int i = atoi(c);

		switch(i)
		{
			case 1:
				doctor_login();
				break;
			case 2:
				patient_login();
				break;
			case 3:
				pharmacist_login();
				break;
			case 4:
				admin_login();
				break;
			default:
				return 0;
		}
	}
}
