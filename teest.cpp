#include <iostream>

using namespace std;

class test
{
private:
    int id;
    static int next_id;

public:
    static int getnextid()
    {
        next_id = id++;
        return next_id;
    }
    test()
    {
        id = 0;
    }
};

int test::next_id = 1;

int main()
{
    test t;
    cout << t.getnextid() << "";
    return 0;
}