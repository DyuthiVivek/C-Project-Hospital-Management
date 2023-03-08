#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"employee.h"
//employee structure creation
struct employee{
	char name[30];
	int dob;
	int id;
	char sex;
	int age;
	char dept[20];
	float salary;
	char email[35];
	long int phone;
	struct employee* link;};

//insertemployee function definition
struct employee * insertemployee(struct employee * head,struct employee *ptr){
	struct employee * temp2;
	temp2=(struct employee *)malloc(sizeof(struct employee));
	if (head==NULL){
		return ptr;}
	temp2=head;
	if (head->link!=NULL){
		while(temp2->link!=NULL){
			temp2=temp2->link;}
		temp2->link=ptr;
		temp2=temp2->link;
		temp2=head;
		return temp2;}
	if (head->link==NULL){
		head->link=ptr;
		ptr->link=NULL;
		return head;}}

//print function definition
void print(struct employee *head){
	struct employee * temp;
	if (head==NULL){
		printf("NO RECORD PRESENT");
		return;}
	temp=head;
	if (head!=NULL){
		printf("\t\t\t\t\t\tEMPLOYEE DATABASE\n\n\n");
		printf("\tID\t\t\tNAME\t\t\tDOB\t\tAGE\t\tSEX\t\t\tDEPARTMENT\t\tSALARY\t\t\tEMAIL-ID\t\tPHONE NUMBER\t\t\n");
		printf("\n");
		while(temp->link!=NULL){
			printf("\t%d\t\t\t%s\t\t\t%d\t\t%d\t\t%c\t\t\t%s\t\t%.2f\t\t\t%s\t\t%ld\n",temp->id,temp->name,temp->dob,temp->age,temp->sex,temp->dept,temp->salary,temp->email,temp->phone);
			temp=temp->link;}
			printf("\t%d\t\t\t%s\t\t\t%d\t\t%d\t\t%c\t\t\t%s\t\t%.2f\t\t\t%s\t\t%ld\n",temp->id,temp->name,temp->dob,temp->age,temp->sex,temp->dept,temp->salary,temp->email,temp->phone);
		printf("\n\n");}}

//retrievename function definition- To retrieve records using input name
void retrievename(struct employee * head,char dname[30]){
	struct employee *p;
	p=head;
	int c=0;
	while(p!=NULL){
		if(strcmp(p->name,dname)==0){
			printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %d\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %ld\n\n",p->id,p->name,p->dob,p->age,p->sex,p->dept,p->salary,p->email,p->phone);
			c++;}
		p=p->link;}
	if (p==NULL && c==0){
		printf("\tNO RECORD FOUND\n");}
	if (p==NULL){return;}}
			
//retrieveid function definition- To retrieve records using input id
void retrieveid(struct employee * head,int did){
	struct employee *p;
	p=head;
	int c=0;
	while(p!=NULL){
		if(p->id==did){
			printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %d\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %ld\n\n",p->id,p->name,p->dob,p->age,p->sex,p->dept,p->salary,p->email,p->phone);
			c++;}
		p=p->link;}
	if (p==NULL && c==0){
		printf("\tNO RECORD FOUND\n");}
	if(p==NULL){return;}}

//retrieveage function definition- To retrieve records using input age (Filters all records based on input) 
void retrieveage(struct employee * head,int dage){
	struct employee *p;
	p=head;
	int c=0;
	while(p!=NULL){
		if(p->age==dage){
			printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %d\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %ld\n\n",p->id,p->name,p->dob,p->age,p->sex,p->dept,p->salary,p->email,p->phone);
			c++;}
		p=p->link;}
	if (p==NULL && c==0){
		printf("\tNO RECORD FOUND\n");}
	if (p==NULL){return;}}

struct employee * retrieveid1(struct employee * head,int dage){
	struct employee *p;
	struct employee * temp;
	p=head;
	int c=0;
	while(p!=NULL){
		if(p->age==dage){
			temp=p;
			return temp;
			break;
			c++;}
		p=p->link;}
	if (p==NULL && c==0){
		return NULL;}
	if (p==NULL){return c;}}

//retrievedob function definition - To retrieve records using input dob 
void retrievedob(struct employee * head,int ddob){
	struct employee *p;
	p=head;
	int c=0;
	while(p!=NULL){
		if(p->dob==ddob){
			printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %d\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %ld\n\n",p->id,p->name,p->dob,p->age,p->sex,p->dept,p->salary,p->email,p->phone);
			c++;}
		p=p->link;}
	if (p==NULL && c==0){
		printf("\tNO RECORD FOUND\n");}
	if (p==NULL){return;}}

