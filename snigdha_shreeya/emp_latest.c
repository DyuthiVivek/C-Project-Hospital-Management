#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"employeenew.h"
#include"doc_admin_login.h"
/*
struct employee{
	int id;
	char name[30];
	char dob[8];
	int age;
	char sex;
	char dept[20];
	float salary;
	char email[35];
	char phone[10];
	struct employee * link;
};
*/

void deletey(int did,char name[],char dob[],int age,char sex, char dept[],float sal,char email[],char phone[]);
void retrievesalary(int dsalary);
void updatedept(int did,char dadept[]);
void updatedob(int did,char dadob[]);
void updatename(int did,char daname[]);
void updatesex(int dbs,int das);
void updateage(int dbage,int daage);
void updateid(int dbid,int daid);
void retrieveage(int dage);
void retrievesex(int dsex);
void retrievephone(char dphone[]);
void retrievedob(char ddob[]);
void updatesalary(int did,int dasa);
void updateemail(int did,char daemail[]);
void retrievedept(char ddept[]);
void retrieveemail(char demail[]);
void retrievename(char dname[]);
void retrieveid(int did);
void print();
void updatephone(int did,char dap[]);
//void deletebyname(int did);
void insertemployee();
void deletex(int did);
void insertemployee(){
	FILE *fp;
	struct employee  temp;
	struct employee * temp2;
	char buf[1000];
	fp=fopen("employee.bin","ab+");
	if (!fp){
		printf("UNABLE TO OPEN FILE");}
	else{
	printf("ENTER ID\n");
	scanf("%d",&temp.id);
	getchar();
	printf("ENTER NAME\n");
	scanf("%s",temp.name);
	getchar();
	printf("ENTER DOB\n");
	scanf("%s",temp.dob);
	getchar();
	printf("ENTER AGE\n");
	scanf("%d",&temp.age);
	getchar();
	printf("ENTER SEX\n");
	scanf("%c",&temp.sex);
	getchar();
	printf("ENTER DEPARTMENT\n");
	scanf("%s",temp.dept);
	getchar();
	printf("ENTER SALARY\n");
	scanf("%f",&temp.salary);
	getchar();
	printf("ENTER EMAIL\n");
	scanf("%s",temp.email);
	getchar();
	printf("ENTER PHONE\n");
	scanf("%s",temp.phone);
	getchar();
	fwrite(&temp,sizeof(struct employee),1,fp);
	fclose(fp);}}

void print(){
	struct employee  temp;
	int c=0;
	FILE *fp=fopen("employee.bin","rb");
	if (fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			c++;
                        printf("\t%d\t\t\t%s\t\t\t%s\t\t%d\t\t%c\t\t\t%s\t\t%.2f\t\t\t%s\t\t%s\n",temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);}
		fclose(fp);}
	if(c==0){
		printf("NO RECORDS IN DATABASE\n");}}

//retrieveid
void retrieveid(int did){
	struct employee temp;
	int c=0;
	FILE * fp=fopen("employee.bin","rb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.id==did){
				printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %s\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %s\n\n",temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);
				c++;}}
			fclose(fp);}
	if(c==0){
		printf("NO RECORD WITH GIVEN ID FOUND\n");}}

//retrievename
void retrievename(char dname[]){
	struct employee temp;
	int c=0;
	FILE * fp=fopen("employee.bin","rb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(strcmp(temp.name,dname)==0){
				printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %s\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %s\n\n",temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);
				c++;}}
			fclose(fp);}
	if(c==0){
		printf("NO RECORD WITH GIVEN NAME FOUND\n");}}

//retrieveemail
void retrieveemail(char demail[]){
	struct employee temp;
	int c=0;
	FILE * fp=fopen("employee.bin","rb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(strcmp(temp.email,demail)==0){
				printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %s\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %s\n\n",temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);
				c++;}}
			fclose(fp);}
	if(c==0){
		printf("NO RECORD WITH GIVEN EMAIL FOUND\n");}}
	
