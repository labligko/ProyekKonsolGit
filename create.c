#include <stdio.h>
typedef struct
{
    int id;
    char name[25];
    float grade;
}student;

void main()
{
    student aStudent;
    FILE *studentFile;

    studentFile = fopen("student.dat","wb");
    printf("Input student ID = "); scanf("%d",&aStudent.id);
    while (aStudent.id != 9999)
    {
        printf("Input student name = "); scanf("%s",&aStudent.name);
        printf("Input student grade = "); scanf("%f                  ",&aStudent.grade);
        fwrite(&aStudent,sizeof(aStudent),1,studentFile);

        printf("Input student ID = "); scanf("%d",&aStudent.id);
    }
    fclose(studentFile);
}