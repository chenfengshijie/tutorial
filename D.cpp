#include<stdio.h>
#define min(a,b)(a<b?a:b)
char ss[1009];
int n,k;
int f(int p,int len)
{
	int cnt=0;
	for(int i=p,j=p+len-1;i<j;i++,j--)
	{
		if(ss[i]!=ss[j])++cnt;
	}
	return cnt*2;
}
int check(int mid)
{
	for(int i=0;i<=n-mid;++i)
	{
		if(f(i,mid)<=k)return 1;
	}
	return 0;
}
int main()
{
	while(scanf("%d%d",&n,&k)==2)
	{
		scanf("%s",ss);
		int l=0,r=n,mid;
		while(l<r-1)
		{
			mid=(l+r)>>1;
			if(check(mid))l=mid;
			else r=mid;
		}
		for(int i=min(r+50,n);i;i--)
			if(check(i))
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
