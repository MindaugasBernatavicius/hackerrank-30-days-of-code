#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);
        for (int j = 0; j < 6; j++)
            cin >> arr[i][j];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // vector<vector<int>>::iterator row;
    // vector<int>::iterator col;
    // for (row = arr.begin(); row != arr.end(); row++) {
    //     for (col = row->begin(); col != row->end(); col++){
    //         cout << *col << ' ';
    //     }
    //     cout << endl;
    // }
    
    // // print all the sandclocks
    // for (int i = 0; i < arr.size() - 2; ++i){
    //     for(int j = 0; j < arr[i].size() - 2; ++j){
    //         cout << arr[i][j] << arr[i][j + 1] << arr[i][j + 2] << endl;
    //         cout << ' ' << arr[i + 1][j + 1] << endl;
    //         cout << arr[i + 2][j] << arr[i + 2][j + 1] << arr[i + 2][j + 2] << endl;
    //         cout << endl;
    //     }
    // }
    
    int max = numeric_limits<int>::min(),
        sandClockTotal = numeric_limits<int>::min(),
        top = 0, middle = 0, bottom = 0;
    
    for (int i = 0; i < arr.size()-2; ++i){
        for(int j = 0; j < arr[i].size()-2; ++j){
            top = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            middle = arr[i+1][j+1];
            bottom = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            sandClockTotal = top + middle + bottom;
            if(sandClockTotal > max) max = sandClockTotal;
        }
    }
    cout << max;
    
    return 0;
}
