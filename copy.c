#include <stdio.h>
typedef struct
{
    int id;
    char name[25];
    float grade;
}studentData;

void copyArchive(FILE *studentFile1, FILE *studentFile2);

main()
{
    FILE *studentFile, *studentFile2;

    copyArchive(studentFile, studentFile2);
    printf("\n Files have been copied.");
}

void copyArchive(FILE *studentFile1, FILE *studentFile2)
{
    studentData studentRec;

    studentFile1 = fopen("student.dat", "rb");
    studentFile2 = fopen("student2.dat", "wb");
    while (fread(&studentRec, sizeof(studentData), 1, studentFile1) == 1)
    {
        fwrite(&studentRec, sizeof(studentRec), 1, studentFile2);
    }
    fclose(studentFile1);fclose(studentFile2);
}