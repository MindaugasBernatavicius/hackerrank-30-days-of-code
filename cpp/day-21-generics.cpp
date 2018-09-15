#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
*    Name: printArray
*    Print each element of the generic vector on a new line. Do not return anything.
*    @param A generic vector
**/

// Write your code here
// TODO :: You need two parameters for a function
// that accepts a generic vector, the second argument
// is the "allocator", more information on SO:
// https://stackoverflow.com/questions/19094340/stdvector-as-a-template-function-argument
template<typename T>
void printArray(vector<T> &v) {
    for (auto i = v.begin(); i != v.end(); ++i)
        std::cout << *i << endl;
}

int main() {
	int n;
	
	cin >> n;
	vector<int> int_vector(n);
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		int_vector[i] = value;
	}
	
	cin >> n;
	vector<string> string_vector(n);
	for (int i = 0; i < n; i++) {
		string value;
		cin >> value;
		string_vector[i] = value;
	}

	printArray<int>(int_vector);
	printArray<string>(string_vector);

	return 0;
}
