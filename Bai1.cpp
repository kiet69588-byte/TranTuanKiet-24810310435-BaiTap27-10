
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct MonHoc
{
    char maMH[20];
    char tenMH[50];
    int soTinChi;
    int soTiet;
};

void Nhap(MonHoc *ds, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap mon hoc thu %d:\n", i + 1);

        printf("Ma mon hoc: ");
        scanf(" %[^\n]", ds[i].maMH);

        printf("Ten mon hoc: ");
        scanf(" %[^\n]", ds[i].tenMH);

        printf("So tin chi: ");
        scanf("%d", &ds[i].soTinChi);

        printf("So tiet da giang day: ");
        scanf("%d", &ds[i].soTiet);
    }
}

void Xuat(MonHoc *ds, int n)
{
    printf("\n%-15s %-30s %-15s %-15s\n",
           "Ma mon hoc", "Ten mon hoc",
           "So tin chi", "So tiet");

    for (int i = 0; i < n; i++)
    {
        printf("%-15s %-30s %-15d %-15d\n",
               ds[i].maMH,
               ds[i].tenMH,
               ds[i].soTinChi,
               ds[i].soTiet);
    }
}

void SelectionSort(MonHoc *ds, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (ds[j].soTiet < ds[min].soTiet)
            {
                min = j;
            }
        }

        if (min != i)
        {
            MonHoc temp = ds[i];
            ds[i] = ds[min];
            ds[min] = temp;
        }
    }
}

int BinarySearch(MonHoc *ds, int n, int X, int *timThay)
{
    int left = 0;
    int right = n - 1;
    int count = 0;

    *timThay = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (ds[mid].soTiet == X)
        {
            *timThay = mid;
            count = 1;

            int i = mid - 1;
            while (i >= left && ds[i].soTiet == X)
            {
                count++;
                i--;
            }

            i = mid + 1;
            while (i <= right && ds[i].soTiet == X)
            {
                count++;
                i++;
            }

            return mid;
        }
        else if (ds[mid].soTiet < X)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void TimKiem(MonHoc *ds, int n, int X)
{
    int viTri = BinarySearch(ds, n, X, &viTri);

    if (viTri == -1)
    {
        printf("\nKhong tim thay mon hoc co so tiet bang %d.\n", X);
        return;
    }

    printf("\nCac mon hoc co so tiet bang %d:\n", X);

    for (int i = 0; i < n; i++)
    {
        if (ds[i].soTiet == X)
        {
            printf("%-15s %-30s %-15d %-15d\n",
                   ds[i].maMH,
                   ds[i].tenMH,
                   ds[i].soTinChi,
                   ds[i].soTiet);
        }
    }
}

int main()
{
    int n, X;

    printf("Nhap so mon hoc n: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("So mon hoc khong hop le!\n");
        return 0;
    }

    MonHoc *ds = (MonHoc *)malloc(n * sizeof(MonHoc));

    if (ds == NULL)
    {
        printf("Khong du bo nho!\n");
        return 1;
    }

    Nhap(ds, n);

    printf("\nDANH SACH MON HOC VUA NHAP");
    Xuat(ds, n);

    SelectionSort(ds, n);

    printf("\nDANH SACH SAU KHI SAP XEP TANG DAN THEO SO TIET");
    Xuat(ds, n);

    printf("\nNhap so tiet X can tim: ");
    scanf("%d", &X);

    TimKiem(ds, n, X);

    free(ds);

    getch();
    return 0;
}

