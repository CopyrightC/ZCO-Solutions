#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> takeInput()
{
    int N, item;
    std::cin >> N;
    std::vector<int> bambooHeights{};
    for (int i = 0; i < N; ++i)
    {
        std::cin >> item;
        bambooHeights.push_back(item);
    }
    return bambooHeights;
}

void solve(std::vector<int> input)
{
    std::sort(input.begin(), input.end());
    int diff = 0;
    int elem = 0;
    int currentCount = 1;
    int maxLen = 0;
    for (int i = 0; i < input.size() - 1; ++i)
    {
        for (int x = i + 1; x < input.size(); ++x)
        {
            currentCount = 1;
            diff = input[x] - input[i];
            elem = input[i] + diff;
            while (std::binary_search(input.begin(), input.end(), elem))
            {
                elem += diff;
                currentCount++;
            }
            maxLen = std::max(maxLen, currentCount);
        }
    }
    std::cout << maxLen << std::endl;
}

int main()
{
    std::vector<int> input = takeInput();
    solve(input);
}