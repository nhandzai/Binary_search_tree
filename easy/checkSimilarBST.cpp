#include <iostream>
#include <vector>
using namespace std;
bool checkSimillarBst(int *a, int *b, int n, int m)
{
    if (n != m)
        return false;
    else if (n == 0 && m == 0)
        return true;

    if (a[0] != b[0])
        return false;

    vector<int> leftA;
    vector<int> leftB;

    vector<int> rightA;
    vector<int> rightB;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[0])
            leftA.push_back(a[i]);
        else
            rightA.push_back(a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (b[i] < b[0])
            leftB.push_back(b[i]);
        else
            rightB.push_back(b[i]);
    }
    bool left = checkSimillarBst(leftA.data(), leftB.data(), leftA.size(), leftB.size());
    bool right = checkSimillarBst(rightA.data(), rightB.data(), rightA.size(), rightB.size());
    return left && right;
}
int main()
{
    int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
    int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    cout << checkSimillarBst(a, b, n, m);
    return 0;
}