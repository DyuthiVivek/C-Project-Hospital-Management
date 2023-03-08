#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pharma_fns.h>
#include <presc_fns.h>
void pharmacist_login(){
	int a,k,st,b;
	char name[20];
	while(1){
		printf("1.read medicines\n");
		printf("2.check medicines\n");
		printf("3.add stock\n");
		printf("4.deduct medicines\n\n");
		char ch[2];
		fgets(ch,2,stdin);
		getchar();
		int a = atoi(ch);
		if(a==1){
			read_medicines();
		}
		else if(a==2){
			printf("Enter the name of the medicine");
			scanf("%s",name);
			k=check_medicines(name);
			if(k==1){
				printf("Medicine is available in hospital and in stock\n");
			}
			if(k==2){
				printf("Medicine is available in hospital but out of stock\n");
			}
			if(k==0){
				printf("Medicine is unavailable in hospital\n");
			}
		}
		else if(a==3){
			printf("Enter the name and stock of the medicine");
			scanf("%s %d",name,&st);
			add_stock(st,name);
		}
		else if(a==4){
			printf("Enter the name of the medicine");
			scanf("%s",name);
			deduct_medicine(name);
		}
		else{
			printf("Invalid input");
		}
	}
}
			

