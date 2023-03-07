//Structure for an appointment
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


