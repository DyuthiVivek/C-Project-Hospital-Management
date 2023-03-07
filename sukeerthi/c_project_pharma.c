#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pharma_fns.h>
/*
struct pharma* deduct_medicicne(struct pharma a,int new_stock);
int check_medicines(char med[20]);
struct pharma add_medicines(struct pharma a);
int read_medicines();
struct pharma add_stock(struct pharma a,int new_stock,char name[20]);
struct pharma {
	char name[20];
	int stock;
	int cost;
};
*/
int read_medicines(){
	struct pharma a;
	printf("Enter name of the medicine\n");
	scanf("%s",a.name);
	if(check_medicines(a.name)==0){
		printf("Enter the number of units of the medicine\n");
		scanf("%d",&a.stock);
		printf("Enter the cost of each units\n");
		scanf("%d",&a.cost);
		add_medicines(a);
		return 1;
	}
	int new_stock;
	if(check_medicines(a.name)==1){	
		printf("Enter the number of units of the medicine\n");
		scanf("%d",&new_stock);
		add_stock(a,new_stock,a.name);
		return 0;
	}			
}
struct pharma add_medicines(struct pharma a){
	FILE*add_med;
	int int1,int2;
	char buff[100];
	add_med=fopen("List_of_medicines","r+");
	fseek(add_med,0,SEEK_END);
	fprintf(add_med,"%s %d %d\n",a.name,a.stock,a.cost);
	fclose(add_med);
	return a;
}
struct pharma add_stock(struct pharma a,int new_stock,char name[20]){
	int initial_stock;
	int points;
	int final_stock;
	char buff[100];
	char result[10];
	char c;
	FILE*addstock;
	addstock=fopen("List_of_medicines","r+");
	fseek(addstock,0,SEEK_SET);
	while(fscanf(addstock,"%s",buff)==1){
		if(strcmp(buff,name)==0){
			points=ftell(addstock)+1;
			fscanf(addstock,"%d",&initial_stock);
			final_stock=initial_stock+new_stock;
			sprintf(result,"%d",final_stock);
			fseek(addstock,points,SEEK_SET);
			fwrite(result,sizeof(final_stock)-1,1,addstock);
			break;
		}
		}	
	fclose(addstock);
	return a;
}
int check_medicines(char med[20]){
	FILE*check_med;
	int int1,int2;
	char buff[100];
	check_med=fopen("List_of_medicines","r");
	fseek(check_med,0,SEEK_SET);
	while(fscanf(check_med,"%s %d %d",buff,&int1,&int2)==3){
		if(strcmp(buff,med)==0){
			if(int1>0){
	      		        return 1;  //Stock is available
			}
			if(int1==0){
				return 2; //stock is unavailable
			}
		}
}
	return 0;//Medicine is unavailable in hospital pharma
}
struct pharma* deduct_medicicne(struct pharma a,int new_stock){}
/*
int main(){
	char med[20];
	read_medicines();
	scanf("%s",med);
	check_medicines(med);
	return 0;
}
*/
