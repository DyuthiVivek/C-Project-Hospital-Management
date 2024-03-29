#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an appointment
typedef struct {
    char phone_number[20];
    char doctor_name[50];
    char date[20];
    char time[20];
} Appointment;


// Function prototypes
void write_to_file(Appointment appointment);
void book_appointment(char phone_number[]);
void reschedule_appointment(char phone_number[]);
void cancel_appointment(char phone_number[]);
void list_appointments_for_patient(char phone_number[]);
void list_appointments_for_doc(char doctor_name[]);


// Function to display the appointment menu
void apptmenu(char phone_number[]) {
    int choice;
    
    do {
        // Display the appointment menu
        printf("\nAppointment Menu\n");
        printf("1. Book Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Reschedule Appointment\n");
        printf("4. Cancel Appointment\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                book_appointment(phone_number);
                break;
            case 2:
                list_appointments_for_patient(phone_number);
                break;
            case 3:
                reschedule_appointment(phone_number);
                break;
            case 4:
                cancel_appointment(phone_number);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
}


// Function to write an appointment to the binary file 
void write_to_file(Appointment appointment) {
    FILE *file = fopen("appointments.dat", "ab");
    if (file != NULL) {
        fwrite(&appointment, sizeof(Appointment), 1, file);
    }
    fclose(file);
}


// Function to book a new appointment
void book_appointment(char phone_number[]) {
    Appointment appointment;
    
    // Get the appointment details from the user
    printf("\nEnter the doctor's name: ");
    scanf(" %[^\n]s", appointment.doctor_name);
    printf("Enter the appointment date (dd/mm/yyyy): ");
    scanf("%s", appointment.date);
    char *a[]={"11:00AM-11:30AM","11:30AM-12:00PM","12:00PM-12:30PM","12:30PM-1:00PM","1:00PM-1:30PM","1:30PM-2:00PM","2:00PM-2:30PM","2:30PM-3:00PM","3:00PM-3:30PM","3:30PM-4:00PM"};
    printf("Enter one of these slots for your appointment when prompted.\n");
    for (int i=0;i<10;i++)
	    printf("%s\n", a[i]);
    printf("Enter your preferred appointment time slot: ");
    scanf("%s", appointment.time);
    int flag=0;
    for (int i=0;i<10;i++) {
	    if (strcmp(appointment.time,a[i])==0) {
		    flag=1;
		    break;
	    }
    }
    if (!flag) {
	    printf("You entered an invalid time slot.\n");
    } 
    
    else {
    // Check if there is already an appointment with the same doctor, date and time
    FILE *file = fopen("appointments.dat", "rb");
    if (file != NULL) {
        while (fread(&appointment, sizeof(Appointment), 1, file)) {
            if (strcmp(appointment.doctor_name, appointment.doctor_name) == 0 &&
                strcmp(appointment.date, appointment.date) == 0 &&
                strcmp(appointment.time, appointment.time) == 0) {
                printf("\nThere is already an appointment with this doctor, date and time.\n");
                fclose(file);
                return;
            }
        }
        fclose(file);
    }
    
    // Save the appointment to file
    strcpy(appointment.phone_number, phone_number);
    write_to_file(appointment);
    
    printf("\nAppointment booked successfully.\n");
    }
}


// Function to reschedule an existing appointment
void reschedule_appointment(char phone_number[]) {
    char doctor_name[50];
    char new_date[20];
    char new_time[20];
    
    // Get the doctor name and new appointment details from the user
    printf("\nEnter the doctor's name of the appointment to reschedule: ");
    scanf(" %[^\n]s", doctor_name);
    printf("Enter the new appointment date (dd/mm/yyyy): ");
    scanf("%s", new_date);
char *a[]={"11:00AM-11:30AM","11:30AM-12:00PM","12:00PM-12:30PM","12:30PM-1:00PM","1:00PM-1:30PM","1:30PM-2:00PM","2:00PM-2:30PM","2:30PM-3:00PM","3:00PM-3:30PM","3:30PM-4:00PM"};
    printf("Enter one of these slots for your appointment when prompted.\n");
    for (int i=0;i<10;i++)
	    printf("%s\n", a[i]);
    printf("Enter the new appointment time slot: ");
    scanf("%s", new_time);
    int flag=0;
    for (int i=0;i<10;i++) {
	    if (strcmp(new_time,a[i])==0) {
		    flag=1;
		    break;
	    }
    }
    if (!flag) {
	    printf("You entered an invalid time slot.\n");
    } 
    
    else {
    
    // Check if there is an existing appointment with the same doctor, date and time
    Appointment appointment;
    FILE *file = fopen("appointments.dat", "rb+");
    if (file != NULL) {
        while (fread(&appointment, sizeof(Appointment), 1, file)) {
            if (strcmp(appointment.phone_number, phone_number) == 0 &&
                strcmp(appointment.doctor_name, doctor_name) == 0 &&
                strcmp(appointment.date, new_date) == 0 &&
                strcmp(appointment.time, new_time) == 0) {
                printf("\nThere is already an appointment with this doctor, date and time.\n");
                fclose(file);
                return;
            }
        }
        rewind(file);
        while (fread(&appointment, sizeof(Appointment), 1, file)) {
            if (strcmp(appointment.phone_number, phone_number) == 0 &&
                strcmp(appointment.doctor_name, doctor_name) == 0) {
                strcpy(appointment.date, new_date);
                strcpy(appointment.time, new_time);
                fseek(file, -sizeof(Appointment), SEEK_CUR);
                fwrite(&appointment, sizeof(Appointment), 1, file);
                printf("\nAppointment rescheduled successfully.\n");
                fclose(file);
                return;
            }
        }
        fclose(file);
    }
    
    printf("\nNo appointment found with the given doctor name.\n");
}
}


// Function to cancel an existing appointment
void cancel_appointment(char phone_number[]) {
    char doctor_name[50];
    char date[20];
    char time[20];
    
    // Get the appointment details from the user
    printf("\nEnter the doctor's name of the appointment to cancel: ");
    scanf(" %[^\n]s", doctor_name);
    printf("Enter the appointment date (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter the appointment time: ");
    scanf("%s", time);
    
    // Delete the appointment from the file
    Appointment appointment;
    FILE *file = fopen("appointments.dat", "rb+");
    if (file != NULL) {
        while (fread(&appointment, sizeof(Appointment), 1, file)) {
            if (strcmp(appointment.phone_number, phone_number) == 0 &&
                strcmp(appointment.doctor_name, doctor_name) == 0 &&
                strcmp(appointment.date, date) == 0 &&
                strcmp(appointment.time, time) == 0) {
                fseek(file, -sizeof(Appointment), SEEK_CUR);
                fwrite(&appointment, sizeof(Appointment), 1, file);
                printf("\nAppointment cancelled successfully.\n");
                fclose(file);
                return;
            }
        }
        fclose(file);
    }
    
    printf("\nNo appointment found with the given details.\n");
}


// Function to read all appointments from the file and print them for a patient
void list_appointments_for_patient(char phone_number[]) {
  
    // Read all appointments from the file and print them for the given doctor
    Appointment appointment;
    int count = 0;
    FILE *file = fopen("appointments.dat", "rb");
    if (file != NULL) {
        while (fread(&appointment, sizeof(Appointment), 1, file)) {
            if (strcmp(appointment.phone_number, phone_number) == 0) {
                count++;
                printf("%d. %s on %s with %s\n", count, appointment.time, appointment.date, appointment.doctor_name);
            }
        }
        fclose(file);
    }
    if (count == 0) {
        printf("No appointments found for the given doctor.\n");
    }
}

// Function to read all appointments from the file and print them for a doctor
void list_appointments_for_doc(char doctor_name[]) {
  
    // Read all appointments from the file and print them for the given doctor
    printf("\nAppointments for %s:\n", doctor_name);
    Appointment appointment;
    int count = 0;
    FILE *file = fopen("appointments.dat", "rb");
    if (file != NULL) {
        while (fread(&appointment, sizeof(Appointment), 1, file)) {
            if (strcmp(appointment.doctor_name, doctor_name) == 0) {
                count++;
                printf("%d. %s on %s\n", count, appointment.time, appointment.date);
            }
        }
        fclose(file);
    }
    if (count == 0) {
        printf("No appointments found for the given doctor.\n");
    }
}
