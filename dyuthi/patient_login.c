#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <patient_fns.h>
#include <presc_fns.h>
#include <pharma_fns.h>
#include <appointment_fns.h>

void show_more_functions(char name[31],char phone[15])
{
	while(1)
	{

		printf("\n1. Check your details\n");
		printf("2. Buy medicines from prescription\n");
		printf("3. Manage appointments\n\n");

		printf("Enter choice\n");
		printf("Enter any other number to quit\n\n");
		char ch[2];
		fgets(ch,2,stdin);
		getchar();
		int i = atoi(ch);

		switch(i)
		{
			case 1:
				patient b;
				int n;
				patient *c = read_patient(&n);
				b = read_specific_patient(c,n,name);

				printf("Name: %s\n",b.name);
				printf("Phone: %s\n",b.phone_no);
				printf("Age: %d\n",b.age);
				printf("Gender: %c\n",b.gender[0]);
				printf("Emergency contact name: %s\n",b.e_contact_name);
				printf("Emergency contact phone number: %s\n",b.e_contact_phone);
				printf("Name of history file: %s\n",b.history_file);

				break;
			case 2:
				struct node *head = return_cart(name);
				get_med_prescription(head);

				break;

			case 3:
				apptmenu(phone);

			default:
				return;
		}
	}
}

void patient_login()
{
	while(1)
	{
		printf("\n1. Sign up\n");
		printf("2. Sign in\n");

		printf("Enter choice\n");
		printf("Enter any other number to quit\n\n");
		char c[2];
		fgets(c,2,stdin);
		getchar();
		int i = atoi(c);

		switch(i)
		{
			case 1:
				add_patient();
				break;
			case 2:
				/*
				int n;
				patient *c = read_patient(&n);
				for (int i = 0; i < n; i++) {
					printf("%s\n",c[i].name);
					printf("%s\n",c[i].phone_no);
					printf("%d\n",c[i].age);
					printf("%s\n",c[i].e_contact_name);
					printf("%s\n",c[i].e_contact_phone);
				}
				*/
				int n;
				patient *c = read_patient(&n);

				char name[31];
				printf("Enter your name\n");
				fgets(name,30,stdin);
				name[strlen(name)-1]=0;

				patient b;
				b = read_specific_patient(c,n,name);

				if(check_patient(name))
				{
					printf("Logged in successfully\n");
					show_more_functions(name,b.phone_no);
				}
				else
					printf("No such patient exists\n");
					break;

				break;
			default:
				return;
		}
	}

}

