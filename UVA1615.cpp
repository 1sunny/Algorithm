#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> pii;
const double eps = 1e-6;
#define fi first
#define se second
const int N = 1e5+100;
double L, D, n;
int cmp(double a) {
	if(a > eps) return 1;
	else if(a < -eps) return -1;
	return 0;
}
bool cmp1(pii a, pii b) {
	if(a.se != b.se) {
		return a.se < b.se;
	}
	return a.fi < b.fi;
}
double calc(double y) {
	return sqrt(D*D-y*y);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt","r", stdin);
#endif
	while(cin >> L >> D >> n) {
		vector<pii>ve;
		for(int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			double dis = calc(y);
			double l = max((double)0, x-dis);
			double r = min(L, x+dis);
			ve.push_back({l, r});
		}
		sort(ve.begin(), ve.end(), cmp1);
		int res = 0;
		double pre = -1;
		for(int i = 0; i < ve.size(); i++) {
			pii cur = ve[i];
			if(cmp(cur.fi - pre) == 1) {
				res++;
				pre = cur.se;
			}
		}
		cout << res << endl;
	}
}
