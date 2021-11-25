#include <iostream>
#include <vector>

using namespace std;
vector<int> vals;
int getMax(){
    int max = 0;
    for(int i=0;i<3;++i){
        if (vals[i] > max){
            max = vals[i];
        }
    }
    return max;
}

int main(){
   int num1,num2,num3;
   cout<<"Enter three nums " << endl;
   cin>>num1;
   cin>>num2;
   cin>>num3;
   vals.push_back(num1);
   vals.push_back(num2);
   vals.push_back(num3);
   cout << getMax() <<endl;

}   