//retrievedept
void retrievedept(char ddept[]){
	struct employee temp;
	int c=0;
	FILE * fp=fopen("employee.bin","rb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(strcmp(temp.dept,ddept)==0){
				printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %s\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %s\n\n",temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);
				c++;}}
			fclose(fp);}
	if(c==0){
		printf("NO RECORD WITH GIVEN DEPARTMENT FOUND\n");}}

//retrievedob
void retrievedob(char ddob[]){
	struct employee temp;
	int c=0;
	FILE * fp=fopen("employee.bin","rb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(strcmp(temp.dob,ddob)==0){
				printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %s\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %s\n\n",temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);
				c++;}}
			fclose(fp);}
	if(c==0){
		printf("NO RECORD WITH GIVEN DATE OF BIRTH FOUND\n");}}

//retrievephone
void retrievephone(char dphone[]){
	struct employee temp;
	int c=0;
	FILE * fp=fopen("employee.bin","rb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(strcmp(temp.phone,dphone)==0){
				printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %s\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %s\n\n",temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);
				c++;}}
			fclose(fp);}
	if(c==0){
		printf("NO RECORD WITH GIVEN PHONE NUMBER FOUND\n");}}
//retrieveage
void retrieveage(int dage){
	struct employee temp;
	int c=0;
	FILE * fp=fopen("employee.bin","rb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.age==dage){
				printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %s\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %s\n\n",temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);
				c++;}}
			fclose(fp);}
	if(c==0){
		printf("NO RECORD WITH GIVEN AGE FOUND\n");}}

//retrievesex
void retrievesex(int dsex){
	struct employee temp;
	int c=0;
	FILE * fp=fopen("employee.bin","rb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.sex==dsex){
				printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %s\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %s\n\n",temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);
				c++;}}
			fclose(fp);}
	if(c==0){
		printf("NO RECORD WITH GIVEN SEX FOUND\n");}}

//retrievesalary
void retrievesalary(int dsalary){
	struct employee temp;
	int c=0;
	FILE * fp=fopen("employee.bin","rb");
	if(fp!=NULL){
		fseek(fp,0L, SEEK_END);
		long int r=ftell(fp);
		while(fread(&temp,sizeof(struct employee),r,fp)){
			if(temp.salary==dsalary){
				printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %s\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %s\n\n",temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);
				c++;}}
			fclose(fp);}
	if(c==0){
		printf("NO RECORD WITH GIVEN ID FOUND\n");}}

//updateid
void updateid(int dbid,int daid){
	struct employee temp;
	struct employee  temp2;
	int c=0;
	char oldname[]="employee.bin";
	char newname[]="employeex.bin";
	FILE * fp=fopen("employee.bin","rb+");
	FILE * fp2=fopen("employeex.bin","wb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.id==dbid){
				temp2.id=daid;
				temp2.age=temp.age;
				temp2.sex=temp.sex;
				temp2.salary=temp.salary;
				strcpy(temp2.name,temp.name);
				strcpy(temp2.dept,temp.dept);
				strcpy(temp2.dob,temp.dob);
				strcpy(temp2.email,temp.email);
				strcpy(temp2.phone,temp.phone);
				fwrite(&temp2,1,sizeof(temp2),fp);
				c++;}
			else{fwrite(&temp,1,sizeof(temp),fp2);}}
			fclose(fp);
	fclose(fp2);
	remove(oldname);
	rename(newname,oldname);
	system("PAUSE");
	return;}
	if(c==0){
		printf("NO RECORD FOUND");}}

//updateage
void updateage(int dbage,int daage){
	struct employee temp;
	struct employee  temp2;
	int c=0;
	char oldname[]="employee.bin";
	char newname[]="employeex.bin";
	FILE * fp=fopen("employee.bin","rb+");
	FILE * fp2=fopen("employeex.bin","wb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.age==dbage){
				temp2.age=daage;
				temp2.salary=temp.salary;
				temp2.id=temp.id;
				temp2.sex=temp.sex;
				strcpy(temp2.name,temp.name);
				strcpy(temp2.dept,temp.dept);
				strcpy(temp2.dob,temp.dob);
				strcpy(temp2.email,temp.email);
				strcpy(temp2.phone,temp.phone);
				fwrite(&temp2,1,sizeof(temp2),fp);
				c++;}
			else{fwrite(&temp,1,sizeof(temp),fp2);}}
			fclose(fp);
	fclose(fp2);
	remove(oldname);
	rename(newname,oldname);
	system("PAUSE");
	return;}
	if(c==0){
		printf("NO RECORD FOUND");}}

