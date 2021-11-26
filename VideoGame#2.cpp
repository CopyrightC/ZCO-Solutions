#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

vector<int> splitStr(string uglyString, string splitKey = " ")
{
    cout << uglyString.length();
    vector<int> splittedStr{};
    int start = 0;
    int end = 0;

    while (start < uglyString.length())
    {
        end = uglyString.find(splitKey, start);
        if (end == -1)
            end = uglyString.length();
        string subStr = uglyString.substr(start, end - start);
        splittedStr.push_back(stoi(subStr));
        start = end + 1;
    }

    return splittedStr;
}

vector<vector<ll>> takeInput()
{
    vector<vector<ll>> inputVector{};
    for (int x = 0; x < 3; ++x)
    {
        string input;
        cin >> input;
        vector<int> converted = splitStr(input);
        for (auto i : converted)
        {
            cout << i << endl;
        }
        input = "";
    }
    return inputVector;
}

int main()
{
    int x;
    for (int i = 0; i < 5; ++i)
    {
        cin >> x;
        cout << x << endl;
    }
}