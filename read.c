#include <stdio.h>
typedef struct
{
    int id;
    char name[25];
    float grade;
}studentData;

#define MAX_STUDENTS 100

void countGraduation(FILE *stdFile, int *nOver2);
void printGradu();
void copyArr();
void printArr();
void expcsv();

studentData studentArr[MAX_STUDENTS];
int co;

main()
{
    FILE *studentFile;
    int numberOfGraduates;

    countGraduation(studentFile, &numberOfGraduates);
    printf("Number of Graduates is %d\n", numberOfGraduates);
    printf("The Graduates: \n");
    printGradu();
    printf("Student list: \n");
    printArr();
    expcsv();
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

void copyArr()
{
    studentData studentRec;
    FILE *stdFile;
    int i;
    stdFile = fopen("student.dat","rb");
    while(fread(&studentRec, sizeof(studentRec), 1, stdFile) == 1)
    {
        if (co < MAX_STUDENTS)
        {
            studentArr[co] = studentRec;
            co++;
        }
        else
        {
            printf("Array penuh,\n");
        }
    }
    fclose(stdFile);
}

void printArr()
{
    int i;
    copyArr();
    for (i = 0; i < co; i++)
    {
        printf("student-%d : \n", i+1);
        printf("\tID : %d\n", studentArr[i].id);
        printf("\tNama : %s\n", studentArr[i].name);
        printf("\tGrade : %.2f\n", studentArr[i].grade);
    }
}

void expcsv()
{
    int i;
    FILE *stdFile;
    stdFile = fopen("student.csv","w");
    fprintf(stdFile, "ID, Nama, Grade\n");
    for (i = 0; i < co; i++)
    {
        fprintf(stdFile, "%d,%s,%.2f\n", studentArr[i].id, studentArr[i].name, studentArr[i].grade);
    }
    if (stdFile != NULL)
    {
        printf("Berhasil export to .csv\n");
    }
    fclose(stdFile);
}