#include <iostream>

using namespace std;

class MonPhai
{
public:
	virtual char PhanLoai() = 0;
	virtual int TLSatThuong(MonPhai* m) = 0;

};
class Kim :public MonPhai
{
public:
	char PhanLoai()
	{
		return 'k';
	}
	int TLSatThuong(MonPhai* m)
	{
		if (m->PhanLoai() == 't')
			return 10;
		if (m->PhanLoai() == 'm')
			return 20;
		if (m->PhanLoai() == 'h')
			return -20;
		return 0;
	}

};

class Thuy :public MonPhai
{
public:
	int TLSatThuong(MonPhai* m)
	{
		if (m->PhanLoai() == 'm')
			return 10;
		if (m->PhanLoai() == 'h')
			return 20;
		if (m->PhanLoai() == 'o')
			return -20;
		return 0;
	}
	char PhanLoai()
	{
		return 't';
	}

};

class Moc :public MonPhai
{
public:
	char PhanLoai()
	{
		return 'm';
	}
	int TLSatThuong(MonPhai* m)
	{
		if (m->PhanLoai() == 'h')
			return 10;
		if (m->PhanLoai() == 'o')
			return 20;
		if (m->PhanLoai() == 'k')
			return -20;
		return 0;
	}
};

class Hoa :public MonPhai
{
public:
	char PhanLoai()
	{
		return 'h';
	}
	int TLSatThuong(MonPhai* m)
	{
		if (m->PhanLoai() == 'o')
			return 10;
		if (m->PhanLoai() == 'k')
			return 20;
		if (m->PhanLoai() == 't')
			return -20;
		return 0;
	}
};

class Tho :public MonPhai
{
public:
	char PhanLoai()
	{
		return 'o';
	}
	int TLSatThuong(MonPhai* m)
	{
		if (m->PhanLoai() == 'k')
			return 10;
		if (m->PhanLoai() == 't')
			return 20;
		if (m->PhanLoai() == 'm')
			return -20;
		return 0;
	}
};

class PhanTu
{
protected:
	int iCapDo;
	MonPhai* mpMonPhai;
public:
	float SatThuong(PhanTu* p)
	{
		float fMST = MucSatThuong();
		return fMST + fMST * mpMonPhai->TLSatThuong(p->GetMonPhai()) / 100;
	}
	MonPhai* GetMonPhai()
	{
		return mpMonPhai;
	}
	void Nhap()
	{
		cout << "Nhap cap do: ";
		cin >> iCapDo;
		cout << "Nhap mon phai (kim thuy moc hoa tho): ";
		char cLoai;
		cin >> cLoai;
		switch (cLoai)
		{
		case 'k':
			mpMonPhai = new Kim;
			break;
		case 't':
			mpMonPhai = new Thuy;
			break;
		case 'm':
			mpMonPhai = new Moc;
			break;
		case 'h':
			mpMonPhai = new Hoa;
			break;
		case 'o':
			mpMonPhai = new Tho;
		}
	}

	virtual float MucSatThuong() = 0;
	~PhanTu()
	{
		delete mpMonPhai;
	}
};

class NhanVat :public PhanTu
{
public:
	float MucSatThuong()
	{
		return iCapDo * 5;
	}
};

class QuaiVat :public PhanTu
{

public:
};

class ThongThuong :public QuaiVat
{
public:
	float MucSatThuong()
	{
		return iCapDo * 3;
	}
};

class DauLinh :public QuaiVat
{
public:
	float MucSatThuong()
	{
		return iCapDo * 7;
	}
};

class MangPhanTu
{
	PhanTu* arrPhanTu[50];
	int iN;
public:
	void SatThuong()
	{
		cout << "\nGia tri sat thuong A len B: ";
		cout << arrPhanTu[0]->SatThuong(arrPhanTu[1]) << endl;
		cout << "Gia tri sat thuong B len A: ";
		cout << arrPhanTu[1]->SatThuong(arrPhanTu[0]) << endl;
	}
	void MaxSatThuong()
	{
		float max = arrPhanTu[0]->MucSatThuong();
		for (int i = 0; i < iN; i++)
			if (max < arrPhanTu[i]->MucSatThuong())
				max = arrPhanTu[i]->MucSatThuong();
		cout << "\n(Nhung) phan tu co muc sat thuong cao nhat: ";
		for (int i = 0; i < iN; i++)
			if (max == arrPhanTu[i]->MucSatThuong())
				cout << i << " ";
	}
	void Nhap()
	{
		cout << "Nhap n: ";
		cin >> iN;
		int iLoai;
		for (int i = 0; i < iN; i++)
		{
			cout << "\nNhap loai: ";
			cin >> iLoai;
			switch (iLoai)
			{
			case 1:
				arrPhanTu[i] = new NhanVat;
				break;
			case 2:
				arrPhanTu[i] = new ThongThuong;
				break;
			case 3:
				arrPhanTu[i] = new DauLinh;
			}

			arrPhanTu[i]->Nhap();
		}
	}
	~MangPhanTu()
	{
		for (int i = 0; i < iN; i++)
			delete arrPhanTu[i];
	}
};
int main()
{
	MangPhanTu a;
	a.Nhap();
	a.MaxSatThuong();

	MangPhanTu b; //nhap n=2
	cout << "\n\nPhai nhap n=2\n";
	b.Nhap();
	b.SatThuong();
	return 0;
}