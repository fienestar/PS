/*
    Magic Squares
    https://www.acmicpc.net/problem/14039
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int square[4][4];
	for(auto& line:square)
		for(auto& n:line)
			cin >> n;

	int sum = 0;
	for(size_t i=0; i!=4; ++i) sum += square[0][i];
	for(size_t i=0; i!=4; ++i){
		int row_sum = 0, column_sum = 0;
		for(size_t j=0; j!=4; ++j){
			row_sum += square[j][i];
			column_sum += square[i][j];
		}

		if(row_sum != sum || column_sum != sum){
			cout << "not magic";
			return 0;
		}
	}

	cout << "magic";
}