typedef struct patient{
	char name[30]; 
	char phone_no[12];
	int age;
	char gender[2];
	char e_contact_name[30];
	char e_contact_phone[12];
	char history_file[34]; //name of file which contains history of patient's illness
	char presc_file[20]; //name of file with list of precription files
} patient;
void add_patient();
patient *read_patient(int *no_of_rec);
