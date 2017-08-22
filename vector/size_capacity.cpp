// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() //Number of elliments within the vector
         << " capacity: " << vec.capacity() << endl;	//Capacity available maximum size for vector memory allocated
		 //When size exceeds capacity the capacity is doubled to accomadate vector inputs

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}
