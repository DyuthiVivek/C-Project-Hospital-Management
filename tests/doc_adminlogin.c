#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<employee.h>
#include<appointment_fns.h>
#include<patient_fns.h>
#include<presc_create.h>
void doctor_login(){
		int did;
		struct employee * x;
		char dname[30];
		printf("PLEASE ENTER ID\n");
		scanf("%d",&did);
		x=retrieveid1(head,did);
		if (strcmp(x->dept,'DOCTOR')==0 && x!=NULL){
			printf("PLEASE ENTER OPTION NUMBER TO CONTINUE: \n");
			printf("1.VIEW ALL APPOINTMENTS\n");
			printf("2.CHECK PARTICULAR PATIENT\n");
			printf("3.WRITE PRESCRIPTION FOR PATIENT\n");
			scanf("%d",&opt);
			switch(opt){
				case 1:{
					        strcpy(dname,x->name)
				       		list_appointments_for_doc(dname);
				       		break;
				       }
				case 2:{
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
				       }
				case 3:{
						create_presc();
						break;
				 	}
			}}
		else{
			printf("NO ACCOUNT FOUND\n");}}

void admin_login(){
		int adid;
		struct employee * x;
		char adname[30];
		printf("PLEASE ENTER ID\n");
		scanf("%d",&adid);
		x=retrieveid1(head,adid);
		if (strcmp(x->dept,'ADMIN')==0 && x!=NULL){
			 struct employee * head=NULL;
         		struct employee * ptr;
         		int did,ddob,dage,n,p,l,didaf;
         		float dsalary;
         		long int dphone;
         		char dname[30],dnamedel[30],ddept[30],demail[35];
         		char dsex;
         		printf("*****************************************************************************************************************************************************************************\n");
         		while(1){
         		printf("\n\t\t\t\t\t\t\t\tMENU\n\n");
         		printf("1.INSERT RECORD\n");
         		printf("2.VIEW ALL RECORDS\n");
         		printf("3.RETRIEVE RECORD\n");
         		printf("4.DELETE RECORD\n");
         		printf("CAUTION DELETE RECORD ONLY USING NAME\n");
         		printf("5.UPDATE RECORD\n");
         		printf("6.EXIT\n");

                 	printf("\nENTER OPTION NUMBER: ");
                 	scanf("%d",&n);
                 	switch(n){
                        	 case 1:{
                                	 printf("-----------------------------------------------------------------------------------\n");
                          	       printf("PLEASE ENTER  STAFF ID   STAFF NAME   DOB   AGE   SEX   DEPARTMENT   SALARY   EMAIL ID   PHONE NUMBER \n");
	                                 ptr=read();
        	                         head=insertemployee(head,ptr);
                	                 printf("RECORD ADDED\n");
                        	         printf("-----------------------------------------------------------------------------------\n");
                                	 break;}
	                         case 2:{
        	                         printf("-----------------------------------------------------------------------------------\n");
        	                         print(head);
                	                 printf("-----------------------------------------------------------------------------------\n");
                        	         break;}
                        	 case 3:{
                                         printf("-----------------------------------------------------------------------------------\n");
                                         printf("PLEASE ENTER OPTION NUMBER: \n");
                                         printf("1.SEARCH BY NAME\n");
                                         printf("2.SEARCH BY ID\n");
                                         printf("3.SEARCH BY DOB\n");
                                         printf("4.SEARCH BY SEX\n");
                                         printf("5.SEARCH BY AGE\n");
                                         printf("6.SEARCH BY DEPARTMENT\n");
                                         printf("7.SEARCH BY SALARY\n");
                                         printf("8.SEARCH BY EMAIL\n");
                                         printf("9.SEARCH BY PHONE NUMBER\n");
                                         scanf("%d",&p);
                                         switch(p){
                                                 case 1:{
                                                         scanf("%s",dname);
                                                         retrievename(head,dname);break;}
                                                 case 2:{
                                                         scanf("%d",&did);
                                                         retrieveid(head,did);break;}
						 case 3:{
                                                        scanf("%d",&ddob);
                                                        retrievedob(head,ddob);break;}
                                                 case 4:{
                                                        scanf("%c",&dsex);
                                                        retrievesex(head,dsex);break;}
                                                 case 5:{
                                                        scanf("%d",&dage);
                                                        retrieveage(head,dage);break;}
                                                 case 6:{
                                                        scanf("%s",ddept);
                                                        retrievedept(head,ddept);break;}
                                                 case 7:{
                                                        scanf("%f",&dsalary);
                                                        retrievesalary(head,dsalary);break;}
                                                 case 8:{
                                                        scanf("%s",demail);
                                                        retrieveemail(head,demail);break;}
                                                 case 9:{
                                                        scanf("%ld",&dphone);
                                                        retrievephone(head,dphone);break;}}
                                        printf("-----------------------------------------------------------------------------------\n");
                                        break;}
                       		 case 4:{
                                        printf("-----------------------------------------------------------------------------------\n");
                                        printf("PLEASE ENTER NAME TO DELETE\n");
                                        scanf("%s",dnamedel);
                                        head=deletebyname(head,dnamedel);
                                        printf("RECORD DELETED OR RECORD WITH GIVEN NAME NOT FOUND\n");
                                        printf("-----------------------------------------------------------------------------------\n");
                                        break;}
                     	   case 5:{
                                        printf("-----------------------------------------------------------------------------------\n");
                                        printf("PLEASE ENTER OPTION NUMBER: \n");
                                        printf("1.UPDATE NAME\n");
                                        printf("2.UPDATE ID\n");
                                        printf("3.UPDATE DOB\n");
                                        printf("4.UPDATE SEX\n");
                                        printf("5.UPDATE AGE\n");
                                        printf("6.UPDATE DEPARTMENT\n");
                                        printf("7.UPDATE SALARY\n");
                                        printf("8.UPDATE EMAIL\n");
                                        printf("9.UPDATE PHONE NUMBER\n");
                                        scanf("%d",&l);
                                        printf("PLEASE ENTER STAFF ID: \n");
                                        scanf("%d",&did);
                                        switch(l){
                                                case 1:{
                                                               printf("PLEASE ENTER NEW NAME\n");
                                                               scanf("%s",dname);
                                                                head=updatename(head,did,dname);break;}
                                                case 2:{
                                                               printf("PLEASE ENTER NEW ID\n");
                                                               scanf("%d",&didaf);
                                                                head=updateid(head,did,didaf);break;}
                                                case 3:{
                                                               printf("PLEASE ENTER NEW DOB\n");
                                                               scanf("%d",&ddob);
                                                                head=updatedob(head,did,ddob);break;}
                                                case 4:{
                                                               printf("PLEASE ENTER NEW SEX\n");
                                                               scanf("%c",&dsex);
                                                                head=updatesex(head,did,dsex);break;}
                                                case 5:{
                                                               printf("PLEASE ENTER NEW AGE\n");
                                                               scanf("%d",&dage);
                                                                head=updateage(head,did,dage);break;}
                                                case 6:{
                                                               printf("PLEASE ENTER NEW DEPARTMENT\n");
                                                               scanf("%s",ddept);
                                                                head=updatedept(head,did,ddept);break;}
                                                case 7:{
                                                               printf("PLEASE ENTER NEW SALARY\n");
                                                               scanf("%f",&dsalary);
                                                                head=updatesalary(head,did,dsalary);break;}
                                                case 8:{
                                                               printf("PLEASE ENTER NEW EMAIL\n");
                                                               scanf("%s",demail);
                                                                head=updateemail(head,did,demail);break;}
                                                case 9:{
                                                               printf("PLEASE ENTER NEW PHONE NUMBER\n");
                                                               scanf("%ld",&dphone);
                                                                head=updatephone(head,did,dphone);break;}}
                                        printf("RECORD UPDATED\n");
                                        printf("-----------------------------------------------------------------------------------\n");break;}
                     	   case 6:{
                                        printf("*****************************************************************************************************************************************************************************\n");
                                        exit(0);}}}}
			
		else{
			printf("NO ACCOUNT FOUND\n");}}
