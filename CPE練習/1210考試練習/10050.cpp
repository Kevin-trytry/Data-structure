#include <iostream>
using namespace std;

int main()
{
    int i, j, k;
    int T;

    cin >> T;
    
    for (i=0;i<T;i++) {
    	int N, P, hi;
    	
    	cin >> N >> P;
    	
    	int days[N+1]={}, total = 0;
    	
    	for (j=0;j<P;j++) {
    		cin >> hi;
    		
    		for (k=hi;k<=N;k=k+hi) {
    			if (k % 7 == 6 || k % 7 == 0)
    				continue;
    			
    			if (days[k] == 0) {
    				total++;
    				days[k] = 1;
				}
			}
		}
		
		cout << total << endl;
	}
}