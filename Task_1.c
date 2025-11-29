#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//TASK 1

typedef struct
{

    char Name[100];
    int Rollno;

    // Marks
    float English;
    float Maths;
    float Physics;

    // Aptitude
    float Average;
    float Percentage;
    char Grade[3];

} Student;

Student *Record;

float TotalAverage;

void InputData(int NumberofStudents);
void Calculate(int NumberofStudents);
void SearchName(int NumberofStudents);
void SearchRollno(int NumberofStudents);
void SearchGrade(int NumberofStudents);
void DisplayByAverage(int NumberofStudents);
void DisplayRankings(int NumberofStudents);

int main()
{

    int NumberofStudents, Command;
    float Sum = 0;
    char Continue;

    printf("Enter how many students to add: ");
    scanf(" %d", &NumberofStudents);

    Record = (Student *)malloc(sizeof(Student) * NumberofStudents);

    if (Record == NULL)
    {
        printf("Allocation Error.");
        return 0;
    }

    InputData(NumberofStudents);
    Calculate(NumberofStudents);

    while (true)
    {

        printf("\n\nActions:\n\n");
        printf("1. Search Student by name.\n");
        printf("2. Search Student by Roll number.\n");
        printf("3. Find Students by Grade.\n");
        printf("4. Display students by average.\n");
        printf("5. Display student rankings.\n");
        printf("\nCommand: ");

        scanf(" %d", &Command);

        printf("\n\n");

        switch (Command)
        {
        case 1:
            SearchName(NumberofStudents);
            break;

        case 2:
            SearchRollno(NumberofStudents);
            break;

        case 3:
            SearchGrade(NumberofStudents);
            break;

        case 4:
            DisplayByAverage(NumberofStudents);
            break;

        case 5:
            DisplayRankings(NumberofStudents);
            break;
        }

        printf("\n\nContinue? Y/N: ");
        scanf(" %c", &Continue);

        if (Continue != 'y' && Continue != 'Y')
        {
            break;
        }
    }

    free(Record);
    return 0;
}

void InputData(int NumberofStudents)
{
    char ch;
    while ((ch = getchar()) == '\n' && !EOF)
        ;

    for (int i = 0; i < NumberofStudents; i++)
    {
        printf("Enter student %d name: ", i + 1);

        fgets(Record[i].Name, sizeof(Record[i].Name), stdin);

        Record[i].Name[strcspn(Record[i].Name, "\n")] = '\0';

        printf("Enter student %d Rollno: ", i + 1);
        scanf(" %d", &Record[i].Rollno);

        while (true)
        {
            printf("Enter Student %d English marks: ", i + 1);
            scanf(" %f", &Record[i].English);

            if (Record[i].English > 0 && Record[i].English <= 100)
            {
                break;
            }
            else
            {
                printf("Invalid input. Marks must be between 0-100\n");
            }
        }

        while (true)
        {
            printf("Enter Student %d Physics marks: ", i + 1);
            scanf(" %f", &Record[i].Physics);

            if (Record[i].Physics > 0 && Record[i].Physics <= 100)
            {
                break;
            }
            else
            {
                printf("Invalid input. Marks must be between 0-100\n");
            }
        }

        while (true)
        {
            printf("Enter Student %d Maths marks: ", i + 1);
            scanf(" %f", &Record[i].Maths);

            if (Record[i].Maths > 0 && Record[i].Maths <= 100)
            {
                break;
            }
            else
            {
                printf("Invalid input. Marks must be between 0-100\n");
            }
        }
        printf("\n");
        while ((ch = getchar()) == '\n' && !EOF)
            ;
    }
}

void Calculate(int NumberofStudents)

{

    float TotalSum = 0, tempSum;

    for (int i = 0; i < NumberofStudents; i++)
    {

        tempSum = Record[i].English + Record[i].Maths + Record[i].Physics;
        Record[i].Average = tempSum / 3.0;
        Record[i].Percentage = (tempSum / 300) * 100;
        TotalSum += tempSum;

        if (Record[i].Average >= 90)
        {
            strcpy(Record[i].Grade, "A+");
        }
        else if (Record[i].Average >= 80)
        {
            strcpy(Record[i].Grade, "A");
        }
        else if (Record[i].Average >= 70)
        {
            strcpy(Record[i].Grade, "B+");
        }
        else if (Record[i].Average >= 60)
        {
            strcpy(Record[i].Grade, "B");
        }
        else if (Record[i].Average >= 50)
        {
            strcpy(Record[i].Grade, "C");
        }
        else if (Record[i].Average < 50)
        {
            strcpy(Record[i].Grade, "F");
        }
    }

    TotalAverage = TotalSum / 3.0;
}

