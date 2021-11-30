#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
ll width;
ll maxHeight;
vector<ll> takeInput()
{
    vector<ll> currentStack{};
    ll input;
    cin >> width >> maxHeight;
    for (int x = 0; x < width; ++x)
    {
        cin >> input;
        currentStack.push_back(input);
    }
    return currentStack;
}

void solve(vector<ll> currentStack)
{
    int cranePosition = 0; //left most
    bool isHoldingBox = false;
    ll command;
    while (true)
    {
        cin >> command;
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
    vector<ll> inputVector = takeInput();
    solve(inputVector);
}