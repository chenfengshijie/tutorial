#include<stdio.h>
#include<string.h>
char ss[30][109];
int used[20],ans[20009];int n,tot;
int num[30];
void qsort(int left,int right)
{
	if(left<right)
	{
		int l=left,r=right,pivot=num[l];
		while(l<r)
		{
			while(l<r&&strcmp(ss[num[r]],ss[num[pivot]])>=0)--r;
			if(l<r)num[l]=num[r];
			while(l<r&&strcmp(ss[pivot],ss[l])>=0)++l;
			if(l<r)num[r]=num[l];
		}
		num[l]=pivot;
		qsort(left,l-1);
		qsort(l+1,right);
	}
}
void DFS(int p,int last)
{
	if(p==tot+1)
	{
		for(int i=1;i<=tot;++i)
			printf("%s ",ss[ans[i]]);
		printf("\n");
	}
	for(int i=1;i<=n;++i)
	{
		if(num[i]!=last&&used[num[i]]>=1)
		{
			used[num[i]]--;
			ans[p]=num[i] ;
			DFS(p+1,num[i] );
			used[num[i]]++;
		}
	}
	return ;
}
int main()
{
	
	while(scanf("%d",&n)==1)
	{
		tot=0;
		memset(used,0,sizeof(used));
		for(int i=1;i<=n;++i)
		{
			scanf(" %s %d",ss[i],&used[i]);
			num[i]=i;
			tot+=used[i];
		}
		qsort(1,n);
		//for(int i=1;i<=n;++i)
		//	printf("%s ",ss[num[i] ]);
		DFS(1,0);
	}
	return 0;
 } 
