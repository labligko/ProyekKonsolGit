#include <stdio.h>
typedef struct
{
    int id;
    char name[25];
    float grade;
}student;

void show();
void avg();

void main()
{
    student aStudent;
    FILE *studentFile;

    studentFile = fopen("student.dat","wb");
    printf("Input student ID = "); scanf("%d",&aStudent.id);
    while (aStudent.id != 9999)
    {
        printf("Input student name = "); scanf("%s",&aStudent.name);
        printf("Input student grade = "); scanf("%f",&aStudent.grade);
        fwrite(&aStudent,sizeof(aStudent),1,studentFile);

        printf("Input student ID = "); scanf("%d",&aStudent.id);
    }
    fclose(studentFile);
    show();
    avg();
}

void show()
{
    student aStudent;
    FILE *studentFile;
    studentFile = fopen("student.dat","rb");

    printf("-- Lihat Data Mahasiswa --\n");
    while (fread(&aStudent,sizeof(aStudent),1,studentFile) == 1)
    {
        printf("ID = %d\n", aStudent.id);
        printf("Name = %s\n", aStudent.name);
        printf("Grade = %.2f\n", aStudent.grade);
        printf("\n");
    }
    fclose(studentFile);
}

void avg()
{
    student aStudent;
    FILE *studentFile;
    float average = 0;
    int count = 0;
    studentFile = fopen("student.dat","rb");
    printf("-- Hitung Rata-rata Grade Mahasiswa --\n");

    while (fread(&aStudent,sizeof(aStudent),1,studentFile) == 1)
    {
        average += aStudent.grade;
        count++;
    }
    average /= count;
    printf("Rata-rata Grade %d Mahasiswa adalah : %.2f\n",count, average);
    fclose(studentFile);
}