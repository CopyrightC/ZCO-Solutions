#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

vector<ll> splitStr(string uglyString, string splitKey = " ")
{
    vector<ll> splittedStr{};
    int start = 0;
    int end = 0;

    while (start < uglyString.length())
    {
        end = uglyString.find(splitKey, start);
        if (end == -1)
            end = uglyString.length();
        string subStr = uglyString.substr(start, end - start);
        splittedStr.push_back(stoll(subStr));
        start = end + 1;
    }

    return splittedStr;
}

vector<vector<ll>> takeInput()
{
    vector<vector<ll>> inputVector{};
    string input;
    for (int x = 0; x < 3; ++x)
    {
        getline(cin, input);
        vector<ll> converted = splitStr(input);
        inputVector.push_back(converted);
    }
    return inputVector;
}

int main()
{
    vector<vector<ll>> inputVector = takeInput();
    for (auto i : inputVector)
    {
        cout << i[0] << endl;
    }
}