void SearchName(int NumberofStudents)
{
    char ch;
    char Name[50];
    printf("Enter Name: ");
    while ((ch = getchar()) != '\n' && !EOF)
        ;
    fgets(Name, sizeof(Name), stdin);
    Name[strcspn(Name, "\n")] = '\0';

    for (int i = 0; i < NumberofStudents; i++)
    {

        if (strcmp(Record[i].Name, Name) == 0)
        {
            printf("Name: %s\n", Record[i].Name);
            printf("Rollno: %d\n", Record[i].Rollno);
            printf("Grade: %s\n", Record[i].Grade);
        }
    }
}

void SearchRollno(int NumberofStudents)
{
    int Rollno;
    printf("Enter Roll no: ");
    scanf(" %d", &Rollno);

    for (int i = 0; i < NumberofStudents; i++)
    {

        if (Record[i].Rollno == Rollno)
        {
            printf("Name: %s\n", Record[i].Name);
            printf("Rollno: %d\n", Record[i].Rollno);
            printf("Grade: %s\n", Record[i].Grade);
        }
    }
}

void SearchGrade(int NumberofStudents)
{
    char Grade[3], ch;
    printf("Enter Grade: ");
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    fgets(Grade, sizeof(Grade), stdin);
    Grade[strcspn(Grade, "\n")] = '\0';

    for (int i = 0; i < NumberofStudents; i++)
    {

        if (strcmp(Record[i].Grade, Grade) == 0)
        {
            printf("Name: %s\n", Record[i].Name);
            printf("Rollno: %d\n", Record[i].Rollno);
            printf("Grade: %s\n", Record[i].Grade);
        }
    }
}

void DisplayByAverage(int NumberofStudents)
{
    printf("Above Average: \n\n");

    for (int i = 0; i < NumberofStudents; i++)
    {

        if (Record[i].Average > TotalAverage)
        {
            printf("Name: %s\n", Record[i].Name);
            printf("Rollno: %d\n", Record[i].Rollno);
            printf("Grade: %s\n", Record[i].Grade);
        }
    }

    printf("\nAverage: \n\n");

    for (int i = 0; i < NumberofStudents; i++)
    {

        if (Record[i].Average == TotalAverage)
        {
            printf("Name: %s\n", Record[i].Name);
            printf("Rollno: %d\n", Record[i].Rollno);
            printf("Grade: %s\n", Record[i].Grade);
        }
    }

    printf("\nBelow Average: \n\n");

    for (int i = 0; i < NumberofStudents; i++)
    {

        if (Record[i].Average < TotalAverage)
        {
            printf("Name: %s\n", Record[i].Name);
            printf("Rollno: %d\n", Record[i].Rollno);
            printf("Grade: %s\n", Record[i].Grade);
        }
    }
}

void DisplayRankings(int NumberofStudents)
{
    bool swap = true;
    float temp;
    int boundary = NumberofStudents;

    float *Ranking = (float *)malloc(sizeof(float) * NumberofStudents);

    if (Ranking == NULL)
    {
        printf("Error displaying ranking.\n");
        return;
    }

    for (int i = 0; i < NumberofStudents; i++)
    {
        Ranking[i] = Record[i].Percentage;
    }

    while (swap)

        swap = false;
    for (int i = 0; i < NumberofStudents; i++)
    {
        for (int j = 0; j < boundary; j++)
        {

            if (Ranking[i] > Ranking[j])
            {

                temp = Ranking[i];
                Ranking[i] = Ranking[j];
                Ranking[j] = temp;

                swap = true;
                boundary--;
            }
        }
    }

    printf("\n\nRankings: \n\n");
    for (int i = 0; i < NumberofStudents; i++)
    {
        printf("Ranking %d: %.2f\n", i + 1, Ranking[i]);
    }
    free(Ranking);
}
