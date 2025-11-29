#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Task 3

typedef enum
{
    IT = 0,
    HR,
    Finance,
    Marketing,
    Operations

} Department;

typedef enum
{
    Intern = 0,
    Junior,
    Senior,
    Manager,
    Director
} Designation;

typedef struct
{
    int ID;
    char Name[50];
    Department Department;
    Designation Designation;
    int Salary;
    char JoinDate[10];
    int phone;
    char email[50];
    float experience;
} Employee;

Employee *Employees;

void PopulateDatasheet(int NumberOfEmployees);

void PrintDepartment(int choice);

void PrintDesignation(int choice);

void CalculateExperience(int Index);

void Display_Deparment_Salaries(int max);

void SearchEmployee(int max);

void Display_Promotion_Candidates(int max);

int main()
{

    int NumberOfEmployees, Command;
    char End;

    printf("NOTE: All dates are in format DD/MM/YYYY\n\n");

    printf("Enter number of employees: ");
    scanf(" %d", &NumberOfEmployees);

    PopulateDatasheet(NumberOfEmployees);

    while (true)
    {
        printf("\n\nActions:\n\n");
        printf("1. Display Department-Wise Salary Statistics.\n");
        printf("2. Search Employee.\n");
        printf("3. Display Employees Eligible for Promotion.\n\n");
        printf("Command: ");
        scanf(" %d", &Command);

        printf("\n\n");

        switch (Command)
        {

        case 1:
            Display_Deparment_Salaries(NumberOfEmployees);
            break;

        case 2:
            SearchEmployee(NumberOfEmployees);
            break;

        case 3:
            Display_Promotion_Candidates(NumberOfEmployees);
            break;
        }
        printf("\n\nContinue? Y/N: ");
        scanf(" %c", &End);

        if (End != 'Y' && End != 'y')
        {
            return 0;
        }
    }
}

void PopulateDatasheet(int NumberOfEmployees)
{

    Employees = (Employee *)malloc(sizeof(Employee) * NumberOfEmployees);
    char ch;

    for (int i = 0; i < NumberOfEmployees; i++)
    {

        printf("\nEnter Employee %d's ID: ", i + 1);
        scanf(" %d", &Employees[i].ID);

        printf("Enter Employee %d's name: ", i + 1);
        while ((ch = getchar()) == '\n' && !EOF)
            ;
        gets(Employees[i].Name);

        printf("\n0 for IT.\n1 for HR\n2 for Finance\n3 for Marketing\n4 for operations)\nEnter Employee %d's Department: ", i + 1);
        scanf(" %d", &Employees[i].Department);

        printf("\n0 for intern.\n1 for junior.\n2 for Senior.\n3 for manager.\n4 for director.\nEnter Employee %d's Designation: ", i + 1);
        scanf(" %d", &Employees[i].Designation);

        printf("Enter Employee %d's Salary: ", i + 1);
        scanf(" %d", &Employees[i].Salary);

        printf("Enter Employee %d's date of joining: ", i + 1);
        while ((ch = getchar()) == '\n' && !EOF)
            ;
        gets(Employees[i].JoinDate);

        CalculateExperience(i);

        printf("Enter Employee %d's phone number: ", i + 1);
        scanf(" %d", &Employees[i].phone);

        printf("Enter Employee %d's email: ", i + 1);
        while ((ch = getchar()) == '\n' && !EOF)
            ;
        gets(Employees[i].email);
    }
}

void CalculateExperience(int Index)
{
    float Day, Month, Year; // DD/MM/YYYY

    Day = ((Employees[Index].JoinDate[0] - '0') * 10) + (Employees[Index].JoinDate[1] - '0');

    Month = ((Employees[Index].JoinDate[3] - '0') * 10) + (Employees[Index].JoinDate[4] - '0');

    Year = ((Employees[Index].JoinDate[6] - '0') * 1000) +
           ((Employees[Index].JoinDate[7] - '0') * 100) +
           ((Employees[Index].JoinDate[8] - '0') * 10) +
           (Employees[Index].JoinDate[9] - '0');

    Employees[Index].experience = (Day / 365.0f) + (Month / 12.0f) + Year;
}

