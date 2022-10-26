#include <iostream>

using namespace std;

void input(int &row, int &col, int a[100][100])
{
    cout << "Nhap vao so hang: ";
    cin >> row;
    cout << "Nhap vao so cot: ";
    cin >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Nhap du lieu cho o a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
}

void output(int row, int col, int a[100][100])
{
    cout << "Ma tran co " << row << " hang, co " << col << " cot.\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int a[100][100];
    int row, col;
    input(row, col, a);
    output(row, col, a);
    return 0;
}