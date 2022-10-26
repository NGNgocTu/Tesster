#include<iostream>
using namespace std;
int main()
{
    bool flag = 1;
    int n;
    int a[100];
    cin >> n;
    for (int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    if (a[0] > a[1])
        for (int i=1; i<n-1; i++)
            if (a[i] < a[i+1]){
                flag = 0;
            }
    else
        for (int i=1; i<n-1; i++)
            if (a[i] < a[i+1]){
                flag = 0;
                break;
            }
    if (flag == 1) {
        cout << "YES";
    }
    else 
    {
        cout << "NO";
    }
}