//retrievesex function definition - To retrieve records using input sex
void retrievesex(struct employee * head,char dsex){
	struct employee *p;
	p=head;
	int c=0;
	while(p!=NULL){
		if(p->sex==dsex){
			printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %d\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %ld\n\n",p->id,p->name,p->dob,p->age,p->sex,p->dept,p->salary,p->email,p->phone);
			c++;}
		p=p->link;}
	if (p==NULL && c==0){
		printf("\tNO RECORD FOUND\n");}
	if(p==NULL){return;}}

//retrievedept function definition - To retrieve records using input department 
void retrievedept(struct employee * head,char ddept[30]){
	struct employee *p;
	p=head;
	int c=0;
	while(p!=NULL){
		if(strcmp(p->dept,ddept)==0){
			printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %d\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %ld\n\n",p->id,p->name,p->dob,p->age,p->sex,p->dept,p->salary,p->email,p->phone);
			c++;}
		p=p->link;}
	if (p==NULL && c==0){
		printf("\tNO RECORD FOUND\n");}
	if(p==NULL){return;}}

//retrieveemail function definition - To retrieve records using input email id
void retrieveemail(struct employee * head,char demail[30]){
	struct employee *p;
	p=head;
	int c=0;
	while(p!=NULL){
		if(strcmp(p->email,demail)==0){
			printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %d\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %ld\n\n",p->id,p->name,p->dob,p->age,p->sex,p->dept,p->salary,p->email,p->phone);
		c++;}
		p=p->link;}
	if (p==NULL && c==0){
		printf("\tNO RECORD FOUND\n");}
	if (p==NULL){return;}}

//retrievesalary function definition - To retrieve records using input salary 
void retrievesalary(struct employee* head,float dsalary){
	struct employee *p;
	p=head;
	int c=0;
	while(p!=NULL){
		if(p->salary==dsalary){
			printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %d\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %ld\n\n",p->id,p->name,p->dob,p->age,p->sex,p->dept,p->salary,p->email,p->phone);
		c=c+1;}
		p=p->link;}
	if (p==NULL && c==0){
		printf("\tNO RECORD FOUND\n");}
	if (p==NULL){return;}}

//retrievephone function definition - To retrieve records using input phone
void retrievephone(struct employee* head,long int dphone){
	struct employee *p;
	p=head;
	int count;
	while(p!=NULL){
		if(p->phone==dphone){
			printf("\n\tSTAFF ID: %d\n\tSTAFF NAME: %s\n\tDOB: %d\n\tAGE: %d\n\tSEX: %c\n\tDEPARTMENT: %s\n\tSALARY: %f\n\tEMAIL-ID: %s\n\tPHONE NUMBER: %ld\n\n",p->id,p->name,p->dob,p->age,p->sex,p->dept,p->salary,p->email,p->phone);
		count=count+1;}
		p=p->link;}
	if(p==NULL && count==0){
		printf("\tNO RECORD FOUND\n");}
	if (p==NULL){return ;}}

//deletebyname function definition - To delete record using name
struct employee * deletebyname(struct employee * head, char dname[30]){
	struct employee * temp1;
	struct employee * temp2;
	struct employee * temp3;
	struct employee * temp4;
	int c=0;
	if(head==NULL){
		printf("\tRECORD EMPTY\n");
		return head;}
	else if(strcmp(head->name,dname)==0){
		temp1=head;
		head=head->link;
		free(temp1);
		temp1->link=NULL;
		c++;
		return head;}
	else{
		temp2=head;
		while(strcmp(temp2->name,dname)!=0){
				temp3=temp2;
				temp2=temp2->link;}
				temp4=temp2->link;
				temp3->link=temp4;
				free(temp2);
				temp4=head;
				c++;
				return temp4;}
	if (c==0){return head;}}
	
//read function definition - To read user input record
struct employee * read(){
	struct employee * temp=(struct employee *)malloc(sizeof(struct employee));
	scanf("%d %s %d %d %c %s %f %s %ld",&(temp->id),temp->name,&(temp->dob),&(temp->age),&(temp->sex),temp->dept,&(temp->salary),temp->email,&(temp->phone));
	temp->link=NULL;
	return temp;}

