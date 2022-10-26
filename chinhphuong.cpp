#include <iostream>
#include <cmath>

using namespace std;

string chinhphuong(int n){
    int i = 1;
    int s = 1;
    while (s<n) {
        s = i*i;
        i++;
    }
    if (s==n){
        return "La so chinh phuong";
    } 
    else{
        return "Khong la so chinh phuong";
    }
}
int input(){
    int a;
    cout << "Nhap vao so: \n";
    cin >> a;
    return a;
}

int main(){
    int n;
    n = input();
    cout << chinhphuong(n);
}