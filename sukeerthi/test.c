#include<stdio.h>
#include<stdlib.h>
struct pharma {
        char name[20];
        int stock;
        int cost;
};
struct pharma* print_list_medicines(){
        FILE*print_med;
	struct pharma buf[100];
	int i=0;
        print_med=fopen("List_of_medicines","r");
        fseek(print_med,0,SEEK_SET);
        while(ftell(print_med)!=SEEK_END){
                fgets(buf[i],sizeof(struct pharma),print_med);
                printf("%s %d %d",buf[i]);
                fseek(print_med,0,SEEK_CUR);
		i++;
        }
}
int main(){
	print_list_medicines();
	return 0;
}


