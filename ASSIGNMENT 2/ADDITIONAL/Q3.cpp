#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool res(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
int main()
{
    string s1, s2;
    cout << "Enterfirst string: ";
    cin >> s1;
    cout << "Entersecond string: ";
    cin >> s2;
    if (res(s1, s2))
        cout << "Anagrams." << endl;
    else
        cout << "Not Anagrams." << endl;
    return 0;
}
