#include <iostream>
#include <cstdlib>
using namespace std;

const int cedge = 4;
int edge = cedge;

void fill(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		*(arr + i) = rand() % 90 + 10;
	}
}
void print(int* arr, int a) {
	for (int i = 0; i < a; ++i) {
		cout << *(arr + i) << ' ';
	}
	cout << '\n';
}
void print(int* arr, int a, int b) {
	for (int i = 0; i < a * a; ++i) {
		if (i % b == 0) cout << '\n';
		cout << *(arr + i) << ' ';
	}
	cout << '\n';
}

void print(int* arr, int a, int b, int c) {
	for (int i = 0; i < a * b * c; ++i) {
		if (i % b == 0) cout << '\n';
		if (i % (a * b) == 0) cout << '\n';
		cout << *(arr + i) << ' ';
	}
	cout << '\n';
}

int min(int* arr, int n) {
	int res = arr[0];
	for (int i = 0; i < n; ++i) {
		if (*(arr + i) < res) {
			res = *(arr + i);
		}
	}
	return res;
}

int max(int* arr, int n) {
	int res = arr[0];
	for (int i = 0; i < n; ++i) {
		if (*(arr + i) > res) {
			res = *(arr + i);
		}
	}
	return res;
}

int median(int* arr, int size) {
	int temp;
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (*(arr + j) > *(arr + j + 1)) {
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}

	if (size % 2 == 1) return *(arr + (size / 2));
	else return (*(arr + (size / 2 - 1)) + *(arr + (size / 2))) / 2;
}

int main() {
	int arr1[cedge]{};
	int arr2[cedge][cedge]{};
	int arr3[cedge][cedge][cedge]{};
	fill(arr1, edge);
	fill(*arr2, edge * edge);
	fill(**arr3, edge * edge * edge);
	print(arr1, edge);
	cout << '\n' << "min: " << min(arr1, edge) << '\n';
	cout << "max: " << max(arr1, edge) << '\n';
	cout << "median: " << median(arr1, edge) << '\n';
	print(*arr2, edge, edge);
	cout << '\n' << "min: " << min(*arr2, edge*edge);
	cout << '\n' << "max: " << max(*arr2, edge * edge);
	cout << '\n' << "median: " << median(*arr2, edge * edge);
	print(**arr3, edge, edge, edge);
	cout << '\n' << "min: " << min(**arr3, edge * edge * edge);
	cout << '\n' << "max: " << max(**arr3, edge * edge * edge);
	cout << '\n' << "median: " << median(**arr3, edge * edge * edge);
}