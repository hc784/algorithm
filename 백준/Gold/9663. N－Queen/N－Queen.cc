#include <iostream>
using namespace std;

int n;
int board[15][15];
bool chk[15];
bool chk2[27];
bool chk3[27];
int cnt = 0;
void queen(int q) {
    if (q == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (chk[i] || chk2[i + q] || chk3[i - q + n - 1]) continue;
        chk[i] = 1;
        chk2[i + q] = 1;
        chk3[i - q + n - 1] = 1;
        queen(q + 1);
        chk[i] = 0;
        chk2[i + q] = 0;
        chk3[i - q + n - 1] = 0;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    queen(0);
    cout << cnt;
}