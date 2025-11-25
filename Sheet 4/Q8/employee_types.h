#ifndef EMPLOYEE_TYPES_H
#define EMPLOYEE_TYPES_H


typedef struct {
    int day;
    int month;
    int year;
} Date;


typedef struct {
    char street[100];
    char city[50];
    char zip_code[20];
} Address;


typedef struct {
    char name[100];
    Address address;
    char phone_number[20];
} Company;


typedef struct {
    char name[100];
    Address home_address;
    Date date_of_birth;
    Company company;
} Entry;

#endif 
