#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    
    // Declare second integer, double, and String variables.
    int my_i;
    double my_d;
    string my_s;

    // Read and save an integer, double, and String to your variables.
    cin >> my_i;
    cin >> my_d;
    cin.ignore();
    getline(cin, my_s);

    // Print the sum of both integer variables on a new line.
    cout << i + my_i << endl;
    
    // Print the sum of the double variables on a new line.
    cout << std::setprecision(1) << std::fixed << d + my_d << endl;

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << s << my_s << endl;
    
    return 0;
}
