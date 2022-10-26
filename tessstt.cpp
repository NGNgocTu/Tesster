#include <iostream>

using namespace std;

void nhap(int &a, int &b, int &c, int &d){
    cin >> a >> b >> c >> d;
}

int main(){
    int a,b,c,d;
    nhap(a,b,c,d);
    cout << a << " " << b << " "<< c  << " "<< d;
}