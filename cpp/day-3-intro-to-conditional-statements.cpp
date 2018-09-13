#include <bits/stdc++.h>

using namespace std;

void IsNumerberWeird(int N)
{
    // If  is odd, print Weird
    if(N % 2 != 0)
        cout << "Weird" << endl;
    
    // If  is even ...
    else if(N % 2 == 0)
    {
        // ... and in the inclusive range of 2 to 5, print Not Weird
        if(N >= 2 && N <= 5)
            cout << "Not Weird" << endl;
        
        // ... and in the inclusive range of 6 to 20, print Weird
        if(N >= 6 && N <= 20)
            cout << "Weird" << endl;
        
        // ... and greater than 20, print Not Weird
        if(N > 20)
            cout << "Not Weird" << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    IsNumerberWeird(N);
    return 0;
}
