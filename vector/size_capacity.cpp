// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() // It initilises at zero then the capacity is the maximum size untill reallocation needs to take place which is 
         << " capacity: " << vec.capacity() << endl; //where the capacity then doubles in size after each reallocation

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}
