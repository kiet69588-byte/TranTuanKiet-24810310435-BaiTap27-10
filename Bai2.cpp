
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct SinhVien
{
    int maSV;
    char tenSV[50];
    char lop[30];
    float tongKet;
};

void Nhap(SinhVien *ds, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap sinh vien thu %d:\n", i + 1);

        printf("Ma sinh vien: ");
        scanf("%d", &ds[i].maSV);

        printf("Ten sinh vien: ");
        scanf(" %[^\n]", ds[i].tenSV);

        printf("Lop: ");
        scanf(" %[^\n]", ds[i].lop);

        printf("Diem tong ket: ");
        scanf("%f", &ds[i].tongKet);
    }
}

void Xuat(SinhVien *ds, int n)
{
    printf("\n%-15s %-30s %-20s %-15s\n",
           "Ma SV", "Ten sinh vien", "Lop", "Tong ket");

    for (int i = 0; i < n; i++)
    {
        printf("%-15d %-30s %-20s %-15.2f\n",
               ds[i].maSV,
               ds[i].tenSV,
               ds[i].lop,
               ds[i].tongKet);
    }
}

void BubbleSort(SinhVien *ds, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (ds[j].tongKet > ds[j + 1].tongKet)
            {
                SinhVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

int BinarySearch(SinhVien *ds, int n, float X)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (ds[mid].tongKet == X)
        {
            return mid;
        }
        else if (ds[mid].tongKet < X)
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

void TimKiem(SinhVien *ds, int n, float X)
{
    int viTri = BinarySearch(ds, n, X);

    if (viTri == -1)
    {
        printf("\nKhong tim thay sinh vien co diem tong ket bang %.2f\n", X);
        return;
    }

    printf("\nDanh sach sinh vien co diem tong ket bang %.2f:\n", X);

    int i = viTri;

    while (i >= 0 && ds[i].tongKet == X)
    {
        i--;
    }

    i++;

    while (i < n && ds[i].tongKet == X)
    {
        printf("%-15d %-30s %-20s %-15.2f\n",
               ds[i].maSV,
               ds[i].tenSV,
               ds[i].lop,
               ds[i].tongKet);
        i++;
    }
}

int main()
{
    int n;
    float X;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("So luong sinh vien khong hop le!\n");
        return 0;
    }

    SinhVien *ds = (SinhVien *)malloc(n * sizeof(SinhVien));

    if (ds == NULL)
    {
        printf("Khong du bo nho!\n");
        return 1;
    }

    Nhap(ds, n);

    printf("\nDANH SACH SINH VIEN VUA NHAP\n");
    Xuat(ds, n);

    BubbleSort(ds, n);

    printf("\nDANH SACH SINH VIEN SAU KHI SAP XEP TANG DAN THEO DIEM TONG KET\n");
    Xuat(ds, n);

    printf("\nNhap diem tong ket X can tim: ");
    scanf("%f", &X);

    TimKiem(ds, n, X);

    free(ds);

    getch();
    return 0;
}

