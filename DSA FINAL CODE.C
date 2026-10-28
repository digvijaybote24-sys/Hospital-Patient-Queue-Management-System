#include <stdio.h>
#include <string.h>

#define MAX 10

struct Patient {
    char name[50];
    int age;
    int priority;
};

struct Patient patients[MAX];

int front = 0, rear = -1, count = 0;

// Add Patient
void addPatient() {
    if (count == MAX) {
        printf("Queue is full!\n");
        return;
    }

    rear = (rear + 1) % MAX;

    printf("Enter patient name: ");
    scanf(" %49[^\n]", patients[rear].name);

    printf("Enter patient age: ");
    scanf("%d", &patients[rear].age);

    printf("Enter priority (1-High, 2-Medium, 3-Low): ");
    scanf("%d", &patients[rear].priority);

    if (patients[rear].priority < 1 ||
        patients[rear].priority > 3) {
        printf("Invalid priority!\n");
        rear = (rear - 1 + MAX) % MAX;
        return;
    }

    count++;

    printf("Patient added successfully!\n");
}

// Display Patients
void displayPatients() {
    int i, index;

    if (count == 0) {
        printf("No patients in the queue.\n");
        return;
    }

    printf("\n--- Patient Queue ---\n");
    printf("Name\t\tAge\tPriority\n");

    for (i = 0; i < count; i++) {
        index = (front + i) % MAX;

        printf("%-15s %d\t%d\n",
               patients[index].name,
               patients[index].age,
               patients[index].priority);
    }
}

// Treat Patient
void treatPatient() {
    if (count == 0) {
        printf("No patients waiting.\n");
        return;
    }

    printf("Now treating: %s\n",
           patients[front].name);

    front = (front + 1) % MAX;
    count--;

    if (count == 0) {
        front = 0;
        rear = -1;
    }
}

// Sort Patients by Priority using Bubble Sort
void sortPatients() {
    int i, j, index1, index2;
    struct Patient temp;

    if (count == 0) {
        printf("No patients to sort.\n");
        return;
    }

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {

            index1 = (front + j) % MAX;
            index2 = (front + j + 1) % MAX;

            if (patients[index1].priority >
                patients[index2].priority) {

                temp = patients[index1];
                patients[index1] = patients[index2];
                patients[index2] = temp;
            }
        }
    }

    printf("Patients sorted by priority!\n");
}

// Main Function
int main() {
    int choice;

    do {
        printf("\n--- HOSPITAL PATIENT QUEUE ---\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Treat Patient\n");
        printf("4. Sort Patients by Priority\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                treatPatient();
                break;

            case 4:
                sortPatients();
                break;

            case 5:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}