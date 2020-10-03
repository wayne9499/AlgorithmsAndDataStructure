#include <iostream>
#include <vector>
#define boost() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
using namespace std;
bool isSubsetSum_dp(const vector<int>& arr, int n, int sum) {
    bool t[n+1][sum+1];
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < sum+1; j++) {
            if (i == 0) t[i][j] = false;
            if (j == 0) t[i][j] = true;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (arr[i-1] <= j) {
                t[i][j] = (t[i-1][j - arr[i-1]] || t[i-1][j]);
            } else t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}
int main() {
    boost();
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum = 9;
    cout << isSubsetSum_dp(arr, n, sum);
    return 0;
}