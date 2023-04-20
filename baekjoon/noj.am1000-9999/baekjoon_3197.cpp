#include <iostream>
#include <queue>
using namespace std;

int r, c;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int visited[1500][1500];
char arr[1500][1500];
pair<int,int> pos;
queue<pair<int,int>> q, bq, wq;

int bfs(){
	int days = 0; // 얼음이 다 녹을 때까지 녹는 시간
	while(1){	// 백조가 만날때 까지 계속 반복됌.
		queue<pair<int,int>> nxbq, nxwq;	// 다음 bq과 wq를 따로따로 해야함
		while(!bq.empty()){
			int x = bq.front().first;		// 다음 위치 x
			int y = bq.front().second;		// 다음 위치 y
			
			bq.pop();						// pop해서 다음 위치 준비
//			cout << x << " " << y << "\n";	// bq를 출력하여 확인
			if(arr[x][y]=='L') return days;	// days를 리턴함 
			for(int i=0; i<4; i++){			// 근처 위아래양옆 확인하기 위한 인덱스
				int nx = x + dx[i];			// nx는 다음 x (Next X)
				int ny = y + dy[i];			// ny는 다음 y (Next Y)
				
				// 다음 위치가 0미만이거나 호수 사이즈를 벗어나면 continue하여 다음
				// 근처를 확인함, 이미 방문했어도 continue한다.
				if(nx<0 || ny<0 || nx>=r || ny>=c || visited[nx][ny]) continue;
				
				// 나머지 들은 방문하지 않았기에, 방문처리를 하고
				// arr가 'X'이라면 현재 지금 가지 못하기에 다음 bq에서 처리해야한다.
				// 그러기 위해 nxbq에 값을 넣는다. 그게 아니라면 bq에 푸쉬해서 bfs를 한다
				visited[nx][ny]++;
				if(arr[nx][ny]=='X') nxbq.push({nx, ny}); 
				else				 bq.push({nx, ny});
			}
		}	bq = nxbq; 					// 다음 bq(nxbq)를 bq에 집어넣는다.
		days++; 						// 백조가 만나지 못했기에 days를 추가한다
		while(!wq.empty()){				// wq는 물(백조)의 위치만 취급한다. 
			int x = wq.front().first;
			int y = wq.front().second;
			
			wq.pop();
//			cout << x << " " << y << "\n"; // wq를 출력하여 확인
			for(int i=0; i<4; i++){	
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				// 방문을 확인할 필요는 없다. 어짜피 사라지기 때문이다.
				// 근처 값이 얼음이 아니라도 continue한다.
				if(nx<0 || ny<0 || nx>=r || ny>=c || arr[nx][ny]!='X') continue;
				arr[nx][ny]='.';	// 녹여서 물이된다.
				nxwq.push({nx, ny});// 바로 다음 물이 녹으면 안되기에 nxwq에 넣는다.
			}
		}	wq = nxwq; // 다음 wq(nxwq)를 wq에 집어넣는다.
	}
}
int main(){
	// 입력들 L은 백조, bq시작점으로 push함
	// X는 얼음, 백조는 물에서만 존재할 수 있기에 '.'과 'L'을 물에 존재하는 것으로 친다.
	cin >> r >> c;
	for(int i=0; i<r; i++)	
		for(int j=0; j<c; j++){
			cin >> arr[i][j];
			if(arr[i][j]=='L') pos = {i, j};  
			if(arr[i][j]!='X') wq.push({i, j});
		}
	
	// 마지막 백조의 위치를 저장 후 다른 백조를 만나기 위해 .으로 변경
	int a = pos.first;
	int b = pos.second;
	arr[a][b] = '.';
	bq.push({a, b});
	visited[a][b]++;
	
	// 첫번재 백조 위치 삭제 후 BFS 실행
	cout << bfs();
}