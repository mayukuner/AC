#include <stdio.h>
int main()
{
	int n,ans;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int p[1001]={0};
		ans=0;
		for(int i=n;i>1;i--)  
			for(int j=1;j<i;j++)  
			{
				int t;
				scanf("%d",&t);
				if(t)
				{
					p[n-i+1]++;
					p[n-i+j+1]++;
				}
			}
		for(int i=1; i<=n; i++)
			ans+=(n-p[i]-1)*p[i];
		printf("%d\n",n*(n-1)*(n-2)/6-ans/2);
	}
	return 0;
}
