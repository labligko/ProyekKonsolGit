#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char noplat[20];
    char jenis[20];
    int tahun;
}kendaraan;

void add();
void show();
void edit();
void del();

int main()
{
    int n;

    while(1)
    {
        printf("****** DATA KENDARAAN ******\n");
        printf("[1] Tambah Data Kendaraan\n");
        printf("[2] Lihat Data Kendaraan\n");
        printf("[3] Ubah Data Kendaraan\n");
        printf("[4] Hapus Data Kendaraan\n");
        printf("[5] Keluar Program\n");
        printf("Pilih Menu : "); scanf("%d", &n);

        switch (n)
        {
            case 1: add(); break;
            case 2: show(); break;
            case 3: edit(); break;
            case 4: del(); break;
            case 5: return 0;
        }
    }
}

void add()
{
    kendaraan aKendaran;
    FILE *f = fopen("kendaraan.dat","ab");
    printf("*** Tambah Data Kendaraan ***\n");
    printf("ID kendaraan\t: "); scanf("%d",&aKendaran.id);
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    while(aKendaran.id != 9999)
    {
        printf("Nomor Plat\t: ");fgets(aKendaran.noplat, sizeof(aKendaran.noplat), stdin);
        printf("Jenis Kendaraan\t: ");fgets(aKendaran.jenis, sizeof(aKendaran.jenis), stdin);
        printf("Tahun Produksi\t: ");scanf("%d", &aKendaran.tahun);

        while ((ch = getchar()) != '\n' && ch != EOF);

        aKendaran.noplat[strcspn(aKendaran.noplat, "\n")] = 0;
        aKendaran.jenis[strcspn(aKendaran.jenis, "\n")] = 0;
        fwrite(&aKendaran,sizeof(aKendaran),1,f);

        printf("ID kendaraan\t: "); scanf("%d",&aKendaran.id);
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    fclose(f);
}

void show()
{
    kendaraan aKendaran;
    FILE *f = fopen("kendaraan.dat","rb");

    printf("*** Lihat Data Kendaraan ***\n");
    while(fread(&aKendaran,sizeof(aKendaran),1,f))
    {
        printf("Id Kendaraan\t: %d \n",aKendaran.id);
        printf("Nomor Plat\t: %s \n",aKendaran.noplat);
        printf("Jenis Kendaraan\t: %s \n",aKendaran.jenis);
        printf("Tahun Produksi\t: %d \n",aKendaran.tahun);
        printf("\n");
    }
    fclose(f);
}

void edit()
{
    kendaraan aKendaran;
    int idTarget, found =0;
    char newNoplat[20];
    FILE *f = fopen("kendaraan.dat","rb");
    FILE *f2 = fopen("tempkendaraan.dat","wb");
    printf("*** Ubah Data Kendaraan ***\n");
    printf("ID kendaraan\t: ");scanf("%d", &idTarget);
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    while (fread(&aKendaran,sizeof(aKendaran),1,f))
    {
        if(aKendaran.id == idTarget)
        {
            printf("Masukan nomor plat baru : ");
            fgets(newNoplat, sizeof(newNoplat), stdin);
            newNoplat[strcspn(newNoplat, "\n")] = 0;
            strcpy(aKendaran.noplat, newNoplat);
            printf("Data Kendaraan berhasil diperbarui!\n");
            found = 1;
        }
        fwrite(&aKendaran,sizeof(aKendaran),1, f2);
    }
    fclose(f);
    fclose(f2);

    if (!found)
    {
        printf("Data Kendaraan dengan ID %d tidak ditemukan!\n", idTarget);
        remove("tempkendaraan.dat");
    }
    else
    {
        remove("kendaraan.dat");
        rename("tempkendaraan.dat", "kendaraan.dat");
    }
}

void del()
{
    kendaraan aKendaran;
    int idTarget, found=0;
    FILE *f = fopen("kendaraan.dat","rb");
    FILE *f2 = fopen("tempkendaraan.dat","wb");

    if (!f || !f2)
    {
        printf("File gagal dibuka.\n");
    }

    printf("*** Hapus Data Kendaraan ***\n");
    printf("ID kendaraan\t: ");scanf("%d",&idTarget);

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    while(fread(&aKendaran,sizeof(aKendaran),1,f))
    {
        if(aKendaran.id == idTarget)
        {
            found = 1;
            continue;
        }
        fwrite(&aKendaran,sizeof(aKendaran),1,f2);
    }
    fclose(f);
    fclose(f2);

    if (found)
    {
        printf("Data berhasil dihapus!\n");
    }
    else
    {
        printf("Data tidak ditemukan!\n");
    }

    remove("kendaraan.dat");
    rename("tempkendaraan.dat", "kendaraan.dat");
}