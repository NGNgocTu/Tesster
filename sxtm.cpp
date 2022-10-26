#include <iostream>

using namespace std;

int main()
{
    int n, m, a[100][100],b[100][2];
    cout << "Nhap hang: ";
    cin >> n;
    cout << "Nhap cot: ";
    cin >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            cout << "Nhap a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
            b[i][1] +=a[i][j];
        }
        b[i][2]= i;
    }
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (b[i][1]>b[j][1]){
                swap(b[i][1],b[j][1]);
                swap(b[i][2],b[j][2]);
            }
    for (int i=0;i<n;i++){
        for (int j=0; j<m; j++)
            cout << a[b[i][2]][j] << "\t";
        cout << "\n";
    }

    return 0;
}