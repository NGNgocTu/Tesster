#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a[100][100];
    int n, m;
    // nhập số hàng, cột
    cout << "Nhap so hang: ";
    cin >> n;
    cout << "Nhap so cot: ";
    cin >> m;
    cout << "So hang la: " << n << ", so cot la: " << m << "\n";
    // nhập mảng 2 chiều
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // xuất mảng 2 chiều
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << "\ ";
        }
        cout << "\n";
    }

    return 0;
}