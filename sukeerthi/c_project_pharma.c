#include<stdio.h>
#include<stdlib.h>
struct pharma {
	char name[20];
	int stock;
	int cost;
};
struct pharma*read_medicines(){
	struct pharma a;
	scanf("%s %d %d",a.name,&a.stock,&a.cost);
	return &a;
}
struct pharma* add_medicines(struct pharma*a){
	FILE*add_med;
	add_med=fopen("List_of_medicines","w");
	fseek(add_med,0,SEEK_END);
	fprintf(add_med,"%s",a->name);	
	fprintf(add_med," ");
	fprintf(add_med,"%d",a->stock);	
	fprintf(add_med," ");
	fprintf(add_med,"%d",a->cost);	
	fprintf(add_med,"\n");
	fclose(add_med);

}
struct pharma* check_medicines(){
}
struct pharma* deduct_medicicne(){}
int main(){
	struct pharma *a;
	a=read_medicines();
	add_medicines(a);
	return 0;
}
