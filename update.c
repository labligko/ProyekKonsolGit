#include <stdio.h>

typedef struct
{
    int id;
    char name[25];
    float grade;
} studentData;

void updateData(const char *sourceFilename, int idTarget);

int main()
{
    int idTarget;
    printf("\nMasukan ID mahasiswa yang ingin diupdate: ");
    scanf("%d", &idTarget);
    updateData("student.dat", idTarget);
    return 0;
}

void updateData(const char *sourceFilename, int idTarget)
{
    FILE *sourceFile, *tempFile;
    studentData studentRec;
    int found = 0;
    float newGrade;

    sourceFile = fopen(sourceFilename, "rb");
    tempFile = fopen("temp.dat", "wb");

    if (!sourceFile || !tempFile)
    {
        printf("File tidak dapat dibuka!\n");
        return;
    }

    while (fread(&studentRec, sizeof(studentData), 1, sourceFile))
    {
        if (studentRec.id == idTarget)
        {
            found = 1;
            printf("Data ditemukan:\n");
            printf(" ID: %d\n Name: %s\n Nilai: %.2f\n", studentRec.id, studentRec.name, studentRec.grade);

            printf("Masukan nilai baru: ");
            scanf("%f", &newGrade);

            studentRec.grade = newGrade;
        }
        fwrite(&studentRec, sizeof(studentData), 1, tempFile);
    }

    fclose(sourceFile);
    fclose(tempFile);

    if (!found)
    {
        printf("Mahasiswa dengan ID %d tidak ditemukan!\n", idTarget);
        remove("temp.dat");
        return;
    }

    sourceFile = fopen(sourceFilename, "wb");
    tempFile = fopen("temp.dat", "rb");

    if (!sourceFile || !tempFile)
    {
        printf("Error saat membuka ulang file.\n");
        return;
    }

    while (fread(&studentRec, sizeof(studentData), 1, tempFile))
    {
        fwrite(&studentRec, sizeof(studentData), 1, sourceFile);
    }

    fclose(sourceFile);
    fclose(tempFile);
    remove("temp.dat");

    printf("Data berhasil diperbarui.\n");
}
