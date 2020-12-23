#include<stdio.h>
#include<string.h>
char a[1009],b[1009];
char a_[1009],b_[1009];
int ans[10009],cnt=0;
#define max(a,b)(a>b?a:b)
int solve(char a,char b,int p)
{
	int ha=a-'0',hb=b-'0';
	int now=(ha+hb+p);
	ans[++cnt]=now%10;
	return (now/10);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%s",a_);
		scanf("%s",b_);
		int len1=strlen(a_),len2=strlen(b_);
		for(int i=0;i<len1;++i)
			a[i]=a_[len1-i-1];
		for(int i=0;i<len2;++i)
			b[i]=b_[len2-i-1];
		int len=max(len1,len2);
		int now=0;
		for(int i=0;i<=len;++i)
		{
			now=solve((i>=len1?'0':a[i]),(i>=len2?'0':b[i]),now);
		}
		if(ans[cnt]==1)printf("1");
		for(int i=cnt-1;i>=1;--i)
			printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}
