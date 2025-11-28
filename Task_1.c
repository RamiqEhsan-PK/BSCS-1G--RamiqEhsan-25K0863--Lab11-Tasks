#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct{

char Name[100];
int Rollno;

//Marks
float English;
float Maths;
float Physics;

float Average;
float Percentage;

} Student;

Student *Record;

void InputData(int NumberofStudents);
float CalculateAverage(int NumberofStudents);
float CalculatePercentage();



int main(){

int NumberofStudents;
float Sum=0, Average;
char Command;

printf("Enter how many students to add: ");
scanf(" %d", &NumberofStudents);

Record= (Student*)malloc(sizeof(Student) * NumberofStudents);

if(Record==NULL){
    printf("Allocation Error.");
    return 0;
}

InputData(NumberofStudents);
float TotalAverage = CalculateAverage(NumberofStudents);
CalculatePercentage();

printf("\n\nActions:\n\n");
printf("1. Search Student by name.\n");
printf("2. Search Student by Roll number.\n");
printf("3. Find Students by Grade.\n");
printf("4. Display students by average.");

scanf(" %d", &Command);

switch(Command){
    case 1: 
}

free(Record);
return 0;
}


void InputData(int NumberofStudents){

for(int i=0; i<NumberofStudents;i++){
    printf("Enter student %d name: ", i+1);
    fgets(Record[i].Name, sizeof(Record[i].Name), stdin);

    printf("Enter student %d Rollno: ", i+1);
    scanf(" %d", Record[i].Rollno);

    printf("Enter Student %d English marks: ", i+1);
    scanf(" %d", Record[i].English);

    printf("Enter Student %d Physics marks: ", i+1);
    scanf(" %d", Record[i].Physics);

    printf("Enter Student %d Maths marks: ", i+1);
    scanf(" %d", Record[i].Maths);
}

}

float CalculateAverage(int NumberofStudents){
float sum=0,TotalAverage;

for(int i=0; i<NumberofStudents; i++){
    sum+=Record[i].Maths+Record[i].English+Record[i].Physics;
}

TotalAverage= sum / (float)(NumberofStudents);

return TotalAverage;
}

void CalculatePercentage(){



}