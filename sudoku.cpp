#include <iostream>

using namespace std;

// For checking whether a given value is already in the box
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

// For checking whether a given value is only in one of the "o" array of elements in the given box
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

// For filling the value k in a particular element of a given box.
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

// For checking if a value 'val' can occur at x, y on the basis of horizontal, vertical and box condition
int is_valid(int a[][10], int x, int y, int val) {
	int i, j, sum = 0, p = (x - 1) / 3, q = (y - 1) / 3, b, c;

	// Horizontal
	for (i = 1; i < 10; i++) {
		if (a[x][i] == val)
			sum++;
	}

	if (sum != 1)
		return 0;

	sum = 0;
	
	// Vertical
	for (i = 1; i < 10; i++) {
		if (a[i][y] == val)
			sum++;
	}

	if (sum != 1)
		return 0;

	sum = 0;
	
	// Box
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (i == p && j == q)
				return box_valid(a, p * 3 + 1, p * 3 + 4, q * 3 + 1, q * 3 + 4,
						val);

		}
	}

}

// Recursive Brute Force
void put(int a[][10], int x, int y) {
	int i, j;
	
	// If row no. > 9, bottom out.
	if (x > 9) {
		cout << "\nSolved Sudoku\n\n";

		for (i = 1; i < 10; i++) {
			for (j = 1; j < 10; j++)
				cout << a[i][j] << " ";

			cout << "\n";
		}
	}

	// If the cell is already filled, move on.
	else if (a[x][y] != 0) {
		if (y < 9)
			put(a, x, y + 1);
		else
			put(a, x + 1, 1);
	}

	// Otherwise, iteratively put the value in the box if its valid
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
			l, m, f = 0, g, b[10], var, K, var1, var2;

	cout << "\n"
			<< "Enter the sudoku to be solved. Enter the blank spaces as 0"
			<< "\n\n";

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++)
			cin >> a[i][j];
	}

	start:

	// Initialising the "o" matrix. Stores the possible numbers for each cell.
	for (c = 1; c < 10; c++) {
		for (d = 1; d < 10; d++) {
			for (e = 1; e < 10; e++)
				o[c][d][e] = 0;
		}
	}

	// Filling the "o" matrix by using is_valid(). is_valid() checks whether that number can be added there by horizontal, vertical and box condition
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

	// If there is only one possibility in a cell, then fill it. (Unit propogation)
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

	// If in the entire row, only the given particular cell has the unique value as one of the possibility, then fill it
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

	// If in the entire column, only the given particular cell has the unique value as one of the possibility, then fill it
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

	// If in the entire box, only the given particular cell has the unique value as one of the possibility, then fill it
	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {

			p = (i - 1) / 3;
			q = (j - 1) / 3;

			for (l = 0; l < 3; l++) {
				for (m = 0; m < 3; m++) {
					if (l == p && m == q) {
						for (k = 1; k < 10; k++) {
							if (check_box(o, p * 3 + 1, p * 3 + 4, q * 3 + 1, q
									* 3 + 4, k)) {
								fill_k(a, o, p * 3 + 1, p * 3 + 4, q * 3 + 1, q
										* 3 + 4, k);
								goto start;
							}
						}
					}
				}
			}

		}
	}

	// After filling the obvious stuff by following all the rules, now applying brute force to fill the remaining positions.
	put(a, 1, 1);

	return 0;

}

