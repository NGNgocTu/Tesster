#include <iostream>

using namespace std;

int main(){
    int a,b;
    char s;
    cout << "Nhap so thu nhat: \n";
    cin >> a;
    cout << "Nhap so thu hai: \n";
    cin >> b;
    cout << "Nhap phep tinh ban muon: \n";
    cin >> s;
    if (s == '+'){
        cout << "ket qua la: " << a+b;
    }
    else if (s == '-'){
        cout << "Ket qua la: " << a-b;
    }
    else if (s == '*'){
        cout << "Ket qua la: " << a*b;
    }
    else {
        cout << "Ket qua la: " << a/b;
    }
}