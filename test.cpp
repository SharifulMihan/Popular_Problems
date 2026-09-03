#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

struct Employee *employees = NULL; 
int totalEmployees = 0;

void inputEmployees(int startIdx, int totalCount) {
    
    for (int i = startIdx; i < totalCount; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name); 
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    float highestSalary = 0;
    int idx = 0;
    
    printf("\n--- Current Employees ---\n");
    printf("ID      Name        Salary\n");
    
    for (int i = 0; i < totalCount; i++) {
        printf("%d      %s      %f\n", employees[i].id, employees[i].name, employees[i].salary);
        if (employees[i].salary > highestSalary) {
            highestSalary = employees[i].salary;
            idx = i;
        }
    }
    printf("\nHighest paid: %s (ID: %d, Salary: %f)\n\n", employees[idx].name, employees[idx].id, employees[idx].salary);
}

int main() {
    int n;
    printf("Enter initial number of employees: ");
    scanf("%d", &n);

    employees = (struct Employee*)calloc(n , sizeof(struct Employee));
    totalEmployees = n;

    inputEmployees(0, totalEmployees);

    int flag = 1;
    while (flag) {
        printf("Do you want to add more employees? (1 for yes, 0 for no): ");
        scanf("%d", &flag);
        
        if (flag == 1) {
            int newNumberOfEmployee;
            printf("How many new employees? ");
            scanf("%d", &newNumberOfEmployee);
            
            employees = (struct Employee*)realloc(employees, (totalEmployees + newNumberOfEmployee) * sizeof(struct Employee));
            
            int previousTotal = totalEmployees;
            totalEmployees += newNumberOfEmployee;
            
            inputEmployees(previousTotal, totalEmployees);
        }
        else break;
    }
    
    free(employees);
    printf("Memory freed. Goodbye!\n");
    
    return 0;
}