#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

bool checkBorder(int x, int y, int n) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool checkVisit(vector<vector<int>> map11, int n) {
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {
            if (map11[i][j] == 0) { return false; }

        }

    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r, c, d;
    vector<pair<int, int>> direc = { {-1,0},{1,0},{0,-1},{0,1} };
    cin >> n >> r >> c >> d;
    vector<vector<int>> map1(n + 3, vector<int>(n + 3));
    //시작 위치도 출력하기 추가.

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {
            cin >> map1[i][j];
        }

    }
    cout << r << " " << c << endl;
    int di2[4][4] = { {0,2,3,1},{1,3,2,0},{2,1,0,3},{3,0,1,2} };
    d = d - 1;
    map1[r][c] = 2;
    while (!checkVisit(map1, n)) {
        // 상하좌우 방문 안한 바다가 있는 경우.
        bool moveFlag = false;
        for (int i = 0; i < 4; i++) { // d에 따라 방향이 달라져야함.
            // d == 1 : 상 =  0이 처음.0 2 3 1
            // d == 2 : 하 = 1이 처음 1 3 2 0
            // d == 3 : 좌 = 2 1 0 3
            // d == 4 : 우 = 3 0 1 2
            int nextx = r + direc[di2[d][i]].first;
            int nexty = c + direc[di2[d][i]].second;
            if (checkBorder(nextx, nexty, n) && map1[nextx][nexty] == 0)
            { // 있으면 이동 후 다시 처음부터.
                // 할일 이동한 바다로 표시, r,c 변경, 출력하기.
                map1[nextx][nexty] = 2;
                cout << nextx << " " << nexty << endl;
                r = nextx;
                c = nexty;
                d = di2[d][i];
                //flag로 검증.
                moveFlag = true;
                break;
            }
        }
        // 방문 안한 바다 없는 경우
        if (!moveFlag) {
            // 가장 가까운 바다 탐색. bfs
            queue<pair<int, int>> pq;
            vector<vector<int>> visited(n + 2, vector<int>(n + 2, 999));
            pq.push({ r, c });
            visited[r][c] = 0;
            while (!pq.empty()) {
                int px = pq.front().first;
                int py = pq.front().second;
                pq.pop();
                for (int i = 0; i < 4; i++) { // 상하좌우 이동은 아무 순서나 해도 됨. 역추적 할 때 추적하기.
                    int nextx = px + direc[i].first;
                    int nexty = py + direc[i].second;

                    if (map1[nextx][nexty] != 1 && checkBorder(nextx, nexty, n) && visited[nextx][nexty] == 999) {
                        visited[nextx][nexty] = visited[px][py] + 1;
                        pq.push({ nextx,nexty });
                    } ////// 0817 할일 역추적 배열 만들고, 최단거리 기록하고, bfs 상하좌우로 이동하게 하기. bfs 완성하기.
                }
            }
            // 최단거리 테이블로 가장 가까운 바다 찾고, 역추적해서 경로 출력.
            // 최단거리 바다의 거리와 인덱스를 갱신. 최단거리가 겹치면 인덱스를 함께 저장. 최단거리가 갱신되면 인덱스 초기화 하고 넣기.
            int minval = 99999;
            vector<pair<int, int>> minidx;
            for (int i = 1; i <= n; i++) {

                for (int j = 1; j <= n; j++) {
                    if (map1[i][j] == 0) {
                        if (visited[i][j] < minval) {
                            minidx.clear();
                            minval = visited[i][j];
                            minidx.push_back({ i,j });
                        }
                        else if (visited[i][j] == minval) {
                            minidx.push_back({ i,j });
                        }
                    }
                }

            }
            int minx = 999, miny = 999;
            // 최단거리 중 행 번호가 가장 작고, 같으면 열 번호가 가장 작은것을 선택.
            for (auto pa : minidx) {
                if (pa.first < minx) {
                    minx = pa.first;
                    miny = pa.second;
                }
                else if (pa.first == minx && pa.second < miny) {

                    minx = pa.first;
                    miny = pa.second;
                }
            }


            //찾은 인덱스에서 시작 위치로 가는 경로 역추적 시작 위치는 r,c 변동없음.
            // 도착점에서 상하좌우 중 -1인 거리를 찾는다. 찾는 순서는 우 상 좌 하. 가장 먼저 찾아지는 곳으로 이동. 출력은 거꾸로 해야한다.
            // 우 상 좌 하 : 3 0 2 1
            int dir3[4] = { 3,0,2,1 };
            int dir4[4] = { 2,1,3,0 };
            //시작점으로 갈 때까지. 인덱스가 rc가 될 때까지.
            // 시작 인덱스는 minxy, 이 인덱스를 계속 옮겨서 rc로 도착해야한다.
            vector<pair<int, int>> inv;
            inv.push_back({ minx,miny });
            int firstflag = true;
            
            //1. mixy에서 r c로 가는 모든 경로를 찾기.
            //2. map2에 기록해서 rc에서 우선순위에 따라 선택.
            //3. 마지막 d 갱신.
            int saveminx = minx, saveminy = miny;
            vector<vector<int>> map2(n+2, vector<int>(n + 2,9999));
            map2[minx][miny] = visited[minx][miny];
            map2[r][c] = 0;
        /*    
                minx = saveminx; 
                miny = saveminy;
                while (!(minx == r && miny == c)) {
                for (int i = 0; i < 4; i++) {
                        int nextx = minx + direc[dir3[i]].first;
                        int nexty = miny + direc[dir3[i]].second;

                        if (checkBorder(nextx, nexty, n) && visited[nextx][nexty] == visited[minx][miny] - 1 && map1[nextx][nexty] != 1) {
                            minx = nextx;
                            miny = nexty;
                            map2[minx][miny] = 0;
                        }
                        else break;
                }
            }*/

            queue<pair<int,int>> q1;
            q1.push({ minx,miny });
            while (!q1.empty()) {
                int ax = q1.front().first;
                int ay = q1.front().second;
                q1.pop();
                for (int i = 0; i < 4; i++) {
                    int nextx = ax + direc[dir3[i]].first;
                    int nexty = ay + direc[dir3[i]].second;

                    if (checkBorder(nextx, nexty, n) && visited[nextx][nexty] == visited[ax][ay] - 1 && map1[nextx][nexty] != 1 && map2[nextx][nexty] == 9999) {

                        map2[nextx][nexty] = visited[nextx][nexty];
                        q1.push({ nextx,nexty });
                    }
                }
            }
            int lastx, lasty;
            while (!(saveminx == r && saveminy == c)) {
                for (int i = 0; i < 4; i++) {
                    int nextx = r + direc[dir4[i]].first;
                    int nexty = c + direc[dir4[i]].second;

                    if (checkBorder(nextx, nexty, n) && map2[nextx][nexty] == map2[r][c]+1) {
                        lastx = r;
                        lasty = c;
                        map2[r][c] = 9999;
                        r = nextx;
                        c = nexty;
                        break;
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
                //last 방향에서 savemix으로 가는 방향을 구하기.
                // 
                if (lastx + direc[i].first == saveminx && lasty + direc[i].second == saveminy) {
                    d = i;
                    //cout << "d:" << lastx<<lasty << endl;
                    break;
                }
            }

            //for (int i = inv.size() - 1; i >= 0; i--) {
            //    cout << inv[i].first << " " << inv[i].second << endl;
            //}
            cout << inv[0].first << " " << inv[0].second << endl;
            r = saveminx;
            c = saveminy;
            map1[r][c] = 2;

        }

    }


}
/*

최단거리 이동 경로 : 역추적 함수.
이 칸에 도달하는 이전 칸을 기록.
최단 거리로 해당칸에 도달하는 경우 같으면 우선순위에 따라 역추적을 갱신.
그럼 최단거리로 방문했다고, 이미 방문했다고 방문하지 않으면 안됨.
모든 경우를 찾아야한다.

최단거리의 칸은 bfs로 찾을 수 있다.

찾고 나서 역추적은 해당 칸에 도달하는 bfs를 다시 돌리기/
거리 테이블로 역추적이 가능한가/
거리는 최단거리로 갱신된다.
해당 칸에서 움직일 수 있는 -1 칸으로 우선순위에 따라
 시작지점으로 이동하면 역추적이 가능하다.
 */
