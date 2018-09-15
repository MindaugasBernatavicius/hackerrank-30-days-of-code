#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void split(const string& s, char c, vector<string>& v)
{
   string::size_type i = 0;
   string::size_type j = s.find(c);

   while (j != string::npos){
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}

int calcFine(string& actualReturnDate, string& expectedReturnDate)
{    
    vector<string> actual;
    vector<string> expected;
    
    split(actualReturnDate, ' ', actual);
    split(expectedReturnDate, ' ', expected);
    
    int actualDay = stoi(actual[0]);
    int actualMonth = stoi(actual[1]);
    int actualYear = stoi(actual[2]);
    
    int expectedDay = stoi(expected[0]);
    int expectedMonth = stoi(expected[1]);
    int expectedYear = stoi(expected[2]);
    
    int penalty = 0;
    
    // if(actualYear > expectedYear){
    //     penalty += 10000;
    //     if(actualMonth > expectedMonth){
    //         penalty += (actualMonth - expectedMonth) * 500;
    //         if(actualDay > expectedDay){
    //             penalty += (actualDay - expectedDay) * 15;
    //         }
    //     } else if(actualMonth = expectedMonth){
    //         if(actualDay > expectedDay){
    //             penalty += (actualDay - expectedDay) * 15;
    //         }
    //     }
    // } else if(actualMonth > expectedMonth){
    //     penalty += (actualMonth - expectedMonth) * 500;
    //     if(actualDay > expectedDay){
    //         penalty += (actualDay - expectedDay) * 15;
    //     }
    // } else if(actualDay > expectedDay){
    //     penalty += (actualDay - expectedDay) * 15;
    // }

    if(actualYear > expectedYear){
        penalty += 10000;
    } else if(actualYear == expectedYear && actualMonth > expectedMonth){
        penalty += (actualMonth - expectedMonth) * 500;
    } else if(actualMonth == expectedMonth && actualDay > expectedDay){
        penalty += (actualDay - expectedDay) * 15;
    }
    
    return penalty;
}

int main()
{
    string actualReturnDate, expectedReturnDate;
    getline(cin, actualReturnDate);
    getline(cin, expectedReturnDate);
    
    cout << calcFine(actualReturnDate, expectedReturnDate) << endl;
    
    return 0;
}
