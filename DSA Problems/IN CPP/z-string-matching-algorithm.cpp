#include<bits/stdc++.h>
using namespace std;
vector<int> Z_algo(string s, int n) {

	vector<int>  z(n); // form a z vector
	int l = 0;
	int r  = 0 ;
	for (int i = 0; i < n; i++) {
		//condition 1
		//if i > r then make l = i and r = i and check furthur as you can see from the below code


		if (i > r) {
			l = i;
			r = i;

			//furthur check
			while (r < n and s[r - l] == s[r]) {
				r++;
			}

			//now r has gone one step ahead so decrease r
			r--;
			//now put the value of z[i]

			z[i] = r - l + 1;

		}


		else {//if i is in between [l, r] inclusive

			//condition 2
			//it has two subparts

			// 1. if z[i - l](at previus indx of ith charater) < r - i + 1
			int j = i - l;
			if (z[j] < r - i + 1) {
				z[i] = z[j];
			}

			//2. if z[i - l] >= r - i + 1 then furthur check cuz your your z[i] can be greater then the z[i-l]

			else {
				l = i;
				while (r < n and s[r - l] == s[r]) {
					r++;
				}
				r--;
				z[i] = r - l + 1;


			}


		}

	}

	return  z;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	string s, p;
	cin >> s >> p;
	string total = p + "$" + s;

	// cout << "total " << total << endl;
	vector<int> z = Z_algo(total, total.length());
	for (auto i : z)
	{
		cout << i << " ";

	}
	cout << endl;



}