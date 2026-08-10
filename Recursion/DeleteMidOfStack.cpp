#include <vector>
#include <bits/stdc++.h>
using namespace std;


class Solution {
	public:
	void deleteMid(stack<int>& s) {
		int n = s.size();
		int mid = n / 2 + 1;
		
		solve(s, mid);
	}
	
	void solve(stack<int>& s, int mid) {
		if (mid == 1) {
			s.pop();
			return;
		}
		
		int x = s.top();
		s.pop();
		
		solve(s, mid - 1);
		
		s.push(x);
	}
};
