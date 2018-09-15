#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {    
    return (n <= 1) ? 1 : n * factorial(n-1);
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n; cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = factorial(n);
    fout << result << "\n";
    fout.close();

    return 0;
}
