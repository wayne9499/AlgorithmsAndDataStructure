#include <iostream>
#include <cstring>
#define boost() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
using namespace std;
// int count(0);    // to count recursive calls
int min(int x, int y, int z) {
    return min(min(x, y), z);
}
int t[101][101];
int solve(const string& s1, const string& s2, int m, int n) {
    // count++;
    // if first string is empty, the only option is to insert all chars from s2 i.e. of len n
    if (m == 0)
        return n;
    // if second string is empty, the only option is to remove all characters of first string i.e. of len m
    if (n == 0)
        return m;
    // if (t[m][n] != -1) {
    //     return t[m][n];
    // }
    if (s1[m - 1] == s2[n - 1])
        return t[m][n] = solve(s1, s2, m - 1, n - 1);
    else return t[m][n] = 1 + min(
            solve(s1, s2, m, n - 1),    // insert
            solve(s1, s2, m - 1, n),    // remove
            solve(s1, s2, m - 1, n - 1) // replace
        );
}
int main() {
    boost();
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    memset(&t, -1, sizeof(t));
    cout << solve(s1, s2, s1.length(), s2.length());
    // cout << "\nTotal number of recursive calls " << count;
    return 0;
}