void Display_Deparment_Salaries(int max)
{
    int IT = 0, HR = 0, Finance = 0, Marketing = 0, Operations = 0; // Salary count;

    int Department;

    for (int i = 0; i < max; i++)
    {

        Department = Employees[i].Department;

        if (Department == 0)
        {
            IT += Employees[i].Salary;
        }
        if (Department == 1)
        {
            HR += Employees[i].Salary;
        }
        if (Department == 2)
        {
            Finance += Employees[i].Salary;
        }
        if (Department == 3)
        {
            Marketing += Employees[i].Salary;
        }
        if (Department == 4)
        {
            Operations += Employees[i].Salary;
        }
    }

    printf("Salary:\n\n");
    printf("IT = %d\n", IT);
    printf("HR = %d\n", HR);
    printf("Finance = %d\n", Finance);
    printf("Marketing = %d\n", Marketing);
    printf("Operations = %d\n", Operations);
}

void SearchEmployee(int max)
{
    int command;
    printf("Enter search filter (1 = Department, 2 = Designation, 3 = Experience): ");
    scanf(" %d", &command);

    switch (command)
    {

    case 1:
        printf("Which department (0 = IT, 1 = HR, 2 = Finance, 3 = Marketing, 4 = Operations): ");
        scanf(" %d", &command);

        for (int i = 0; i < max; i++)
        {

            if (command == Employees[i].Department)
            {
                printf("Employee ID: %d\n", Employees[i].ID);
                printf("Employee name: %s\n", Employees[i].Name);
                printf("Employee Designation: ");
                PrintDesignation(command);
                printf("Employee phone: %d\n", Employees[i].phone);
                printf("Employee email: %s", Employees[i].email);
            }
        }

        break;

    case 2:
        printf("Enter Designation (0 = Intern, 1 = Junior, 2 = Senior, 3 = Manager, 4 = Director)");
        scanf(" %d", &command);
        for (int i = 0; i < max; i++)
        {

            if (command == Employees[i].Designation)
            {
                printf("Employee ID: %d\n", Employees[i].ID);
                printf("Employee name: %s\n", Employees[i].Name);
                printf("Employee Department: ");
                PrintDepartment(command);
                printf("Employee phone: %d\n", Employees[i].phone);
                printf("Employee email: %s", Employees[i].email);
            }
        }

        break;

    case 3:
        printf("Enter Minimum experience: ");
        scanf(" %d", &command);

        for (int i = 0; i < max; i++)
        {

            if (command <= Employees[i].experience)
            {
                printf("Employee ID: %d\n", Employees[i].ID);
                printf("Employee name: %s\n", Employees[i].Name);
                printf("Employee Department: ");
                PrintDepartment(command);
                printf("\nEmployee Designation: ");
                PrintDesignation(command);
                printf("\nEmployee phone: %d\n", Employees[i].phone);
                printf("Employee email: %s", Employees[i].email);
            }
        }

        break;
    }
}

void Display_Promotion_Candidates(int max)
{
    printf("\n\nEligible for Promotion:\n\n");
    for (int i = 0; i < max; i++)
    {

        if (Employees[i].experience > 3)
        {
            printf("Employee ID: %d\n", Employees[i].ID);
            printf("Employee name: %s\n", Employees[i].Name);
            printf("Employee Department: ");
            PrintDepartment(Employees[i].Department);
            printf("\nEmployee Designation: ");
            PrintDesignation(Employees[i].Designation);
            printf("\nEmployee phone: %d\n", Employees[i].phone);
            printf("Employee email: %s", Employees[i].email);
        }
    }
}

void PrintDepartment(int choice)
{

    switch (choice)
    {
    case 0:
        printf("IT");
        break;

    case 1:
        printf("HR");
        break;

    case 2:
        printf("Finance");
        break;

    case 3:
        printf("Marketing");
        break;

    case 4:
        printf("Operations");
        break;
    }
}

void PrintDesignation(int choice)
{

    switch (choice)
    {
    case 0:
        printf("Intern");
        break;

    case 1:
        printf("Junior");
        break;

    case 2:
        printf("Senior");
        break;

    case 3:
        printf("Manager");
        break;

    case 4:
        printf("Director");
        break;
    }
}