//updatesex
void updatesex(int dbs,int das){
	struct employee temp;
	struct employee  temp2;
	int c=0;
	char oldname[]="employee.bin";
	char newname[]="employeex.bin";
	FILE * fp=fopen("employee.bin","rb+");
	FILE * fp2=fopen("employeex.bin","wb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.sex==dbs){
				temp2.sex=das;
				temp2.age=temp.age;
				temp2.salary=temp.salary;
				temp2.id=temp.id;
				strcpy(temp2.name,temp.name);
				strcpy(temp2.dept,temp.dept);
				strcpy(temp2.dob,temp.dob);
				strcpy(temp2.email,temp.email);
				strcpy(temp2.phone,temp.phone);
				fwrite(&temp2,1,sizeof(temp2),fp);
				c++;}
			else{fwrite(&temp,1,sizeof(temp),fp2);}}
			fclose(fp);
	fclose(fp2);
	remove(oldname);
	rename(newname,oldname);
	system("PAUSE");
	return;}
	if(c==0){
		printf("NO RECORD FOUND");}}

//updatesalary
void updatesalary(int did,int dasa){
	struct employee temp;
	struct employee  temp2;
	int c=0;
	char oldname[]="employee.bin";
	char newname[]="employeex.bin";
	FILE * fp=fopen("employee.bin","rb+");
	FILE * fp2=fopen("employeex.bin","wb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.salary==did){
				temp2.salary=dasa;
				temp2.age=temp.age;
				temp2.id=temp.id;
				temp2.sex=temp.sex;
				strcpy(temp2.name,temp.name);
				strcpy(temp2.dept,temp.dept);
				strcpy(temp2.dob,temp.dob);
				strcpy(temp2.email,temp.email);
				strcpy(temp2.phone,temp.phone);
				fwrite(&temp2,1,sizeof(temp2),fp);
				c++;}
			else{fwrite(&temp,1,sizeof(temp),fp2);}}
			fclose(fp);
	fclose(fp2);
	remove(oldname);
	rename(newname,oldname);
	system("PAUSE");
	return;}
	if(c==0){
		printf("NO RECORD FOUND");}}

//updatename
void updatename(int did,char daname[]){
	struct employee temp;
	struct employee  temp2;
	int c=0;
	char oldname[]="employee.bin";
	char newname[]="employeex.bin";
	FILE * fp=fopen("employee.bin","rb+");
	FILE * fp2=fopen("employeex.bin","wb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.id==did){
				strcpy(temp2.name,daname);
				temp2.age=temp.age;
				temp2.salary=temp.salary;
				temp2.id=temp.id;
				temp2.sex=temp.sex;
				strcpy(temp2.dept,temp.dept);
				strcpy(temp2.dob,temp.dob);
				strcpy(temp2.email,temp.email);
				strcpy(temp2.phone,temp.phone);
				fwrite(&temp2,1,sizeof(temp2),fp);
				c++;}
			else{fwrite(&temp,1,sizeof(temp),fp2);}}
			fclose(fp);
	fclose(fp2);
	remove(oldname);
	rename(newname,oldname);
	system("PAUSE");
	return;}
	if(c==0){
		printf("NO RECORD FOUND");}}

