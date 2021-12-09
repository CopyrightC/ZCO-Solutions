#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, item;
vector<vector<int>> takeInput()
{
    vector<vector<int>> inp{{}};

    cin >> N >> K;
    for (int i = 0; i < N * 2; ++i)
    {
        cin >> item;
        if (i < N)
        {
            inp[0].push_back(item);
        }
        else
        {
            inp[1].push_back(item);
        }
    }
    return inp;
}

void solve(vector<vector<int>> heights)
{
    int maxHeightShelf = 0;
    for (int x = 0; x < K; ++x)
    {
        sort(heights[0].begin(), heights[0].end());
        sort(heights[1].begin(), heights[1].end());

        if ((heights[0][heights[0].size() - 1] < heights[1][0]) || (heights[1][heights[1].size() - 1] < heights[0][0]))
        {
            break;
        }
        if (heights[0][heights[0].size() - 1] > heights[1][heights[1].size() - 1])
        {
            heights[1].pop_back();
            heights[1].push_back(heights[0][0]);
        }
        else if (heights[0][heights[0].size() - 1] < heights[1][heights[1].size() - 1])
        {
            heights[0].pop_back();
            heights[0].push_back(heights[1][0]);
        }
    }
    sort(heights[0].begin(), heights[0].end());
    sort(heights[1].begin(), heights[1].end());
    cout << heights[1][heights[1].size() - 1] + heights[0][heights[0].size() - 1];
}

int main()
{
    vector<vector<int>> inp = takeInput();
    solve(inp);
}

// [3,5,3] ; [7,6,12]