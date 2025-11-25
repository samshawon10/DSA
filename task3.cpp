
#include <iostream>
using namespace std;
int MakeCar(int x, int y ,int z)
{
    if (x < 1 || y < 2 || z<3)
    {
        return 0;
    }
    return 1 + MakeCar(x-1, y-2,z-3);
}

int main()
{
    int n, m ,p;
    cout << "Enter the value of rectanglar and triangle,circle :";
    cin >> n >> m >>p;

    cout << "Number of car:" << MakeCar(n, m,p) << endl;

    return 0;
}