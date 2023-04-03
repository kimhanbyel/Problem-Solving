// |이 코드는 BFS 알고리즘을 이용하여 물고기가 있는 바다에서 가장 먼 거리에 있는 물고기까지의 거리를 구하는 문제를 해결하는 코드입니다.
// |
// |좋은 점:
// |- BFS 알고리즘을 이용하여 문제를 해결하였습니다.
// |- 코드가 간결하고 가독성이 좋습니다.
// |- 변수명이 명확하게 지어져 있어 이해하기 쉽습니다.
// |
// |나쁜 점:
// |- 변수 선언과 초기화가 한 번에 이루어지지 않아 코드의 가독성이 떨어집니다.
// |- 배열의 크기가 상수로 고정되어 있어 유연성이 떨어집니다. (동적 할당을 이용하면 더 좋을 것입니다.)
#include <iostream> //입출력 헤더파일
#include <queue>	//큐 헤더파일
using namespace std;

int x, y, ans, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}; // x, y는 지도의 크기, ans는 정답, dx, dy는 상하좌우 이동을 위한 배열
char arr[50][50];											 // 지도 배열

void bfs(int a, int b) // BFS 함수
{
	queue<pair<int, int>> q; // 큐 생성
	int check[50][50] = {};	 // 방문 체크 배열

	q.push({a, b});	   // 시작점 큐에 삽입
	check[a][b] = 0;   // 시작점 방문 체크
	while (!q.empty()) // 큐가 빌 때까지 반복
	{
		int ox = q.front().first;  // 큐의 맨 앞 원소의 x좌표
		int oy = q.front().second; // 큐의 맨 앞 원소의 y좌표

		q.pop();					// 큐의 맨 앞 원소 제거
		if (check[ox][oy] > ans)	// 현재 위치까지의 거리가 기존 정답보다 크다면
			ans = check[ox][oy];	// 정답 갱신
		for (int i = 0; i < 4; i++) // 상하좌우 이동
		{
			int nx = ox + dx[i]; // 다음 위치의 x좌표
			int ny = oy + dy[i]; // 다음 위치의 y좌표

			if (nx < 0 || ny < 0 || nx >= x || ny >= y) // 지도 범위를 벗어나면
				continue;								// 다음 위치로 이동하지 않음
			if (arr[nx][ny] != 'L' || check[nx][ny])	// 다음 위치가 육지가 아니거나 이미 방문한 곳이면
				continue;								// 다음 위치로 이동하지 않음

			q.push({nx, ny});				   // 다음 위치 큐에 삽입
			check[nx][ny] = check[ox][oy] + 1; // 다음 위치 방문 체크 및 거리 갱신
			check[a][b] = 1;				   // 시작점 방문 체크
		}
	}
}
int main()
{
	cin >> x >> y;				// 지도의 크기 입력
	for (int i = 0; i < x; i++) // 지도 입력
		for (int j = 0; j < y; j++)
			cin >> arr[i][j];
	for (int i = 0; i < x; i++) // 모든 육지에서 BFS 실행
		for (int j = 0; j < y; j++)
			if (arr[i][j] == 'L')
				bfs(i, j);
	cout << ans; // 정답 출력
}