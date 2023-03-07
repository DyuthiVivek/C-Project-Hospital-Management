#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<patient_fns.h>
void admit(char name[31]){
	int n,o;
	char pname[31];
	FILE* beds=fopen("beds","r+");
	int k=check_patient(name);//cheking if patient is there
	printf("%ld",ftell(beds));//third column ->name of patient
	if (k==0){                //second digit ->occupancy status
		return;}          //first digit ->bed num
	else{   
		while(fscanf(beds,"%d %d ",&n,&o)!=EOF){
			if(o==0){  
			fseek(beds,5,SEEK_CUR);//changing occupancy status
			fwrite("1",1,1,beds);
			fseek(beds,7,SEEK_CUR);//writing the name
			fwrite(name,strlen(name),1,beds);
			break;}}}
	printf("%ld",ftell(beds));		
	fclose(beds);
}

void discharge(char name[31]){
	int n,o;
	char pname[31];
	FILE* beds=fopen("beds","r+");
	int k=check_patient(name);
	if (k==0){
		return;}
	else{
		while(fscanf(beds,"%d %d",&n,&o)!=EOF){
			fgets(name,31,beds);
			if (strcmp(name,pname)==0){
			fseek(beds,5,SEEK_CUR);
			fwrite("0",1,1,beds);
			fseek(beds,7,SEEK_CUR);
			fwrite("0",1,strlen(name),beds);
			break;}}}
	fclose(beds);
}

void ot_admit(char name[31]){
	int n,o;
	char pname[31];
	FILE* ot=fopen("ot","r+");
	int k=check_patient(name);
	if (k==0){
		return;}
	else{
		while(fscanf(ot,"%d %d",&n,&o)!=EOF){
			if(o==0){
				fseek(ot,5,SEEK_CUR);
				fwrite("1",1,1,ot);
				fseek(ot,7,SEEK_CUR);
				fwrite(name,strlen(name),1,ot);
				break;}}}
	fclose(ot);
}
void ot_discharge(char name[31]){
	int n,o;
	char pname[31];
	FILE* ot=fopen("ot","r+");
	int k=check_patient(name);
	if (k==0){
		return;}
	else{
	while(fscanf(ot,"%d %d ",&n,&o)!=EOF){
			fgets(name,31,ot);
			if (strcmp(name,pname)==0){
				fseek(ot,5,SEEK_CUR);
				fwrite("0",1,1,ot);
				fseek(ot,7,SEEK_CUR);
				fwrite("0",1,strlen(name),ot);
				break;}}}
	fclose(ot);
}

int main(){
	char name[31];
	scanf("%s",name);
	admit(name);
	ot_admit(name);
}
