#include <stdio.h>
typedef struct
{
    int id;
    char name[25];
    float grade;
}studentData;

void countGraduation(FILE *stdFile, int *nOver2);
void printGradu();

main()
{
    FILE *studentFile;
    int numberOfGraduates;

    countGraduation(studentFile, &numberOfGraduates);
    printf("Number of Graduates is %d\n", numberOfGraduates);
    printGradu();
}

void countGraduation(FILE *stdfile, int *nOver2)
{
    studentData studentRec;

    *nOver2 = 0;
    stdfile = fopen("student.dat","rb");
    while(fread(&studentRec, sizeof(studentRec), 1, stdfile) == 1)
    {
        if (studentRec.grade > 2.0)
        {
            (*nOver2)++;
        }
    }
    fclose(stdfile);
}

void printGradu()
{
    studentData studentRec;
    FILE *stdFile;
    stdFile = fopen("student.dat","rb");
    while(fread(&studentRec, sizeof(studentRec), 1, stdFile) == 1)
    {
        if (studentRec.grade > 2.0)
        {
            printf("ID: %d\n", studentRec.id);
            printf("Nama: %s\n", studentRec.name);
            printf("grade: %.2f\n\n",studentRec.grade);
        }
    }

}
