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
        end = uglyString.find(splitKey, start); //locate all whitespaces
        if (end == -1)
            end = uglyString.length();                         //for the last word
        string subStr = uglyString.substr(start, end - start); //slice word
        splittedStr.push_back(stoll(subStr));                  //covert string to long long and push it to splitStr vector
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
        vector<ll> convertedToLL = splitStr(input);
        inputVector.push_back(convertedToLL);
    }
    return inputVector;
}

void solve(vector<vector<ll>> inputVector)
{
    ll width = inputVector[0][0];
    ll maxHeight = inputVector[0][1];
    vector<ll> currentStack = inputVector[1];
    vector<ll> commands = inputVector[2];
    int cranePosition = 0; //left most
    bool isHoldingBox = false;

    for (auto command : commands)
    {
        if (command == 1 && cranePosition != 0)
            --cranePosition;

        else if (command == 2 && (cranePosition != width - 1))
            ++cranePosition;

        else if (command == 3 && !isHoldingBox && (currentStack[cranePosition] != 0))
        {
            currentStack[cranePosition] -= 1;
            isHoldingBox = true;
        }
        else if (command == 4 && isHoldingBox && (currentStack[cranePosition] <= maxHeight - 1))
        {
            currentStack[cranePosition] += 1;
            isHoldingBox = false;
        }

        else if (command == 0)
            break;
    }
    for (auto i : currentStack)
        cout << i << " ";
}

int main()
{
    vector<vector<ll>> inputVector = takeInput();
    solve(inputVector);
}