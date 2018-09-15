#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

// avoid name collision w sstream::swap 
namespace S {
    template<typename T>
    void swap(T &a, T &b)
    {
        T t = a;
        a = b;
        b = t;
    }
}

using namespace std;
using namespace S;

int bubbleSort(vector<int> &v)
{
    int totalSwaps = 0;
    for (int i = 0; i < v.size(); i++) {
        // Track number of elements swapped during a single array traversal
        int numberOfSwaps = 0;

        for (int j = 0; j < v.size() - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (v[j] > v[j + 1]) {
                S::swap(v[j], v[j + 1]);
                numberOfSwaps++;
            }
        }

        totalSwaps += numberOfSwaps;
        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0)
            break;
    }
    
    return totalSwaps;
}

int main()
{
    int n; cin >> n; cin.ignore();
    
    string nums_string;
    getline(cin, nums_string);
    stringstream iss(nums_string);
    
    vector<int> v; int temp;
    while(iss >> temp)
      v.push_back(temp);
    
    int totalSwaps = bubbleSort(v);
    
    cout << "Array is sorted in " << totalSwaps << " swaps." << endl;
    cout << "First Element: " << v.front() << endl;
    cout << "Last Element: " << v.back() << endl;

    return 0;
}
