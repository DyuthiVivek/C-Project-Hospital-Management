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
	if (k==0){
		printf("No such patient exists");//second digit ->occupancy status
		return;}          //first digit ->bed num
	else{   
		for(int j=0; j<15; j++)
		{
			fscanf(beds,"%d %d",&n,&o);
			if(o==0){  
			fseek(beds,-1,SEEK_CUR);
			fwrite("1",1,1,beds);
			fseek(beds,2,SEEK_CUR);//writing the name
			fwrite(name,strlen(name),1,beds);
			fseek(beds,7,SEEK_CUR);//writing the name
			break;
			}
			else
			{
				fseek(beds,4,SEEK_CUR);//writing the name
			}
		}
	}
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
		for(int j=0;j<15;j++){
			fscanf(beds,"%d %d",&n,&o);
			if(o==1){
				fgets(pname,31,beds);
				if (strcmp(name,pname)==0){
				fseek(beds,-1,SEEK_CUR);
				fwrite("0",1,1,beds);
				fseek(beds,2,SEEK_CUR);
				fwrite("00000",strlen(name),strlen(name),beds);
			//	fseek(beds,7,SEEK_CUR);
			break;
				}}
			else{
				fseek(beds,4,SEEK_CUR);
			}
			fclose(beds);
		}}}

void ot_admit(char name[31]){
	int n,o;
	char pname[31];
	FILE* ot=fopen("ot","r+");
	int k=check_patient(name);
	if (k==0){
		return;}
	else{
		for(int j=0;j<5;j++){
			fscanf(ot,"%d %d",&n,&o);
			if(o==0){
				fseek(ot,-1,SEEK_CUR);
				fwrite("1",1,1,ot);
				fseek(ot,2,SEEK_CUR);
				fwrite(name,strlen(name),1,ot);
				fseek(ot,7,SEEK_CUR);
				break;}
			else{
				fseek(ot,4,SEEK_CUR);
			}

		}}
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
	for(int j;j=0;j<5){
			fscanf(ot,"%d %d",&n,&o);
                        if(o==1){
                                fgets(pname,31,ot);
                                if (strcmp(name,pname)==0){
                                fseek(ot,-1,SEEK_CUR);
                                fwrite("0",1,1,ot);
                                fseek(ot,2,SEEK_CUR);
                                fwrite("0",1,strlen(name),ot);
                                fseek(ot,7,SEEK_CUR);
                        break;
                                }
                        else{
                                fseek(ot,4,SEEK_CUR);
                        }}
        fclose(ot);
	}}}

