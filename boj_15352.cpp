/*
    욱제와 그의 팬들
    https://www.acmicpc.net/problem/15352
*/
#include <bits/stdc++.h>

using namespace std;

struct fanclub
{
	size_t parent;
	size_t id;
	size_t count;
	size_t left;
	size_t right;
};

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t K, N;
	cin >> K >> N;

	vector<fanclub> A(N);

	size_t before = 0;
	for(size_t i=0; i!=N; ++i){
		cin >> A[i].id;

		if(A[i].id != before){
			before = A[i].id;
			A[i].parent = i;
			A[i].count = 1;
			A[i].left = i;
			A[i].right = i;
		}else{
			A[i].parent = A[i-1].parent;
			++A[A[i].parent].count;
			++A[A[i].parent].right;
		}
	}

	size_t Q;
	cin >> Q;

	function<size_t(size_t)> get = [&](size_t i){
		if(i == A[i].parent)
			return i;
		else
			return A[i].parent = get(A[i].parent);
	};

	function<void(size_t, size_t)> merge = [&](size_t src_i, size_t dst_i){
		auto& src = A[src_i];
		auto& dst = A[get(dst_i)];

		src.parent = dst.parent;
		dst.count += src.count;
		dst.left = min(dst.left, src.left);
		dst.right = max(dst.right, src.right);
	};

	size_t answer = 0;

	while(Q--){
		size_t a,b;
		cin >> a >> b;

		auto& club = A[get(b-1)];

		if(a == 1){
			--club.count;
			if(club.count == 0){
				fanclub* right = nullptr;
				fanclub* left = nullptr;

				if(club.left != 0) left = &A[get(club.left - 1)];
				if(club.right + 1 != N) right = &A[get(club.right + 1)];

				if(left){
					merge(club.parent, left->parent);

					if(right && right->id == left->id)
						merge(right->parent, left->parent);
				}else if(right)
					merge(club.parent, right->parent);
			}
		}else
			answer += club.count;
	}

	cout << answer;
}