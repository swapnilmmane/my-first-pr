#include <bits/stdc++.h>
int arr[100][100][100];
int max(int a, int b);
int lcs(char* X, char* Y, char* Z, int m, int n, int o){
	if (m == 0 || n == 0 || o == 0)
		return 0;
	if (arr[m - 1][n - 1][o - 1] != -1)
		return arr[m - 1][n - 1][o - 1];
	if (X[m - 1] == Y[n - 1] and Y[n - 1] == Z[o - 1]) {
		arr[m - 1][n - 1][o - 1] = 1 + lcs(X, Y, Z, m - 1,
											n - 1, o - 1);
		return arr[m - 1][n - 1][o - 1];
	}
	else {
		arr[m - 1][n - 1][o - 1] =
							max(lcs(X, Y, Z, m, n - 1, o),
								max(lcs(X, Y, Z, m - 1, n, o),
									lcs(X, Y, Z, m, n, o - 1)));
		return arr[m - 1][n - 1][o - 1];
	}
}
int max(int a, int b){
	return (a > b) ? a : b;
}
int main(){
	memset(arr, -1, sizeof(arr));
	char X[] = "Acro";
	char Y[] = "Acropolis";
	char Z[] = "Acropolis Institute";
	int m = strlen(X);
	int n = strlen(Y);
	int o = strlen(Z);
	printf("Length of LCS is %d", lcs(X, Y, Z, m, n, o));
	return 0;
}
