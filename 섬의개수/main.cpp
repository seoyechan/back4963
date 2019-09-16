#include <iostream>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


int nfiled[51][51];
int x, y;

typedef struct pos{
	int nx, ny;
};

int dirx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int diry[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int bfs()
{
	int nvisit[51][51] = { 0, };
	queue <pos> que;
	pos cur = { 0, 0 };
	pos nxt = { 0, 0 };
	int iland = 0;


	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			if (nfiled[i][j] && !nvisit[i][j]){
				iland++;
				que.push({ j, i });
				nvisit[i][j] = 1;

				while (!que.empty())
				{
					cur = que.front();
					que.pop();

					for (int d = 0; d < 8; d++){
						nxt.nx = cur.nx + dirx[d];
						nxt.ny = cur.ny + diry[d];

						if (nxt.nx < 0 || nxt.nx >= x || nxt.ny < 0 || nxt.ny >= y) continue;

						if (nfiled[nxt.ny][nxt.nx] && !nvisit[nxt.ny][nxt.nx]){
							nvisit[nxt.ny][nxt.nx] = 1;
							que.push(nxt);

						}
					}
				}
			}
		}
	}

	return iland;
}

int main()
{
	bool flag = true;
	queue <int> que_ret;
	while (flag)
	{
		cin >> x >> y;

		if (x == 0 && y == 0)	flag = false;
		else
		{
			for (int i = 0; i < y; i++){
				for (int j = 0; j < x; j++){
					cin >> nfiled[i][j];
				}
			}

			que_ret.push(bfs());
		}
	}

	while (!que_ret.empty()){
		cout << que_ret.front() << endl;
		que_ret.pop();
	}

	return 0;
}