#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<employeenew.h>
#include<appointment_fns.h>
#include<doc_admin_login.h>
#include<patient_fns.h>
#include<presc_fns.h>

void doctor_login(){
		int opt;
		int did;
		struct employee *x;
		char dname[30];
		printf("PLEASE ENTER ID\n");
		scanf("%d",&did);
		FILE *fp;
		fp=fopen("employee.bin","rb+");
		if (fp!=NULL){
			while(fread(x,sizeof(struct employee),1,fp)){

			if (strcmp(x->dept,"DOCTOR")==0 && x->id==did){
				printf("PLEASE ENTER OPTION NUMBER TO CONTINUE: \n");
				printf("1.VIEW ALL APPOINTMENTS\n");
				printf("2.CHECK PARTICULAR PATIENT\n");
				printf("3.WRITE PRESCRIPTION FOR PATIENT\n");
				scanf("%d",&opt);
				switch(opt){
					case 1:{
					        strcpy(dname,x->name);
				       		list_appointments_for_doc(dname);
				       		break;
					       }
					case 2:{
						patient b;
						int n;
						char name[31];
						printf("Enter name:");
						fgets(name,31,stdin);
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
			}}}}
			else{
				printf("NO ACCOUNT FOUND\n");}}

void admin_login(){int adid;
		FILE *fp;
		struct employee *x;
		int didx;

		scanf("%d",&didx);
		if (fp!=NULL){
				while(fread(x,sizeof(struct employee),1,fp)){
				if (strcmp(x->dept,"ADMIN")==0 && x->id==didx){
                char adname[30];
                        int did,dage,n,p,l,didaf;
                        char ddob[8];
                        float dsalary;
                        char dphone[10];
                        char dname[30],dnamedel[30],ddept[30],demail[35];
                        char dsex;
                        printf("*****************************************************************************************************************************************************************************\n");
                        while(1){
                        printf("\n\t\t\t\t\t\t\t\tMENU\n\n");
                        printf("1.INSERT RECORD\n");
                        printf("2.VIEW ALL RECORDS\n");
                        printf("3.RETRIEVE RECORD\n");
                        printf("4.DELETE RECORD\n");
                        printf("CAUTION DELETE RECORD ONLY USING ID\n");
                        printf("5.UPDATE RECORD\n");
                        printf("6.EXIT\n");

                        printf("\nENTER OPTION NUMBER: ");
                        scanf("%d",&n);
                        switch(n){
                                 case 1:{
                                         printf("-----------------------------------------------------------------------------------\n");
                                         insertemployee();
                                         printf("RECORD ADDED\n");
                                         printf("-----------------------------------------------------------------------------------\n");
                                         break;}
                                 case 2:{
                                         printf("-----------------------------------------------------------------------------------\n"); printf("\t\t\t\t\t\tEMPLOYEE DATABASE\n\n\n");
                                         printf("\n");
                                         print();
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
                                                 case 1:{printf("PLEASE ENTER NAME\n");
                                                         scanf("%s",dname);
                                                         retrievename(dname);break;}
                                                 case 2:{printf("PLEASE ENTER ID\n");
                                                         scanf("%d",&did);
                                                         retrieveid(did);break;}
                                                 case 3:{printf("PLEASE ENTER DATE OF BIRTH\n");
                                                        scanf("%s",ddob);
                                                        retrievedob(ddob);break;}
                                                 case 4:{printf("PLEASE ENTER GENDER\n");
                                                        scanf("%c",&dsex);
                                                        retrievesex(dsex);break;}
                                                 case 5:{printf("PLEASE ENTER AGE\n");
                                                        scanf("%d",&dage);
                                                        retrieveage(dage);break;}
 case 6:{printf("PLEASE ENTER DEPARTMENT\n");
                                                        scanf("%s",ddept);
                                                        retrievedept(ddept);break;}
                                                 case 7:{printf("PLEASE ENTER SALARY\n");
                                                        scanf("%f",&dsalary);
                                                        retrievesalary(dsalary);break;}
                                                 case 8:{printf("PLEASE ENTER EMAIL ID\n");
                                                        scanf("%s",demail);
                                                        retrieveemail(demail);break;}
                                                 case 9:{printf("PLEASE ENTER PHONE NUMBER\n");
                                                        scanf("%s",dphone);
                                                        retrievephone(dphone);break;}}
                                        printf("-----------------------------------------------------------------------------------\n");
                                        break;}
                                 case 4:{
                                        printf("-----------------------------------------------------------------------------------\n");
                                        printf("PLEASE ENTER ID TO DELETE\n");
                                        scanf("%d",&did);
                                        /*struct employee temp;
                                        FILE * fp=fopen("employee.bin","rb+");
                                        if(fp!=NULL){
                                                while(fread(&temp,sizeof(struct employee),1,fp)){
                                                        if(temp.id==did){
  deletex(&temp);
                                                                break;}}}*/
                                        deletex(did);
                                        //deletebyname(did);
                                        printf("RECORD DELETED \n");
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
                                                               updatename(did,dname);break;}
                                                case 2:{
                                                               printf("PLEASE ENTER NEW ID\n");
                                                               scanf("%d",&didaf);
                                                                updateid(did,didaf);break;}
                                                case 3:{
                                                               printf("PLEASE ENTER NEW DOB\n");
 scanf("%s",ddob);
                                                                updatedob(did,ddob);break;}
                                                case 4:{
                                                               printf("PLEASE ENTER NEW SEX\n");
                                                               scanf("%c",&dsex);
                                                               updatesex(did,dsex);break;}
                                                case 5:{
                                                               printf("PLEASE ENTER NEW AGE\n");
                                                               scanf("%d",&dage);
                                                               updateage(did,dage);break;}
                                                case 6:{
                                                               printf("PLEASE ENTER NEW DEPARTMENT\n");
                                                               scanf("%s",ddept);
                                                               updatedept(did,ddept);break;}
                                                case 7:{
                                                               printf("PLEASE ENTER NEW SALARY\n");
                                                               scanf("%f",&dsalary);
                                                               updatesalary(did,dsalary);break;}
                                                case 8:{
                                                               printf("PLEASE ENTER NEW EMAIL\n");
                                                               scanf("%s",demail);
                                                               updateemail(did,demail);break;}
                                                case 9:{
                                                               printf("PLEASE ENTER NEW PHONE NUMBER\n");
                                                               scanf("%s",dphone);
                                                               updatephone(did,dphone);break;}}
                                        printf("RECORD UPDATED\n");
                                        printf("-----------------------------------------------------------------------------------\n");break;}
case 6:{
                                        printf("*****************************************************************************************************************************************************************************\n");
                                        exit(0);}}}}

		else{
				printf("NO ACCOUNT FOUND\n");}}

	}
}


