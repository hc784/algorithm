#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <tuple>

using namespace std;

#define MAX 987654321
int N, W[16][16], cache[16][1 << 16], start_node;

int dfs(int cur, int vis) {
    // 1. 베이스 케이스(Base Case) 수정
    // 이제 W[cur][start_node]가 0인 경우는 없으며, 경로가 없다면 MAX 값을 가집니다.
    // 따라서 바로 W[cur][start_node]를 반환하면 됩니다.
    if (vis == (1 << N) - 1) {
        return W[cur][start_node];
    }

    int& ret = cache[cur][vis];
    if (ret != -1) {
        return ret;
    }

    ret = MAX;
    for (int i = 0; i < N; i++) {
        // 2. 방문 여부 확인 로직 수정
        // main에서 W[cur][i]가 0인 경로를 미리 MAX로 처리했으므로,
        // 여기서 W[cur][i] != 0 체크가 더 이상 필요 없습니다.
        if (!(vis & (1 << i))) {
            int next_cost = dfs(i, vis | (1 << i));

            // next_cost나 W[cur][i]가 MAX(INF)가 아닌 유효한 경로일 때만 갱신
            if (next_cost != MAX && W[cur][i] != MAX) {
                ret = min(ret, next_cost + W[cur][i]);
            }
        }
    }
    return ret;
}

int main() {
    // 입출력 최적화 (필요 시 사용)
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &W[i][j]);
        }
    }

    // ===================================
    // 요청하신 사전 처리 방식 적용
    // ===================================
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 자기 자신으로 가는 경로가 아니고, 경로 비용이 0이면 (즉, 길이 없으면)
            // MAX 값으로 변경하여 갈 수 없는 경로임을 명시합니다.
            if (i != j && W[i][j] == 0) {
                W[i][j] = MAX;
            }
        }
    }

    // 0번 도시에서 출발하는 경우로 고정
    start_node = 0;
    memset(cache, -1, sizeof(cache));

    int result = dfs(start_node, 1 << start_node);

    printf("%d", result);

    return 0;
}

/*
* dfs?
* 비용 기록.
* cache[지나온 도시][현재 비용]
* 
* 16개 비트 마스크
* 1010101101101010101
1 << 0 = 1
1 << 1= 10
1 << 16 = 

현재는 첫시작 도시로 돌아오지 않음. 모든 도시를 돌기는 하는데.
시작 경로로 돌아오는 알고리즘?
마지막에 검사할때 현재 경로가 시작경로로 갈 수 없다면 cache에 -2를 저장하고,
return 값을 실패 플래그를 전달?

시작위치로 돌아올 수 있는 경로?
만약 vis가 전부 1인데, 시작 위치로 갈 수 있다면.
성공 플래그를 주고, 현재 비용을 cache에 기록한다.

vis가 전부 1인데, 시작 위치로 갈 수 없다면 
실패 플래그, 비용은 갈 수 없는 비용 무한으로 갱신.

성공 플래그와 실패 플래그 기록 방법.
실패시 그냥 max 값 반환하면 자동으로 해당 경로는 제외된다.
max 값 + 이전 비용 값이 cache에 기록되기 때문에.

성공 시 0 반환하면 해당 비용이 기록된다.

시작 위치로 갈 수 있는지 확인하는 방법.
vis가 전부 1이면 마지막 도시.
마지막 도시의 비용에서 w[cur][첫시작] != 0 이라면 시작 위치로 돌아 갈 수 있다.
만족하면 w[cur][첫시작]를 반환. 아니면 max 반환.


시작 위치는 정해져 있지 않음.
시작 위치가 변경된다면 cache 값을 초기화하고, 시작 위치를 변경할 때마다.
최솟값을 기록. 그 중에서 가장 작은 값이 min값.

시작 위치로 갈 수 있는지 확인해야함.
시작위치를 전역변수로 기록.

*/