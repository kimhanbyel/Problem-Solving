#include <iostream>
#include <queue>
using namespace std;

int w, h;
int start_x=0, start_y=0, to_x=-1, to_y=-1, max_move=-1, savex, savey;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
char arr[50][50]={};

void where(int a, int b){
	if(arr[a][b] != 'L')
		return;
	
	queue<pair<int, int> > q;
	bool check[50][50]={};
	int move_[50][50]={};
	int nx=0, ny=0;
	
	q.push(make_pair(a, b));
	check[a][b] = true;
	move_[a][b] = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		savex = x, savey = y;
		
		if(x!=a && y!=b){
			if(move_[x][y] > move_[x+1][y] && move_[x+1][y]>0){
				move_[x][y] = move_[x+1][y]+1;
			}
			if(move_[x][y] > move_[x-1][y] && move_[x-1][y]>0){
				move_[x][y] = move_[x-1][y]+1;
			}
			if(move_[x][y] > move_[x][y+1] && move_[x][y+1]>0){
				move_[x][y] = move_[x][y+1]+1;
			}
			if(move_[x][y] > move_[x][y-1] && move_[x][y-1]>0){
				move_[x][y] = move_[x][y-1]+1;
			}
		}
		
//		cout << q.front().first << " " << q.front().second << " " << move_[x][y] << '\n';
		
		q.pop();
		for(int i=0; i<4; i++){
			nx = x + dx[i];
			ny = y + dy[i];
		
			if(nx<0 || ny<0 || nx>=w || ny>=h) continue;
			else if(arr[nx][ny] == 'W' || check[nx][ny]) continue;
			else{
				q.push(make_pair(nx, ny));
				check[nx][ny] = true;
				for(int i=0; i<w; i++){
					for(int j=0; j<h; j++){
						if(i == a && j == b)
							cout << "S";
						else if(i == nx && j == ny)
							cout  << move_[i][j];
						else if(i == to_x && j == to_y)
							cout << "X";
						else
							cout << arr[i][j];
					}
					cout << '\n';
				}	cout << '\n';
				
			}
		}
	}
	
//	cout << start_x << " " << start_y << " " << to_x << " " << to_y << "\n";
//		for(int i=0; i<w; i++){
//			for(int j=0; j<h; j++){
//				if(i == a && j == b)
//					cout << "S";
//				else if(i == to_x && j == to_y)
//					cout << "X";
//				else
//					cout << arr[i][j];
//			}
//			cout << '\n';
//		}	cout << '\n';
		
	if(move_[a][b] > max_move){
		max_move = move_[a][b];
		start_x = a;
		start_y = b;
		to_x = savex;
		to_y = savey;
	}
}

int bfs(){
	cout << start_x << " " << start_y << " " << to_x << " " << to_y << "\n";
		for(int i=0; i<w; i++){
			for(int j=0; j<h; j++){
				if(i == start_x && j == start_y)
					cout << "S";
				else if(i == to_x && j == to_y)
					cout << "X";
				else
					cout << arr[i][j];
			}
			cout << '\n';
		}	cout << '\n';
		
	queue<pair<int, int> > q;
	bool check[50][50]={};
	int move_=0;
	
	q.push(make_pair(start_x, start_y));
	check[start_x][start_y] = true;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		move_++;
		
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
			if(arr[nx][ny] != 'L' || check[nx][ny]) continue;
			if(nx == to_x && ny == to_y) return move_;
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
		}
	}
}

int main(){
	cin >> w >> h;
	
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			cin >> arr[i][j];
		}
	}
				
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			where(i, j);
		}
	}
	
	cout << bfs();
}
