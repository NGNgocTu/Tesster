#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void input(string &n)
{
    n = " ";
    while (n.length() % 2 != 0)
    {
        cout << "Nhap so can kiem tra: ";
        cin >> n;
    }
}
string output(string s)
{
    int n, t, s1, s2, l;
    l = s.length();
    s1 = 0;
    s2 = 0;
    stringstream str2num(s);
    str2num >> n;
    for (int i = 0; i < l; i++)
    {
        if (i < l / 2)
        {
            t = n % 10;
            s1 += t;
            n /= 10;
        }
        else
        {
            t = n % 10;
            s2 += t;
            n /= 10;
        }
    }
    if (s1 == s2)
    {
        return "La so hanh phuc";
    }
    else
    {
        return "Khong la so hanh phuc";
    }
}

int main()
{
    string s;
    input(s);
    cout << output(s);
    return 0;
}