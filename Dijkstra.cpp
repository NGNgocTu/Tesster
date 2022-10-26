#include <iostream>
#include <cmath>

using namespace std;

void input(int &n, int &k, int &s, int &e, int a[100][100]){
    int i,j;
    cin >> n >> k >> s >>e;
    for (int t =0; t<k; t++){
        cin >> i >> j >> a[i][j];
        a[j][i]=a[i][j];
    }
}

int main(){
    int n,k,s,e;
    int a[100][100];
    int ok[100];
    int d[100];
    int u,v,vt;
    vt = 0;
    ::fill_n(d,100,1000);
    ::fill_n(ok,100,0);
    input(n,k,s,e,a);
    d[s] = 0;
    for (int i=1; i<n; i++){
        u = 100;
        for (int t = 1; t< n+1; t++){
            if ((u>d[t]) && (ok[t]==0)){
                vt = t;
                u = d[t];
            }
        }
        u = vt;
        ok[u] = 1;
        for (int v=1; v<n+1; v++){
            if ((a[u][v]!=0) && (d[v]>d[u]+a[u][v])) { d[v]=d[u]+a[u][v]; } 
        }
    }
    cout << d[e] << "\n";
    return 0;
}
/*
6 8 1 6
1 2 7 
1 3 6
1 4 15
2 4 3
3 4 8
4 5 4
4 6 2
5 6 1
*/