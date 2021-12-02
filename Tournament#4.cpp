#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

ll N;
vector<int> takeInput()
{
    ll item;
    vector<int> input{};
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> item;
        input.push_back(item);
    }
    return input;
}

void solve(vector<int> input)
{
    ll revenue = 0;
    ll sum;
    sort(input.begin(), input.end(), greater<ll>());
    for (int i = 0; i < N - 1; ++i)
    {
        sum = accumulate(input.begin() + i + 1, input.end(), 0);
        revenue += (input[i] * (N - i - 1)) - sum;
    }
    cout << revenue;
}

int main()
{
    vector<int> input = takeInput();
    solve(input);
}