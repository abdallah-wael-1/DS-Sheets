#include <stdio.h>
#include <string.h>
#include "employee_types.h"


void printEmployee(const Entry* emp) {
    printf("Employee Information:\n");
    printf("====================\n");
    printf("Name: %s\n", emp->name);
    printf("Date of Birth: %02d/%02d/%04d\n", 
           emp->date_of_birth.day, 
           emp->date_of_birth.month, 
           emp->date_of_birth.year);
    printf("Home Address: %s, %s, %s\n", 
           emp->home_address.street, 
           emp->home_address.city, 
           emp->home_address.zip_code);
    printf("Company: %s\n", emp->company.name);
    printf("Company Address: %s, %s, %s\n", 
           emp->company.address.street, 
           emp->company.address.city, 
           emp->company.address.zip_code);
    printf("Company Phone: %s\n", emp->company.phone_number);
    printf("\n");
}

int main() {
    Entry employee1;
    
    
    strcpy(employee1.name, "John Doe");
    
    
    employee1.date_of_birth.day = 15;
    employee1.date_of_birth.month = 6;
    employee1.date_of_birth.year = 1990;
    
    
    strcpy(employee1.home_address.street, "123 Main Street");
    strcpy(employee1.home_address.city, "New York");
    strcpy(employee1.home_address.zip_code, "10001");
    
   
    strcpy(employee1.company.name, "Tech Solutions Inc.");
    strcpy(employee1.company.address.street, "456 Business Ave");
    strcpy(employee1.company.address.city, "New York");
    strcpy(employee1.company.address.zip_code, "10002");
    strcpy(employee1.company.phone_number, "(555) 123-4567");
    
    
    printEmployee(&employee1);
    
 
    Entry employees[3];
    
   
    strcpy(employees[1].name, "Jane Smith");
    employees[1].date_of_birth.day = 22;
    employees[1].date_of_birth.month = 12;
    employees[1].date_of_birth.year = 1985;
    strcpy(employees[1].home_address.street, "789 Oak Lane");
    strcpy(employees[1].home_address.city, "Boston");
    strcpy(employees[1].home_address.zip_code, "02101");
    strcpy(employees[1].company.name, "Tech Solutions Inc.");
    strcpy(employees[1].company.address.street, "456 Business Ave");
    strcpy(employees[1].company.address.city, "New York");
    strcpy(employees[1].company.address.zip_code, "10002");
    strcpy(employees[1].company.phone_number, "(555) 123-4567");
    
    printf("Second Employee:\n");
    printEmployee(&employees[1]);
    
    return 0;
}
