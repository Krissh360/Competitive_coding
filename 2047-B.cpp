#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
 
void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 1) {
        cout << s << "\n";
        return;
    }
 
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
 
    char most_freq_char = s[0];
    char least_freq_char = s[0];
    int max_count = -1;
    int min_count = n + 1;
 
    for (auto const& [ch, count] : freq) {
        if (count >= max_count) {
            max_count = count;
            most_freq_char = ch;
        }
        if (count <= min_count) {
            min_count = count;
            least_freq_char = ch;
        }
    }
 
    if (most_freq_char == least_freq_char && freq.size() > 1) {
        for (auto const& [ch, count] : freq) {
            if (ch != most_freq_char) {
                least_freq_char = ch;
                break;
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (s[i] == least_freq_char) {
            s[i] = most_freq_char;
            break;
        }
    }
 
    cout << s << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}