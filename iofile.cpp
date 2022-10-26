#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream f("tesst.inp");
    ofstream f1("tesst.out");
    string s;
    //f1 << "Helloooo!!!";
    /*while (getline(f,s)){
        f1 << s;
    }*/
    int n,m,k;
    f >> n >> m >> k;
    cout << n << "\t" << m << "\t" << k << "\n";
    int a[1000];
    for (int i = 1; i< n+1; i++ ){
        f >> a[i];
    }
    for (int i = 1; i< n+1; i++ ){
        cout <<  a[i] << "\n";
    }
    f.close();
    f1.close();
    return 0;
}