//updatedob
void updatedob(int did,char dadob[]){
	struct employee temp;
	struct employee  temp2;
	int c=0;
	char oldname[]="employee.bin";
	char newname[]="employeex.bin";
	FILE * fp=fopen("employee.bin","rb+");
	FILE * fp2=fopen("employeex.bin","wb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.id==did){
				strcpy(temp2.dob,dadob);
				temp2.age=temp.age;
				temp2.id=temp.id;
				temp2.sex=temp.sex;
				strcpy(temp2.name,temp.name);
				strcpy(temp2.dept,temp.dept);
				temp2.salary=temp.salary;
				strcpy(temp2.email,temp.email);
				strcpy(temp2.phone,temp.phone);
				fwrite(&temp2,1,sizeof(temp2),fp);
				c++;}
			else{fwrite(&temp,1,sizeof(temp),fp2);}}
			fclose(fp);
	fclose(fp2);
	remove(oldname);
	rename(newname,oldname);
	system("PAUSE");
	return;}
	if(c==0){
		printf("NO RECORD FOUND");}}

//updatedept
void updatedept(int did,char dadept[]){
	struct employee temp;
	struct employee  temp2;
	int c=0;
	char oldname[]="employee.bin";
	char newname[]="employeex.bin";
	FILE * fp=fopen("employee.bin","rb+");
	FILE * fp2=fopen("employeex.bin","wb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.id==did){
				strcpy(temp2.dept,dadept);
				temp2.age=temp.age;
				temp2.id=temp.id;
				temp2.salary=temp.salary;
				temp2.sex=temp.sex;
				strcpy(temp2.name,temp.name);
				strcpy(temp2.dob,temp.dob);
				strcpy(temp2.email,temp.email);
				strcpy(temp2.phone,temp.phone);
				fwrite(&temp2,1,sizeof(temp2),fp);
				c++;}
			else{fwrite(&temp,1,sizeof(temp),fp2);}}
			fclose(fp);
	fclose(fp2);
	remove(oldname);
	rename(newname,oldname);
	system("PAUSE");
	return;}
	if(c==0){
		printf("NO RECORD FOUND");}}

//updateemail
void updateemail(int did,char daemail[]){
	struct employee temp;
	struct employee  temp2;
	int c=0;
	char oldname[]="employee.bin";
	char newname[]="employeex.bin";
	FILE * fp=fopen("employee.bin","rb+");
	FILE * fp2=fopen("employeex.bin","wb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.id==did){
				strcpy(temp2.email,daemail);
				temp2.age=temp.age;
				temp2.id=temp.id;
				temp2.salary=temp.salary;
				temp2.sex=temp.sex;
				strcpy(temp2.name,temp.name);
				strcpy(temp2.dept,temp.dept);
				strcpy(temp2.dob,temp.dob);
				strcpy(temp2.phone,temp.phone);
				deletey(temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);
				fwrite(&temp2,1,sizeof(temp2),fp);
				c++;}
			else{fwrite(&temp,1,sizeof(temp),fp2);}}
			fclose(fp);
	fclose(fp2);
	remove(oldname);
	rename(newname,oldname);
	system("PAUSE");
	return;}
	if(c==0){
		printf("NO RECORD FOUND");}}

//updatephone
void updatephone(int did,char dap[]){
	struct employee temp;
	struct employee  temp2;
	int c=0;
	char oldname[]="employee.bin";
	char newname[]="employeex.bin";
	FILE * fp=fopen("employee.bin","rb+");
	FILE * fp2=fopen("employeex.bin","wb");
	if(fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(temp.id==did){
				strcpy(temp2.phone,dap);
				temp2.age=temp.age;
				temp2.salary=temp.salary;
				temp2.id=temp.id;
				temp2.sex=temp.sex;
				strcpy(temp2.name,temp.name);
				strcpy(temp2.dept,temp.dept);
				strcpy(temp2.dob,temp.dob);
				strcpy(temp2.email,temp.email);
				//deletey(temp.id,temp.name,temp.dob,temp.age,temp.sex,temp.dept,temp.salary,temp.email,temp.phone);
				fwrite(&temp2,1,sizeof(temp2),fp2);
				c++;}
			else{fwrite(&temp,1,sizeof(temp),fp2);}}
			fclose(fp);
	fclose(fp2);
	remove(oldname);
	rename(newname,oldname);
	system("PAUSE");
	return;}
	if(c==0){
		printf("NO RECORD FOUND");}}

