#include <iostream>
#include <cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<pair<int, long long>>vec;
		vector<int>v1;
		vector<long long>v2;
		vector<int>work;
		vector<long long>time;
		int N, K;
		long long sum = 0;
		cin >> N >> K;
		

		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			
			v1.push_back(a);
		}
		for (int i = 0; i < N; i++) {
			long long b;
			cin >> b;
			v2.push_back(b);
		}
		for (int i = 0; i < N; i++) {
			vec.push_back({ v1[i],v2[i] });
		}


		sort(vec.rbegin(), vec.rend());

		int firstone = vec[0].first;
		work.push_back(vec[0].first);

		for (int i = 1; i < N; i++) {
			if (vec[i].first == vec[i - 1].first) {
				time.push_back(vec[i].second);

			}
			else {
				work.push_back(vec[i].first);

			}
			
		}
		sort(time.begin(), time.end());

		if (K == work.size()) {
			cout << "#" << test_case << " " << sum << endl;
		}
		else {
			for (int i = 0; i < K - work.size(); i++) {
				sum += time[i];

			}

			cout << "#" << test_case << " " << sum << endl;

		}
		
		
	}
	return 0;
}
