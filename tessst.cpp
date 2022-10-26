#include<iostream>
using namespace std;

void nhapmang(int mang[100][100],int hang, int cot){
    for(int i=0;i<hang;i++)
        for (int j=0;j<cot;j++)
        {
            cout<< " nhap du lieu mang ["<<i<<"]["<<j<<"]= ";
            cin>> mang[i][j];

        }   
}
void xuatmang(int mang[100][100],int hang, int cot){
    for(int i=0;i<hang;i++){
    for(int j=0;j<cot;j++){
        cout<< mang[i][j] <<" ";
    }
    cout<< "\n";
    }
}

int tongcot(int mang[][100],int col, int hang ){
    int sum= 0;
    for (int i=0;i< hang;i++)
    {
        sum= sum+ mang[i][col];
    }
    return sum;

}

int main(){
    int mang[100][100];
    int hang;
    cout<<"nhap so hang: ";
    cin>> hang;
    int cot;
    cout<<"nhap so dong: ";
    cin>> cot;
    int col;
    cout<< " nhap cot can tinh tong: ";
    cin>>col;
    nhapmang(mang, hang,cot);
    xuatmang(mang,hang,cot);
    cout<< tongcot(mang,col,hang);
    int mang1[100];
    int soluong = hang*cot;
    return 0;
}