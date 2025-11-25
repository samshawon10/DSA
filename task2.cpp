// f(n,m)=total no of sandwiches you can make if you have n breads and m eggs.you need  2 bread and 3 eggs to make a sandwich.

#include <iostream>
using namespace std;
int NumofSandwich(int n, int m)
{
    if (n < 2 || m < 3)
    {
        return 0;
    }
    return 1 + NumofSandwich(n - 2, m - 3);
}

int main()
{
    int n, m;
    cout << "Enter the value of Bread and Eggs :";
    cin >> n >> m;

    cout << "Number of Sandwich:" << NumofSandwich(n, m) << endl;

    return 0;
}