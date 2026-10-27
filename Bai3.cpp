
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct HANGHOA
{
    char ma[20];
    char ten[50];
    int ngay, thang, nam;
    float gia;
};

void Nhap(HANGHOA *ds, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap hang hoa thu %d:\n", i + 1);

        printf("Ma hang: ");
        scanf(" %[^\n]", ds[i].ma);

        printf("Ten hang: ");
        scanf(" %[^\n]", ds[i].ten);

        printf("Ngay xuat (ngay thang nam): ");
        scanf("%d%d%d", &ds[i].ngay, &ds[i].thang, &ds[i].nam);

        printf("Gia xuat (trieu dong): ");
        scanf("%f", &ds[i].gia);
    }
}

void Xuat(HANGHOA *ds, int n)
{
    printf("\n%-15s %-25s %-15s %-15s\n",
           "Ma hang", "Ten hang", "Ngay xuat", "Gia xuat");

    for (int i = 0; i < n; i++)
    {
        printf("%-15s %-25s %02d/%02d/%04d %-15.2f\n",
               ds[i].ma, ds[i].ten,
               ds[i].ngay, ds[i].thang, ds[i].nam,
               ds[i].gia);
    }
}

void BubbleSort(HANGHOA *ds, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (ds[j].gia > ds[j + 1].gia)
            {
                HANGHOA temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

int BinarySearch(HANGHOA *ds, int n, float X)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (ds[mid].gia == X)
            return mid;
        else if (ds[mid].gia < X)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void TimKiem(HANGHOA *ds, int n, float X)
{
    int vt = BinarySearch(ds, n, X);

    if (vt == -1)
    {
        printf("\nKhong tim thay hang hoa co gia %.2f trieu dong!\n", X);
        return;
    }

    printf("\nDanh sach hang hoa co gia %.2f trieu dong:\n", X);

    int i = vt;
    while (i >= 0 && ds[i].gia == X)
        i--;

    i++;

    while (i < n && ds[i].gia == X)
    {
        printf("%-15s %-25s %02d/%02d/%04d %-15.2f\n",
               ds[i].ma, ds[i].ten,
               ds[i].ngay, ds[i].thang, ds[i].nam,
               ds[i].gia);
        i++;
    }
}

int main()
{
    int n;
    float X;

    printf("Nhap so luong hang hoa: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("So luong khong hop le!\n");
        return 0;
    }

    HANGHOA *ds = (HANGHOA *)malloc(n * sizeof(HANGHOA));

    if (ds == NULL)
    {
        printf("Khong du bo nho!\n");
        return 1;
    }

    Nhap(ds, n);

    printf("\nDANH SACH HANG HOA VUA NHAP\n");
    Xuat(ds, n);

    BubbleSort(ds, n);

    printf("\nDANH SACH HANG HOA SAU KHI SAP XEP TANG DAN THEO GIA\n");
    Xuat(ds, n);

    printf("\nNhap gia X can tim (trieu dong): ");
    scanf("%f", &X);

    TimKiem(ds, n, X);

    free(ds);
    getch();

    return 0;
}

