/*
    소트
    https://www.acmicpc.net/problem/1071
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<size_t> A(N);
	for(auto& x:A)
		cin >> x;
	sort(A.begin(),A.end());

	for(size_t i=0; i!=N;){
		//cout << "{" << i << "} ";

		auto _1 = lower_bound(A.begin()+i+1, A.end(), A[i] + 1);

		if(_1 != A.end() && *_1 == A[i] + 1){
			auto _2 = lower_bound(A.begin()+i+1, A.end(), A[i] + 2);

			if(_2 == A.end()){
				auto j = _1 - A.begin();
				for(; j!=N && A[j] == *_1; ++j)
					cout << *_1 << " ";
				
				for(size_t j=i; A[j] == A[i]; ++j)
					cout << A[j] << " ";
				i = j;
				//cout << "[1]\n";
			}else{
				size_t j;
				for(j=i; A[j] == A[i]; ++j)
					cout << A[j] << " ";
				cout << *_2 << " ";
				*_2 = A[j];
				i = j + 1;
				//cout << "[2]\n";
			}
				
		}else{
			size_t j;
			for(j=i; j != N && A[j] == A[i]; ++j)
				cout << A[j] << " ";
			i = j;
			//cout << "[3]\n";
		}
	}
}