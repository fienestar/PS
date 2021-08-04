/*
    스도쿠
    https://www.acmicpc.net/problem/2239
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t sudoku[9][9];
	bool check_hor[9][10]={};
	bool check_ver[9][10]={};
	bool check_block[9][10]={};

	auto is_possible = [&](size_t i, size_t j, size_t n){
		if(check_hor[i][n])return false;
		if(check_ver[j][n])return false;
		if(check_block[i/3*3+j/3][n])return false;
		return true;
	};

	auto toggle = [&](size_t i, size_t j, size_t n){
		check_hor[i][n] ^= 1;
		check_ver[j][n] ^= 1;
		check_block[i/3*3+j/3][n] ^= 1;
	};

	for(size_t i=0; i!=9; ++i)
		for(size_t j=0; j!=9; ++j){
			char ch;
			cin >> ch;
			sudoku[i][j] = ch - '0';
			toggle(i,j,sudoku[i][j]);
		}

	function<void(size_t,size_t)> dfs = [&](size_t i, size_t j){
		if(i==9 && j==0){
			for(auto& line:sudoku){
				for(auto& dot:line)
					cout << dot;
				cout << "\n";
			}
			exit(0);
		}

		if(sudoku[i][j]){
			if(j==8)
				dfs(i+1,0);
			else
				dfs(i,j+1);
		}
		else
			for(size_t n=1; n<=9; ++n)
				if(is_possible(i,j,n)){
					sudoku[i][j]=n;
					toggle(i,j,n);
					if(j==8)
						dfs(i+1,0);
					else
						dfs(i,j+1);
					sudoku[i][j]=0;
					toggle(i,j,n);
				}
	};

	dfs(0,0);
}