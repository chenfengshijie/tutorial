#include<stdio.h>
int num[19];
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&num[i]);
		int cnt=0;int flag=1;
		while(flag)
		{
			flag=0;
			for(int i=1;i<=n;++i)
			{
				num[i]-=1;
				if(num[i]==0)
				{
					++cnt;
					flag=1;
				}
			}
		}
		if(cnt==n)printf("sorry\n");
		else printf("well played\n");
	}
	return 0;
}
