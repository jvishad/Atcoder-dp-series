#include <bits/stdc++.h>
using namespace std;

int dp[100005];

int solve(int n,vector<int> &h){
	if(n < 0){
		return INT_MAX;
	}
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return abs(h[1] - h[0]);
	}
	
	if(dp[n] != -1){
		return dp[n];
	}
	
	return dp[n] =  min(solve(n-1,h) + abs(h[n] - h[n-1]), solve(n-2,h) + abs(h[n] - h[n-2]));
	 
}

int main() {
	// your code goes here
	int n;
  	cin>>n;
  	vector<int> h;
  	for(int i=0;i<n;i++){
      int x;
      cin>>x;
      h.push_back(x);
    }
  	memset(dp,-1,sizeof(dp));
  	
	cout << solve(n-1,h) << endl;
 	
  	
  	
	return 0;
}
