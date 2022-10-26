#include <iostream>
#include <fstream>

using namespace std;

int main(){
    freopen ("Nhap.inp","r",stdin);
    freopen ("Xuat.out","w",stdout);
    int n,m,k;
    int a[100];
    string t;
    cin >> n >> m >> k;
    cout << n << "\t" << m << "\t" << k << "\n";
    for (int i = 1; i<n+1; i++){
        cin >> a[i];
    }
    for (int i = 1; i<n+1; i++){
        cout << a[i] << "\n";
    }
    return 0;
}