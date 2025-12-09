#include <iostream>
#include <vector>
using namespace std;

int countFrequency(vector<int> a, int i, int j, int t)
{
    if (i == j)
    {
        if (a[i] == t)
        {
            return 1;
        }
        else
            return 0;
    }

    int mid = (i + j) / 2;
    int l = countFrequency(a, i, mid, t);
    int r = countFrequency(a, mid + 1, j, t);
    return l + r;
}

int main()
{
    vector<int> a = {2, 5, 1, 5, 5, 1, 3};
    int n = a.size();
    int target = 5;
    int c = countFrequency(a, 0, n - 1, target);
    cout << "Frequency: " << c << endl;
}
