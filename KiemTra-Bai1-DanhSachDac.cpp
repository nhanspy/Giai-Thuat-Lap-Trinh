#include <iostream>
#include <math.h>
using namespace std;

void Tao(int A[], int n){//cau1.1
	for (int i = 1 ; i <= n ; i ++){
		cin >> A[i];
	}
}

void Xem(int A[], int n){//Cau1.1
	for (int i = 1 ; i <= n ; i ++){
		cout << A[i] << "\t";
	}
}

void SapXepDoanTangDan(int A[], int l , int r){
	for (int i = l ; i < r ; i ++){
		for (int j = r ; j > i ; j--){
			if (A[j] < A[j-1]) {
				int tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
			}
		}
	}
}

void SapXepDoanGiamDan(int A[], int l , int r){
	for (int i = l ; i < r ; i ++){
		for (int j = r ; j > i ; j--){
			if (A[j] > A[j-1]) {
				int tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
			}
		}
	}
}

void SapXepTangDanSoLeTruocSoChanSau(int A[], int n){
	int l = 1 , r = n;
	while (l < r){
		if (abs(A[l]) % 2 == 1)
			l++;
		if (A[r] % 2 == 0)
			r--;
		if (A[l] % 2 == 0 and abs(A[r]) % 2== 1){
			int tmp = A[l]; A[l] = A[r] ; A[r] = tmp;
		}
	}
	if (A[l] % 2 == 0) l--;
	SapXepDoanTangDan(A,1,l);
	SapXepDoanGiamDan(A,l+1,n);
}

int max(int a, int b) {return a>b?a:b;}

int TongConLonNhat(int A[], int n){
	int B[n+1] = {0};
	int Max = A[1];
	for (int i = 1 ; i <= n ; i ++){
		B[i] = A[i];
		if (B[i-1] > 0){
			B[i] += B[i-1];
		} Max = max(B[i],Max);
	}
	return Max;
}
/*
int TongConMax(int A[],int n,int k){
	for (int i = 0; i <= n-k; i++)
 		for (int j = 0; j < k; j++)
  			B[i] += A[i + j];
 	int	max = B[0];
 		for (int h = 1; h <= n - k;h++)
 	if (max < B[h])
	 	max = B[h];
 	return max;
}*/

int main(){
	int A[100], n;
	cin >> n;
	Tao(A,n),cout << TongConLonNhat(A,n) << endl;
	return 0;
}
