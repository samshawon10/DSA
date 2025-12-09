#include<iostream>
#include<vector>
using namespace std;

pair<int, int> FindMaxMin(vector<int> a, int i, int j){
    //base case
    if(i == j){
        return {a[i], a[i]};
    }

    //Divide
    int mid = (i + j)/2;

    //Conquer
    pair<int, int> l = FindMaxMin(a, i, mid);
    pair<int, int> r = FindMaxMin(a, mid+1, j);

    //combine
    int gmax, gmin, hmax, hmin, fmax, fmin;

    gmax = l.first; gmin = l.second;

    hmax = r.first; hmin = r.second;

    fmax = max(gmax, hmax);
    fmin = min(gmin, hmin);

    return {fmax, fmin};
}

int main(){
    vector<int> arr = {4, 34, 23, 98, 6, 13, 21};
    int n = arr.size();
    pair<int, int> x = FindMaxMin(arr, 0, n-1);

    cout << "Max: " << x.first << endl;
    cout << "Min: " << x.second << endl;
}

