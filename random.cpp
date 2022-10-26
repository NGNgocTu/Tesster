#include <cstdlib>
#include <ctime>
#include <iostream>  

using namespace std;

int main()
{
    int a [100];
	srand(time(NULL));
	for (int i=1; i <= 50; i++){
        a[i] = rand() % (200 - 2 + 1) + 2;
        cout << a[i] << "\t";
        if (i%10 ==0) 
            cout << "\n";
    }
	return 0;
}