#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, K, item;
vector<int> takeInput()
{
    vector<int> input{};
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> item;
        input.push_back(item);
    }
    return input;
}
void solve(vector<int> input)
{
    vector<int> combination{};
    vector<vector<int>> combinations{};
    sort(input.begin(), input.end(), greater<int>());

    for (int i = 0; i < input.size(); ++i)
    {
        for (int x = i + 1; x < input.size(); ++x)
        {
            if (input[i] + input[x] < K)
            {
                combination = {input[i], input[x]};
                combinations.push_back(combination);
            }
        }
    }
    cout << combinations.size();
}
int main()
{
    vector<int> input = takeInput();
    solve(input);
}