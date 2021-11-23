#include <stdio.h>
#include <math.h>

int main() {
	double input_[1010];
	double table[1010];
	int N, M, i;

	freopen("input.txt", "r", stdin);

	scanf("%d %d ", &N, &M);
	for (i = 0; i < N; i++)
		scanf("%lf ", &input_[i]);


	double total = 0.0;
	double min = 9999999999999;

	for (int m = M; m <= N; m++) {
		for (i = m - 1; i < N; i++) {
			double ave = 0.0;
			total = 0.0;
			for (int j = 0; j < m; j++)
				ave += input_[i - j];
			ave /= m;
			for (int j = 0; j < m; j++)
				total += pow(input_[i - j] - ave, 2);
			table[i] = sqrt(total / m);
		}



		for (i = M - 1; i < N; i++) {
			if (min > table[i])
				min = table[i];
		}
	}
	printf("%.11f", (min));

	return 0;
}