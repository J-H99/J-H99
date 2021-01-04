// You may use include as below.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
	int j = -1, i = 0;
	int num = 1;
	int limit = n;
	int delta = 1;
	int matrix = n * n;
	int** arr = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*n);
	}
	while (1) {
		for (int p = 0; p < limit; p++) {
			j += delta;
			arr[i][j] = num;
			num++;
		}
		limit--;
		if (limit < 0) {
			break;
		}
		for (int p = 0; p < limit; p++) {
			i += delta;
			arr[i][j] = num;
			num++;
		}
		delta *= -1;
	}
	int answer = 0;
	for (int p = 0; p < n; p++) {
		answer += arr[p][p];
	}
	return answer;
}

// The following is main function to output testcase.
int main() {
	int n1 = 3;
	int ret1 = solution(n1);

	// Press Run button to receive output. 
	printf("Solution: return value of the function is %d .\n", ret1);

	int n2 = 2;
	int ret2 = solution(n2);

	// Press Run button to receive output. 
	printf("Solution: return value of the function is %d .\n", ret2);
}
