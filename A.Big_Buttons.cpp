#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int t, p, n, z=0;
	int r, sum=0;
	int result = 0;
	string a[100];
	cin >> t;
	
	for(int i=0; i<t; i++) {
		cin >> n >> p;
		
		for(int j=0; j<p; i++) {
			cin >> a[j];
		}
		
		for(int w=0; w<p; w++) {
			for(int j=0; j<p; j++) {
				if(a[w].length() < a[j].length()) {
					for(int y=0; y<a[w].length(); y++) {
						if(a[w].at(y) != a[j].at(y)) break;
						else z++;
					}
					if(z == a[w].length()) {
						sum = pow(2, n) / pow(2, a[j].length());
					}
				}
			}
		}
		
		for(int j=0; j<p; j++) {
			result = pow((double)2, (double)n) - pow(2, a[j].length());
			cout<<result;
		}
		cout << result + sum;
	}
}
