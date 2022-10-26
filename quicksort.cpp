#include <iostream>
#include <cmath>

using namespace std;

void quicksort(int l, int r, int a[])
{
    int t = r;
    r--;
    /*    while (l<r){
            if (a[l] > a[t] && a[r] < a[t]){
                swap(a[l],a[r]);
                l++;
                r--;
            }
            if (a[l]<=a[t])
                l++;
            if (a[r]>=a[t])
                r--;
        }
        if (l==r && a[l]>a[t])
            swap(a[l],a[t]);
        l++;*/
    while (l < r)
    {
        if (a[l] < a[t] && a[r] > a[t])
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
        if (a[l] >= a[t])
            l++;
        if (a[r] <= a[t])
            r--;
    }
    if (l == r && a[l] < a[t])
        swap(a[l], a[t]);
    l++;
    if (0 < r)
        quicksort(0, r, a);
    if (l < t)
        quicksort(l, t, a);
}

int main()
{
    int n, a[1000];
    cout << "Nhap so phan tu:\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << "\n";
    quicksort(0, n - 1, a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    return 0;
}