#include<stdio.h>
#include<string.h>
#include<math.h>
int k,l,n,flag;
struct Node
{
	int x,y,r;
}num[1009];
int head[1000009],nx[100009],to[100009],cnt=0,mark[1009];
void add(int u,int v)
{
	to[++cnt]=v;
	nx[cnt]=head[u];
	head[u]=cnt;
}
void DFS(int p)
{
	//printf("p=%d\n",p);
	mark[p]=1;
	int v;
	for(int i=head[p];i;i=nx[i])
	{
		v=to[i];
		if(mark[v])continue;
		DFS(v);
	}
}
int main()
{
	while(scanf("%d%d%d",&k,&l,&n)==3)
	{
		memset(head,0,sizeof(head));
		memset(nx,0,sizeof(nx));
		memset(to,0,sizeof(to));
		cnt=0;
		for(int i=1;i<=n;++i)
			scanf("%d%d%d",&num[i].x,&num[i].y ,&num[i].r );
		for(int i=1;i<=n;++i)
		{
			if(num[i].x-num[i].r<=0)
			{
				add(n+3,i);
				add(i,n+3);
			}
			if(num[i].y-num[i].r<=0)
			{
				add(n+2,i);
				add(i,n+2);
			}
			if(num[i].x+num[i].r>=k)
			{
				add(i,n+5);
				add(n+5,i);
			}
			if(num[i].y+num[i].r>=l)
			{
				add(i,n+4);
				add(n+4,i);
			}
		}
		double len,rr;
		for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			len=sqrt(1.00*(double)(num[i].x -num[j].x)*(num[i].x -num[j].x)+1.00*(double)(num[i].y-num[j].y)*(num[i].y-num[j].y));
			rr=1.00*(double)num[i].r+1.00*(double)num[j].r;
			if(len<=rr)
			{
				add(i,j);
				add(j,i);
				//printf("%d---%d\n",i,j);
			}
		}
		memset(mark,0,sizeof(mark));
		DFS(n+2);
		if(mark[n+3]||mark[n+4])
		{
			printf("No\n");
			continue;
		}
		memset(mark,0,sizeof(mark));
		DFS(n+5);
		if(mark[n+3]||mark[n+4])
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
}