//updatename function definition - To update record name field using id  
struct employee * updatename(struct employee * head,int did, char dnameaf[30]){
	struct employee * temp;
       if (head==NULL){
       		printf("RECORD EMPTY\n");return head;}
	else if(head->id==did){
	 	strcpy(head->name,dnameaf);
		return head;}
       else{
	       temp=head->link;
	       while(temp->id!=did){
		       temp=temp->link;}
	       strcpy(temp->name,dnameaf);
	       temp=head;
	       return temp;}}

//updateemail function definition - To update record email field using id
struct employee * updateemail(struct employee * head,int did, char demailaf[30]){
	struct employee * temp;
       if (head==NULL){
       		printf("RECORD EMPTY\n");return head;}
	else if(head->id==did){
	 	strcpy(head->email,demailaf);
		return head;}
       else{
	       temp=head->link;
	       while(temp->id!=did){
		       temp=temp->link;}
	       strcpy(temp->email,demailaf);
	       temp=head;
	       return temp;}}

//updatedept function definition - To update record department field using id
struct employee * updatedept(struct employee * head,int did, char ddeptaf[30]){
	struct employee * temp;
       if (head==NULL){
       		printf("RECORD EMPTY\n");return head;}
	else if(head->id==did){
	 	strcpy(head->dept,ddeptaf);
		return head;}
       else{
	       temp=head->link;
	       while(temp->id!=did){
		       temp=temp->link;}
	       strcpy(temp->dept,ddeptaf);
	       temp=head;
	       return temp;}}

//updatesex function definition - To update record sex field using id
struct employee * updatesex(struct employee * head,int did, char dsex){
	struct employee * temp;
       if (head==NULL){
       		printf("RECORD EMPTY\n");return head;}
	else if(head->id==did){
	 	head->sex=dsex;
		return head;}
       else{
	       temp=head->link;
	       while(temp->id!=did){
		       temp=temp->link;}
	       temp->sex=dsex;
	       temp=head;
	       return temp;}}

//updateid function definition - To update record id field using id
struct employee * updateid(struct employee * head,int did, int didaf){
	struct employee * temp;
       if (head==NULL){
       		printf("RECORD EMPTY\n");return head;}
	else if(head->id==did){
	 	head->id=didaf;
		return head;}
       else{
	       temp=head->link;
	       while(temp->id!=did){
		       temp=temp->link;}
	       temp->id=didaf;
	       temp=head;
	       return temp;}}

//updatedob function definition - To update record date of birth field using id
struct employee * updatedob(struct employee * head,int did, int dobaf){
	struct employee * temp;
       if (head==NULL){
       		printf("RECORD EMPTY\n");return head;}
	else if(head->id==did){
	 	head->dob=dobaf;
		return head;}
       else{
	       temp=head->link;
	       while(temp->id!=did){
		       temp=temp->link;}
	       temp->dob=dobaf;
	       temp=head;
	       return temp;}}

//updateage function definition - To update record age field using id
struct employee * updateage(struct employee * head,int did, int dageaf){
	struct employee * temp;
       if (head==NULL){
       		printf("RECORD EMPTY\n");return head;}
	else if(head->id==did){
	 	head->age=dageaf;
		return head;}
       else{
	       temp=head->link;
	       while(temp->id!=did){
		       temp=temp->link;}
	       temp->age=dageaf;
	       temp=head;
	       return temp;}}

//updatesalary function definition - To update record salary field using id
struct employee * updatesalary(struct employee* head,int did, float dsalaf){
	struct employee * temp;
       if (head==NULL){
       		printf("RECORD EMPTY\n");return head;}
	else if(head->id==did){
	 	head->salary=dsalaf;
		return head;}
       else{
	       temp=head->link;
	       while(temp->id!=did){
		       temp=temp->link;}
	       temp->salary=dsalaf;
	       temp=head;
	       return temp;}}

//updatephone function definition - To update record phone field using id
struct employee * updatephone(struct employee * head,int did, long int dphone){
	struct employee * temp;
       if (head==NULL){
       		printf("RECORD EMPTY\n");return head;}
	else if(head->id==did){
	 	head->phone=dphone;
		return head;}
       else{
	       temp=head->link;
	       while(temp->id!=did){
		       temp=temp->link;}
	       temp->phone=dphone;
	       temp=head;
	       return temp;}}
/*
//main function
int main(){
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
				printf("PLEASE ENTER  STAFF ID   STAFF NAME   DOB   AGE   SEX   DEPARTMENT   SALARY   EMAIL ID   PHONE NUMBER \n\n");
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
				       	exit(0);}}}}*/
