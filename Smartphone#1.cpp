#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

vector<int> vals{};
int num;
int val;
int main()
{
    vector<int> copy{0, 0};
    cin >> num;

    for (int x = 0; x < num; ++x)
    {
        cin >> val;
        vals.push_back(val);
    }

    sort(vals.begin(), vals.end(), greater<int>());

    for (int i = 0; i < 3; ++i)
    {
        int price = vals[i] * (i + 1);
        if (price > copy[0])
        {
            copy[0] = price;
            copy[1] = i;
        }
    }
    cout << vals[copy[1]] << endl;
}