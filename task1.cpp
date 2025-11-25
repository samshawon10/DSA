#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return sum(n - 1) + n;
}

int mySeries(int n)
{
    if (n == 2)
    {
        return 2;
    }
    return mySeries(n - 3) + n;
}

int NthSeries(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return NthSeries(n - 1) + (2 * n - 1);
}

int mySeries1(int n)
{
    if (n == 1)
    {
        return 2;
    }
    // if (n == 0)
    // {
    //     return 0;
    // }
    return mySeries1(n - 1) + (4 * n - 2);
}

int findNthTerm(int n)
{

    if (n == 1)
    {
        return 1;
    }
    return findNthTerm(n - 1) + 3;
}

int DistinctWays(int n)
{
    if (n == 1 || n == 2)
    {
        return n;
    }
    return DistinctWays(n - 1) + DistinctWays(n - 2);
}

int main()
{
    int n = 4;
    cout << "Sum from 1 to N:" << sum(n) << endl;
    cout << "Sum of Myseries:" << mySeries(8) << endl;
    cout << "Sum of Nthseries:" << NthSeries(10) << endl;
    cout << "Sum of Myseries1:" << mySeries1(1) << endl;
    cout << "Value of Nth term:" << findNthTerm(5) << endl;
    cout << "Find the way of climb Nth stair:" << DistinctWays(6);

    return 0;
}