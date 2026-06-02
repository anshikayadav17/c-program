#include <iostream>
#include <map>
using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> freq;

    for (char c : s)
        freq[c]++;

    for (auto x : freq)
        cout << x.first << " : " << x.second << endl;
}
