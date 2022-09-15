#include<bits/stdc++.h>
using namespace std;

int dp[100005];

int solve(int n,int k,vector<int> &h){
	if(n < 0){
		return INT_MAX;
	}
	
	if(n == 0){
		return 0;
	}
	
	if(dp[n]!=-1){
		return dp[n];
	}
	
	int ans = INT_MAX;
	
	for(int j = n-1; j >=max(0,n-k); j--){
		ans = min(ans, solve(j,k,h) + abs(h[n] - h[j]));
	}
	
	
	return dp[n] = ans;
}

int main()
{
	  int n,k;
	  cin>>n>>k;
	  vector<int> h;
	  for(int i=0;i<n;i++){
	  	int x;
	  	cin>>x;
	  	h.push_back(x);
	  }
	memset(dp,-1,sizeof(dp));
	cout << solve(n-1,k,h) << endl; 
	return 0;
}
