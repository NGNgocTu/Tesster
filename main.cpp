#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// bai 1
float vongLap(int n) {
    float s=0;
    for (int i=0 ; i<n ; i++)
    {
        int x=1;
        for (int j=1 ; j<=i ; j++)
        {
            x*=j;
        }

        s+=i/x;
    }

    return s;
}

int deQuyGiaiThua(int n) {
    if (n==1)
    {
        return 1;
    }
     
    return n*deQuyGiaiThua(n-1);
}

float deQuyTong(int n) {
	
	if (n==1) {
		return 1;
	}
	
	return 1.0/deQuyGiaiThua(n-1) + deQuyTong(n-1);
}

//Bai 2
void capPhatDong(int *&p, int n) {
	p = new int(n);
}

void xoa(int *&p) {
	delete[] p;
}

void nhap(int n, int *p) {
	for (int i=0; i<n ; i++) {
		cout<<"Nhap phan tu thu "<<i+1<<" : ";
		cin>>*(p+i);
	}
}

void xuat(int n, int *p) {
	for (int i=0; i<n ; i++) {
		cout<<"Phan tu thu "<<i+1<<" la: "<<*(p+i)<<endl;
	}
}

int ktraSNT(int n) {
	int dem=0;
	if(n<2) {
		return 0;
	}
	for (int i=2; i<=n ; i++) {
		if (n%i==0) {
			dem++;
		}
	}
		
	if (dem==1) {
		return 1;
	}
	return 0;
}

int soNguyenToLonNhat(int *p, int n) {//
	int a[100],j=0;
	
	for(int i=0 ; i<n ; i++) {
		if(ktraSNT( *(p+i) )) {//
			a[j]=*(p+i);//
			j++;
		}
	}
	if(j==0) {
		return 0;
	}
	
	int max=a[0];
	for(int k=1 ; k<j ; k++) {
		if (a[k]>max){
			max=a[k];
		}
	}
	return max;
}

void swap(int &m, int &n) {
	int t;
	t=m;
	m=n;
	n=t;
}

void xapSepSNT(int *p, int n) {
	for (int i=0 ; i<n-1 ; i++) {
		if (ktraSNT( *(p+i) )) {
			for(int j=i+1 ; j<n ; j++) {
				if(ktraSNT( *(p+j) ) && *(p+i) > *(p+j)) {
					swap(*(p+i),*(p+j));
				}
			}
		}
	}
	
	xuat(n,p);
}

// cau 3
char *xoaChuoi(char *s, int pos, int len) {
	int n = strlen(s);
	strcpy(s+pos, s+pos+len);
	return s;
}

//Cau 4 --------------------------------------------------------------------------------------
struct DATE {
	int ngay, thang, nam;
};
struct SV {
	char ma[11];
	char ten[31];
	DATE ngaySinh;
	float toan, ly , hoa;
	float diemTong;
};

void nhapTungSV(SV &sv) {
	cout<<"Nhap ma: ";
	cin>>sv.ma;
	cin.ignore();
	cout<<"Nhap ten: ";
	cin.getline(sv.ten,31);
	cout<<"Nhap ngay sinh: ";
	cin>>sv.ngaySinh.ngay;
	cout<<"Nhap thang sinh: ";
	cin>>sv.ngaySinh.thang;
	cout<<"Nhap nam sinh: ";
	cin>>sv.ngaySinh.nam;
	cout<<"Nhap diem toan: ";
	cin>>sv.toan;
	cout<<"Nhap diem ly: ";
	cin>>sv.ly;
	cout<<"Nhap diem hoa: ";
	cin>>sv.hoa;
	cin.ignore();
	sv.diemTong = sv.hoa + sv.ly +sv.toan;
}

void truyenDuLieuFile(fstream &f, SV sv) {
	f.open("quanLySinhVien.txt",ios::app);
	f<<sv.ma<<';'<<sv.ten<<';'<<sv.ngaySinh.ngay<<'/'<<sv.ngaySinh.thang<<'/'<<sv.ngaySinh.nam<<';'<<sv.toan<<';'<<sv.ly<<';'<<sv.hoa<<';'<<sv.diemTong<<endl;
	f.close();
}

void nhapDanhSachSV(fstream &f, int n) {
	cout<<"---____BAT DAU NHAP SINH VIEN____---"<<endl;
	for(int i=0 ; i<n ; i++) {
		SV sv;
		cout<<"----Nhap sinh vien thu "<<i+1<<"----"<<endl;
		nhapTungSV(sv);
		truyenDuLieuFile(f,sv);
	}
}

int main() {

//    cout<<deQuyTong(5)<<endl;
//    
//    int *p, n=2;
//    capPhatDong(p,n);
//    nhap(n,p);
//    xuat(n,p);
//    
//    cout<<"So NT lon nhat la: "<<soNguyenToLonNhat(p,n)<<endl;
//    
//    cout<<"----Sau khi sap xep SNT----"<<endl;
//    xapSepSNT(p,n);
//    cout<<endl;
//    xoa(p);
//
//    char name[50]="Tran Kim Hoang";
//    //name = "Tran Kim Hoang";
//    
//    cout<<"Chuoi sau khi xoa la: "<<xoaChuoi(name,5,4)<<endl;
    
    //bai 4 -----------------------------------------------------------------------------------
    fstream f;
    int soSV=2;
    nhapDanhSachSV(f,soSV);
    
    
    return 0;
}
