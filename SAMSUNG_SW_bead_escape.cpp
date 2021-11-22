#include <stdio.h>
#include <stdlib.h>

int minimum_way = 0x7fffffff;
int N, M;
char map[11][11];
bool chk[11][11];


void printMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d", chk[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

void resetMap(int r_x, int r_y, int b_x, int b_y) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R' || map[i][j] == 'B')
				map[i][j] = '.';
		}
	}
	map[r_x][r_y] = 'R';
	map[b_x][b_y] = 'B';
}


int move_bead(int r_x, int r_y, int b_x, int b_y, int count, int way) {
	int buf[11][11] = { 0 };

	if (count >= minimum_way)
		return -1;
	if (chk[r_x][r_y] == 1) {
		return -1;
	}

	chk[r_x][r_y] = 1;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			buf[i][j] = map[i][j];
	}

	bool hole_chk = false, move_chk = false;

	for (int k = 0; k < 2; k++) {
		if (way == 1) {
			for (int j = M - 1; j > 0; j--) {
				for (int i = 0; i < N; i++) {
					if (map[i][j] == 'O' && map[i][j + 1] == 'R') {
						if (count < minimum_way)
							hole_chk = true;
						map[i][j + 1] = '.';
					}
					else if (map[i][j] == 'O' && map[i][j + 1] == 'B') {
						return -1;
					}
					else if (map[i][j] == '.' && (map[i][j + 1] == 'R' || map[i][j + 1] == 'B')) {
						map[i][j] = map[i][j + 1];
						map[i][j + 1] = '.';
						move_chk = true;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				r_x = i;
				r_y = j;
			}
			else if (map[i][j] == 'B') {
				b_x = i;
				b_y = j;
			}
		}
	}
	if (hole_chk)
		minimum_way = count;
	if (move_chk)
		move_bead(r_x, r_y, b_x, b_y, count + 1, 1);



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			map[i][j] = buf[i][j];
	}
	for (int k = 0; k < 2; k++) {
		for (int j = 0; j < M - 1; j++) {
			for (int i = 0; i < N; i++) {
				if (map[i][j] == 'O' && map[i][j - 1] == 'R') {
					if (count < minimum_way)
						hole_chk = true;
					map[i][j - 1] = '.';
				}
				else if (map[i][j] == 'O' && map[i][j - 1] == 'B') {
					return -1;
				} else if (map[i][j] == '.' && (map[i][j - 1] == 'R' || map[i][j - 1] == 'B')) {
					map[i][j] = map[i][j - 1];
					map[i][j - 1] = '.';
					move_chk = true;
				}
			}
		}
	}	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				r_x = i;
				r_y = j;
			}
			else if (map[i][j] == 'B') {
				b_x = i;
				b_y = j;
			}
		}
	}
	if (hole_chk)
		minimum_way = count;
	if (move_chk)
		move_bead(r_x, r_y, b_x, b_y, count + 1, 1);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			map[i][j] = buf[i][j];
	}
	for (int k = 0; k < 2; k++) {
		for (int i = N - 2; i > 0; i--) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'O' && map[i + 1][j] == 'R') {
					if (count < minimum_way)
						hole_chk = true;
					map[i + 1][j] = '.';
				}
				else if (map[i][j] == 'O' && map[i + 1][j] == 'B') {
					return -1;
				} else if (map[i][j] == '.' && (map[i + 1][j] == 'R' || map[i + 1][j] == 'B')) {
					map[i][j] = map[i + 1][j];
					map[i+1][j] = '.';
					move_chk = true;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				r_x = i;
				r_y = j;
			}
			else if (map[i][j] == 'B') {
				b_x = i;
				b_y = j;
			}
		}
	}
	if (hole_chk)
		minimum_way = count;
	if (move_chk)
		move_bead(r_x, r_y, b_x, b_y, count + 1, 1);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			map[i][j] = buf[i][j];
	}
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i < N - 1; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'O' && map[i - 1][j] == 'R') {
					if (count < minimum_way)
						hole_chk = true;
					map[i - 1][j] = '.';
				}
				else if (map[i][j] == 'O' && map[i - 1][j] == 'B') {
					return -1;
				} else if (map[i][j] == '.' && (map[i - 1][j] == 'R' || map[i - 1][j] == 'B')) {
					map[i][j] = map[i - 1][j];
					map[i-1][j] = '.';
					move_chk = true;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				r_x = i;
				r_y = j;
			}
			else if (map[i][j] == 'B') {
				b_x = i;
				b_y = j;
			}
		}
	}
	if (hole_chk)
		minimum_way = count;
	if (move_chk)
		move_bead(r_x, r_y, b_x, b_y, count + 1, 1);



	return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);


	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%c ", &map[i][j]);
	}




	int red_x = 0, red_y = 0, blue_x = 0, blue_y = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				red_x = i;
				red_y = j;
			}
			else if (map[i][j] == 'B') {
				blue_x = i;
				blue_y = j;
			}
		}
	}


	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++)
				chk[j][k] = 0;
		}
		move_bead(red_x, red_y, blue_x, blue_y, 1, i);
	}

	if (minimum_way == 0x7FFFFFFF)
		printf("-1");
	else
		printf("%d", minimum_way);

	return 0;
}