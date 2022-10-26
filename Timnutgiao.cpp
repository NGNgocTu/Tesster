#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void input(ifstream &f, int &n, int a[100][100], int vt[], bool &kt)
{
    f >> n;
    int t = 0;
    for (int k = 1; k <= n; k++)
    {
        int i, j;
        f >> i;
        if (i > t)
            t = i;
        while (true)
        {
            f >> j;
            if (j > 0)
            {
                a[i][j] = 1;
                if (a[i][j] == a[j][i])
                    kt = 0;
                vt[i]++;
            }
            if (f.eof())
                break;
            char c;
            f.get(c);
            char ch[2] = {c};
            if (strcmp(ch, " ") != 0)
            {
                break;
            }
        }
    }
    if (n < t)
        n = t;
}

void output(ofstream &f, int n, int a[100][100], int vt[])
{
    f << "Ma tran ke:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f << a[i][j] << "  ";
        }
        f << "\n";
    }
    f << "Danh sach canh:\n";
    for (int i = 1; i <= n; i++)
        if (vt[i] > 0)
            for (int j = 1; j <= n; j++)
                if (a[i][j] != 0)
                    f << i << " " << j << "\n";
    f << "Danh sach ke:\n";
    for (int i = 1; i <= n; i++)
    {
        int t = 0;
        if (vt[i] > 0)
        {
            for (int j = 1; j <= n; j++)
                if (a[i][j] != 0)
                {
                    if (t == 0)
                    {
                        f << i << " " << j;
                        t++;
                    }
                    else
                        f << " " << j;
                }
            f << "\n";
        }
    }
}

void activity(bool kt, ofstream &f, int vt[], int n, int a[100][100])
{
    int t;
    if (kt)
    {
        f << "Do thi co huong\n";
        for (int i = 1; i <= n; i++)
        {
            if (vt[i] > 0)
            {
                t = 0;
                for (int j = 1; j <= n; j++)
                    if (a[j][i] != 0)
                        t++;
                f << i << " co " << t << " bat vao va co " << vt[i] << " bat ra\n";
            }
        }
    }
    else
    {
        f << "Do thi vo huong\n";
        for (int i = 1; i <= n; i++)
            f << i << " co " << vt[i] << " bat vao va co " << vt[i] << " bat ra\n";
    }
}

int main()
{
    int n, a[100][100], vt[100];
    bool kt = 1;
    ifstream f1("Timnutgiao.inp");
    ofstream f2("Timnutgiao.out");
    input(f1, n, a, vt, kt);
    output(f2, n, a, vt);
    activity(kt, f2, vt, n, a);
    f1.close();
    f2.close();
    return 0;
}