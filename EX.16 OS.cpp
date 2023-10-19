#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee {
    int empId;
    char name[50];
    float salary;
};
void addEmployee(FILE *file, struct Employee emp) {
    fseek(file, 0, SEEK_END); 
    fwrite(&emp, sizeof(struct Employee), 1, file);
}
void displayEmployee(FILE *file, int empId) {
    struct Employee emp;
    fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);
    printf("Employee ID: %d\nName: %s\nSalary: %.2f\n", emp.empId, emp.name, emp.salary);
}
int main() {
    FILE *employeeFile = fopen("employee.dat", "r+");
    if (employeeFile == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }
    int choice, empId;
    struct Employee emp;
    do {
        printf("1. Add Employee\n2. Display Employee\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &emp.empId);
                printf("Enter Name: ");
                scanf("%s", emp.name);
                printf("Enter Salary: ");
                scanf("%f", &emp.salary);
                addEmployee(employeeFile, emp);
                break;
            case 2:
                printf("Enter Employee ID: ");
                scanf("%d", &empId);
                displayEmployee(employeeFile, empId);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    fclose(employeeFile); 
    return 0;
}