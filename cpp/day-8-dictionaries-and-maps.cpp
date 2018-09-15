#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    unsigned int n = 0;
    cin >> n;
    cin.ignore();
    
    unordered_map<string, string> phoneBook;
    string kv, firstname, phoneNumber;
    char pos;
    while(n)
    {
        getline(cin, kv);
        pos = kv.find_first_of(' ');
        firstname = kv.substr(0, pos),
        phoneNumber = kv.substr(pos+1);
        phoneBook.insert(make_pair<string, string>(string(firstname), string(phoneNumber)));
        --n;
    }
    
    // Loop for getting an processing the queries
    string q, prevq;
    unordered_map<string, string>::const_iterator got;

    while(getline(cin, q))
    {
        got = phoneBook.find(q);
        if(got == phoneBook.end())
            std::cout << "Not found" << endl;
        else
            std::cout << got->first << "=" << got->second << endl;
    }
    
    return 0;
}
