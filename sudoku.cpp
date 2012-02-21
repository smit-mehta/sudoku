#include <iostream>

using namespace std;

int box_valid(int a[][10], int u_i, int l_i, int u_j, int l_j, int val) {
	int i, j, sum = 0;

	for (i = u_i; i < l_i; i++) {
		for (j = u_j; j < l_j; j++) {
			if (a[i][j] == val)
				sum++;
		}
	}

	if (sum == 1)
		return 1;
	else
		return 0;
}

int check_box(int o[][10][10], int u_i, int l_i, int u_j, int l_j, int val) {
	int i, j, f = 0;

	for (i = u_i; i < l_i; i++) {
		for (j = u_j; j < l_j; j++) {
			if (o[i][j][val] == val)
				f++;
		}
	}

	if (f == 1)
		return 1;
	else
		return 0;

}

int fill_k(int a[][10], int o[][10][10], int u_i, int l_i, int u_j, int l_j,
		int val) {
	int i, j;

	for (i = u_i; i < l_i; i++) {
		for (j = u_j; j < l_j; j++) {
			if (o[i][j][val] == val) {
				a[i][j] = val;
				return 0;
			}
		}
	}
}

int is_valid(int a[][10], int x, int y, int val) {
	int i, j, sum = 0, p = (x - 1) / 3, q = (y - 1) / 3;

	for (i = 1; i < 10; i++) {
		if (a[x][i] == val)
			sum++;
	}

	if (sum != 1)
		return 0;

	sum = 0;

	for (i = 1; i < 10; i++) {
		if (a[i][y] == val)
			sum++;
	}

	if (sum != 1)
		return 0;

	sum = 0;

	switch (p) {
	case 0:
		if (q == 0)
			return box_valid(a, 1, 4, 1, 4, val);
		else if (q == 1)
			return box_valid(a, 1, 4, 4, 7, val);
		else
			return box_valid(a, 1, 4, 7, 10, val);
		break;

	case 1:
		if (q == 0)
			return box_valid(a, 4, 7, 1, 4, val);
		else if (q == 1)
			return box_valid(a, 4, 7, 4, 7, val);
		else
			return box_valid(a, 4, 7, 7, 10, val);
		break;

	case 2:
		if (q == 0)
			return box_valid(a, 7, 10, 1, 4, val);
		else if (q == 1)
			return box_valid(a, 7, 10, 4, 7, val);
		else
			return box_valid(a, 7, 10, 7, 10, val);
		break;

	}

}

void put(int a[][10], int x, int y) {
	int i, j;

	if (x > 9) {
		cout << "\nSolved Sudoku\n\n";

		for (i = 1; i < 10; i++) {
			for (j = 1; j < 10; j++)
				cout << a[i][j] << " ";

			cout << "\n";
		}
	}

	else if (a[x][y] != 0) {
		if (y < 9)
			put(a, x, y + 1);
		else
			put(a, x + 1, 1);
	}

	else {
		for (i = 1; i < 10; i++) {
			a[x][y] = i;

			if (is_valid(a, x, y, i)) {
				if (y < 9)
					put(a, x, y + 1);
				else
					put(a, x + 1, 1);
			}

			a[x][y] = 0;
		}
	}
}

int main() {

	int a[10][10], i, h = 0, n = 0, y, j, k, x, p, q, o[10][10][10], c, d, e,
			f = 0, g, b[10], var, K, var1, var2;

	cout << "\n"
			<< "Enter the sudoku to be solved. Enter the blank spaces as 0"
			<< "\n\n";

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++)
			cin >> a[i][j];
	}

	start:

	for (c = 1; c < 10; c++) {
		for (d = 1; d < 10; d++) {
			for (e = 1; e < 10; e++)
				o[c][d][e] = 0;
		}
	}

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {

			if (a[i][j] == 0) {

				for (k = 1; k < 10; k++) {
					a[i][j] = k;

					if (is_valid(a, i, j, k))
						o[i][j][k] = k;

				}
				a[i][j] = 0;

			}
		}
	}

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			if (a[i][j] == 0) {
				n = 0;
				for (x = 1; x < 10; x++) {

					if (o[i][j][x] != 0) {
						h = x;
						n++;
					}
				}

				if (n == 1) {
					a[i][j] = h;

					goto start;
				}

			}
		}
	}

	for (i = 1; i < 10; i++) {
		for (k = 1; k < 10; k++) {
			f = 0;
			for (j = 1; j < 10; j++) {
				if (o[i][j][k] == k) {
					f++;
					var = j;
					K = k;
				}
			}

			if (f == 1) {
				a[i][var] = K;
				goto start;
			}
		}
	}

	for (j = 1; j < 10; j++) {
		for (k = 1; k < 10; k++) {
			f = 0;
			for (i = 1; i < 10; i++) {
				if (o[i][j][k] == k) {
					f++;
					var = i, K = k;
				}
			}

			if (f == 1) {
				a[var][j] = K;
				goto start;
			}
		}
	}

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {

			p = (i - 1) / 3;
			q = (j - 1) / 3;

			switch (p) {
			case 0:
				if (q == 0) {
					for (k = 1; k < 10; k++) {
						if (check_box(o, 1, 4, 1, 4, k)) {
							fill_k(a, o, 1, 4, 1, 4, k);
							goto start;
						}
					}
				}

				else if (q == 1) {
					for (k = 1; k < 10; k++) {
						if (check_box(o, 1, 4, 4, 7, k)) {
							fill_k(a, o, 1, 4, 4, 7, k);
							goto start;
						}
					}
				}

				else {
					for (k = 1; k < 10; k++) {
						if (check_box(o, 1, 4, 7, 10, k)) {
							fill_k(a, o, 1, 4, 7, 10, k);
							goto start;
						}
					}
				}

				break;
			case 1:
				if (q == 0) {
					for (k = 1; k < 10; k++) {
						if (check_box(o, 4, 7, 1, 4, k)) {
							fill_k(a, o, 4, 7, 1, 4, k);
							goto start;
						}
					}
				}

				else if (q == 1) {
					for (k = 1; k < 10; k++) {
						if (check_box(o, 4, 7, 4, 7, k)) {
							fill_k(a, o, 4, 7, 4, 7, k);
							goto start;
						}
					}
				}

				else {
					for (k = 1; k < 10; k++) {
						if (check_box(o, 4, 7, 7, 10, k)) {
							fill_k(a, o, 4, 7, 7, 10, k);
							goto start;
						}
					}
				}

				break;
			case 2:
				if (q == 0) {
					for (k = 1; k < 10; k++) {
						if (check_box(o, 7, 10, 1, 4, k)) {
							fill_k(a, o, 7, 10, 1, 4, k);
							goto start;
						}
					}
				}

				else if (q == 1) {
					for (k = 1; k < 10; k++) {
						if (check_box(o, 7, 10, 4, 7, k)) {
							fill_k(a, o, 7, 10, 4, 7, k);
							goto start;
						}
					}
				}

				else {
					for (k = 1; k < 10; k++) {
						if (check_box(o, 7, 10, 7, 10, k)) {
							fill_k(a, o, 7, 10, 7, 10, k);
							goto start;
						}
					}
				}

				break;

			}
		}
	}

	put(a, 1, 1);

	return 0;

}