void deletebyname(int did){
	char name[30];
	char email[30];
	char dept[30];
	char phone[10];
	char dob[8];
	int age;
	char sex;
	float salary;
	printf("ENTER NAME\n");
	scanf("%s",name);
	printf("ENTER EMAIL\n");
	scanf("%s",email);
	printf("ENTER DEPARTMENT\n");
	scanf("%s",dept);
	printf("ENTER PHONE NUMBER\n");
	scanf("%s",phone);
	printf("ENTER DOB\n");
	scanf("%s",dob);
	printf("ENTER AGE\n");
	scanf("%d",&age);
	printf("ENTER SEX\n");
	scanf("%c",&sex);
	printf("ENTER SALARY\n");
	scanf("%f",&salary);
	struct employee temp;
	FILE * fp=fopen("employee.bin","rb+");
	if (fp!=NULL){
		while(fread(&temp,sizeof(struct employee),1,fp)){
			if(strcmp(temp.name,name)==0 && strcmp(temp.dept,dept)==0 && strcmp(temp.phone,phone)==0 && strcmp(temp.email,email)==0 && strcmp(temp.phone,phone)==0 && temp.age==age && temp.sex==sex && temp.id==did && temp.salary==salary){
				fseek(fp,-sizeof(struct employee),SEEK_CUR);
				fwrite(&temp,sizeof(struct employee),1,fp);
				fclose(fp);
				return;}}fclose(fp);}
	printf("NO RECORD FOUND\n");}

void deletex(int did){
	struct employee temp;
	char newname[]="employeex.bin";
	char oldname[]="employee.bin";
	int found=0;
	FILE * fp1=fopen("employee.bin","rb");
	FILE * fp2=fopen("employeex.bin","wb");
	/*if (fp!=NULL){while(fread(&temp,sizeof(struct employee),1,fp)){
                        if(strcmp(temp.name,temp2->name)==0 && strcmp(temp.dept,temp2->dept)==0 && strcmp(temp.phone,temp2->phone)==0 && strcmp(temp.email,temp2->email)==0 && strcmp(temp.phone,temp2->phone)==0 && temp.age==temp2->age && temp.sex==temp2->sex && temp.id==temp2->id && temp.salary==temp2->salary){
                                //if(temp.id==temp2->id){
				fseek(fp,-sizeof(struct employee),SEEK_CUR);
                                fwrite(&temp,sizeof(struct employee),1,fp);
                                fclose(fp);
                                return;}}fclose(fp);}}*/
	while(fread(&temp,sizeof(struct employee),1,fp1)){
		if(temp.id!=did){
			fwrite(&temp,sizeof(struct employee),1,fp2);}
		else{found=1;}}
	if(!found){
		printf("NO MATCH FOUND\n");}
	fclose(fp1);
	fclose(fp2);
	remove(oldname);
	rename(newname,oldname);
	system("PAUSE");
	return;}

void deletey(int did,char name[],char dob[],int age,char sex, char dept[],float sali,char email[],char phone[]){
	struct employee temp;
	char newname[]="employeex.bin";
	char oldname[]="employee.bin";
	int found=0;
	FILE * fp1=fopen("employee.bin","rb");
	FILE * fp2=fopen("employeex.bin","wb");
	while(fread(&temp,sizeof(struct employee),1,fp1)){
                        if(!(strcmp(temp.name,name)==0 && strcmp(temp.dept,dept)==0 && strcmp(temp.phone,phone)==0 && strcmp(temp.email,email)==0 && strcmp(temp.dob,dob)==0 && temp.age==age && temp.sex==sex && temp.id==did && temp.salary==sali)){
			fwrite(&temp,sizeof(struct employee),1,fp2);}
		else{found=1;}}
	if(!found){
		printf("NO MATCH FOUND\n");}
	fclose(fp1);
	fclose(fp2);
	remove(oldname);
	rename(newname,oldname);
	system("PAUSE");
	return;}



/*
int main(){
		int adid;
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
        	                         printf("-----------------------------------------------------------------------------------\n"); 
					 printf("\t\t\t\t\t\tEMPLOYEE DATABASE\n\n\n");
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
					deletex(did);
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
*/

