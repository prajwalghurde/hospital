#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int patientID;
    char name[50];
    int age;
    char gender;
    char contact[20];
    char medicalHistory[200];
    struct Patient* next;
};

struct Patient* createPatient(int id, const char* name, int age, char gender, const char* contact, const char* medicalHistory) {
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    if (newPatient != NULL) {
        newPatient->patientID = id;
        strcpy(newPatient->name, name);
        newPatient->age = age;
        newPatient->gender = gender;
        strcpy(newPatient->contact, contact);
        strcpy(newPatient->medicalHistory, medicalHistory);
        newPatient->next = NULL;
    }
    return newPatient;
}


void addPatient(struct Patient** head, int idCounter) {
    char name[50], contact[20], medicalHistory[200];
    int age;
    char gender;

    printf("Enter patient details:\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", &age);
    printf("Gender (M/F): ");
    scanf(" %c", &gender);
    printf("Contact: ");
    scanf("%s", contact);
    printf("Medical History: ");
    scanf("%s", medicalHistory);

    struct Patient* newPatient = createPatient(idCounter, name, age, gender, contact, medicalHistory);
    if (newPatient != NULL) {
        idCounter++;
        if (*head == NULL) {
            *head = newPatient;
        } else {
            struct Patient* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newPatient;
        }
        printf("Patient added successfully.\n");
    } else {
        printf("Failed to add patient.\n");
    }
}

void displayPatients(struct Patient* head) {
    struct Patient* temp = head;
    while (temp != NULL) {
        printf("Patient ID: %d\n", temp->patientID);
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Gender: %c\n", temp->gender);
        printf("Contact: %s\n", temp->contact);
        printf("Medical History: %s\n", temp->medicalHistory);
        printf("--------------------------------------\n");
        temp = temp->next;
    }
}

struct Patient* searchPatient(struct Patient* head, int id) {
    struct Patient* temp = head;
    while (temp != NULL) {
        if (temp->patientID == id) {
            return temp; // Found the patient
        }
        temp = temp->next;
    }
    return NULL; // Patient not found
}

void updatePatientInfo(struct Patient* patient) {
    char name[50], contact[20], medicalHistory[200];
    int age;
    char gender;

    printf("Enter updated patient details:\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", &age);
    printf("Gender (M/F): ");
    scanf(" %c", &gender);
    printf("Contact: ");
    scanf("%s", contact);
    printf("Medical History: ");
    scanf("%s", medicalHistory);

    strcpy(patient->name, name);
    patient->age = age;
    patient->gender = gender;
    strcpy(patient->contact, contact);
    strcpy(patient->medicalHistory, medicalHistory);

    printf("Patient information updated successfully.\n");
}

void deletePatient(struct Patient** head, int id) {
    struct Patient* temp = *head;
    struct Patient* prev = NULL;

    while (temp != NULL && temp->patientID != id) {
        prev = temp;
        temp = temp->next;
    }

    // If the patient is found
    if (temp != NULL) {
        if (prev == NULL) {
            *head = temp->next; // If the patient is the head
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printf("Patient with ID %d deleted successfully.\n", id);
    } else {
        printf("Patient with ID %d not found.\n", id);
    }
}

void freeList(struct Patient* head) {
    struct Patient* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Patient* patientList = NULL;
    int idCounter = 1;
    int choice, searchID, updateID, deleteID;

    do {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient Information\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(&patientList, idCounter);
                idCounter++;
                break;
            case 2:
                displayPatients(patientList);
                break;
            case 3:
                printf("Enter Patient ID to search: ");
                scanf("%d", &searchID);
                struct Patient* foundPatient = searchPatient(patientList, searchID);
                if (foundPatient != NULL) {
                    printf("Details of Patient with ID %d:\n", searchID);
                    printf("Name: %s\n", foundPatient->name);
                    printf("Age: %d\n", foundPatient->age);
                    printf("Gender: %c\n", foundPatient->gender);
                    printf("Contact: %s\n", foundPatient->contact);
                    printf("Medical History: %s\n", foundPatient->medicalHistory);
                    printf("--------------------------------------\n");
                } else {
                    printf("Patient with ID %d not found.\n", searchID);
                }
                break;
            case 4:
                printf("Enter Patient ID to update: ");
                scanf("%d", &updateID);
                struct Patient* patientToUpdate = searchPatient(patientList, updateID);
                if (patientToUpdate != NULL) {
                    updatePatientInfo(patientToUpdate);
                } else {
                    printf("Patient with ID %d not found.\n", updateID);
                }
                break;
            case 5:
                printf("Enter Patient ID to delete: ");
                scanf("%d", &deleteID);
                deletePatient(&patientList, deleteID);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);
    freeList(patientList);

    return 0;
}