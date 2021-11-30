#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, K, input;
vector<ll> takeInput()
{
    vector<ll> inputVector{};

    cin >> N >> K;
    for (int x = 0; x < N; ++x)
    {
        cin >> input;
        inputVector.push_back(input);
    }
    return inputVector;
}

void solve(vector<ll> numbers)
{
    sort(numbers.begin(), numbers.end());
    ll result = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int x = i + 1; x < N; ++x)
        {
            if (std::abs(numbers[i] - numbers[x]) >= K)
            {
                result += N - x;
                break;
            }
        }
    }
    cout << result;
}

int main()
{
    vector<ll> inputVector = takeInput();
    solve(inputVector);
}