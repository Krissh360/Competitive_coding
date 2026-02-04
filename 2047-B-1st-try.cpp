#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        map <char, int> freq;
        for (char c : s) freq[c]++;

        char m = s[0];
        for (auto p : freq)
        {
            if (p.second > freq[m])
            {
                m = p.first;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] != m)
            {
                s[i] = m;
                break;
            }
            
            cout << s << endl;
        }

         return 0;
    }
}