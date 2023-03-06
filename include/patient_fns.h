typedef struct patient{
	char name[30]; 
	char phone_no[15];
	int age;
	char gender[2];
	char e_contact_name[30];
	char e_contact_phone[15];
	char history_file[35]; //name of file which contains history of patient's illness
	char presc_file[20]; //name of file with list of precription files
} patient;

void add_patient();
patient *read_patient(int *no_of_rec);
int check_patient(char p[30]);
patient read_specific_patient(patient *c,int no_of_rec, char name[30]);
