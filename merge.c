#include <stdio.h>
typedef struct
{
    int id;
    char name[25];
    float grade;
}studentData;

void mergeArchive(FILE *studentFile1, FILE *studentFile2, FILE *studentFile3);

main ()
{
    FILE *studentFile1, *studentFile2, *studentFile3;

    studentFile1 = fopen("student.dat", "rb");
    studentFile2 = fopen("student2.dat", "rb");
    studentFile3 = fopen("student3.dat", "wb");

    if (studentFile1 == NULL || studentFile2 == NULL || studentFile3 == NULL)
    {
        printf("File Not Found");
    }

    mergeArchive(studentFile1, studentFile2, studentFile3);
    printf("Penggabungan selesai. \n");

    fclose(studentFile1);fclose(studentFile2);fclose(studentFile3);
}

void mergeArchive(FILE *studentFile1, FILE *studentFile2, FILE *studentFile3)
{
    studentData studentRec;

    while (fread(&studentRec, sizeof(studentData), 1, studentFile1) == 1)
    {
        fwrite(&studentRec, sizeof(studentData), 1, studentFile3);
    }

    while (fread(&studentRec, sizeof(studentData), 1, studentFile2) == 1)
    {
        fwrite(&studentRec, sizeof(studentData), 1, studentFile3);
    }
}
