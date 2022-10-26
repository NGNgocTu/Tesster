#include <iostream>

using namespace std;

void input(int &n, int a[]);

void output(int n, int a[]);

bool checkEven(int x);

int totalEven(int n, int a[]);

int countOdd(int n, int a[]);

int main()
{
    int n, a[1001];
    input(n, a);
    output(n, a);
    cout << "Tong cac phan tu la so chan la: " << totalEven(n, a) << "\n";
    cout << "So chu so le trong mang la: " << countOdd(n, a) << "\n";
    return 0;
}

void input(int &n, int a[])
{
    cout << "Nhap vao so luong phan tu: ";
    cin >> n;
    cout << "Nhạp vao cac phan tu cua mang: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao a[" << i << "]= ";
        cin >> a[i];
    }
}

void output(int n, int a[])
{
    cout << "Xuat cac phan tu: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << "\n";
}

bool checkEven(int x)
{
    if (x % 2 == 0)
        return true;
    return false;
}

int totalEven(int n, int a[])
{
    int total = 0;
    for (int i = 0; i < n; i++)
        if (checkEven(a[i]))
            total += a[i];
    return total;
}

int countOdd(int n, int a[])
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (!checkEven(a[i]))
            count++;
    return count;
}