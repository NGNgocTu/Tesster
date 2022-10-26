#include <iostream>
#include <cmath>

using namespace std;

void input(int &num){
    cout <<"Nhap vao so le: ";
    cin >> num;
}

void output(int num, int a[100][100]){
    for (int i=0; i<num; i++){
        for (int j=0; j<num; j++){
            cout << a[i][j] << "\t";
        }
        cout <<"\n" << "\n";
    }
}

void dien(int n, int a[100][100]){
    int count = 1;
    int i,j;
    i = round(n/2) ;
    j = round(n/2) + 1;
    while (count <= n*n ){
        a[i][j] = count;
        count++;
        if ((count - 1)%n == 0){
            j = j+2;
            if (j == n) { j = 0; };
            if (j-n == 1) { j = 1; };
        } else if (j==n-1) { j=0; i--;} 
        else if (i==0) { i=n-1; j++; } 
        else {i--; j++; }
    }
    
}

int main(){
    int a[100][100];
    int n;
    input(n);
    dien(n,a);
    output(n,a);
}