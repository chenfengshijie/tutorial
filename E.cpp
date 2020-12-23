#include<stdio.h>
#include<string.h>
int n,m;
#define maxn 200009
int head[maxn],nx[maxn],to[maxn],cost[maxn],cnt=0;
int head_[maxn],nx_[maxn],to_[maxn],cost_[maxn],cnt_=0;
int q[100000009],h,t,in[maxn];
long long dis[maxn],dis_[maxn];
void spfa(int flag) {
	if(!flag) {
		for(int i=1; i<=n; ++i) {
			dis[i]=1e16;
			in[i]=0;
		}
		dis[0]=0;
	} else {
		for(int i=1; i<=n; ++i) {
			dis_[i]=1e16;
			in[i]=0;
		}

		dis_[0]=0;
	}
	h=t=0;
	q[t]=0;++t;
	int u,v,len;
	while(h!=t) {
		u=q[h];++h;
		in[u]=0;
		//printf("%d----",u);
		if(!flag) {
			for(int i=head[u]; i; i=nx[i]) {
				v=to[i];
				len=cost[i];
				if(dis[v]>dis[u]+len) {
					dis[v]=dis[u]+len;
					if(!in[v]) {
						q[t++]=v;
						in[v]=1;
					}
				}
			}
		} else {
			for(int i=head_[u]; i; i=nx_[i]) {
				v=to_[i];
				len=cost_[i];
				if(dis_[v]>dis_[u]+len) {
					dis_[v]=dis_[u]+len;
					if(!in[v]) {
						q[t++]=v;
						in[v]=1;
					}
				}
			}
		}
	}
}
int main() {
	while(scanf("%d%d",&n,&m)==2) {
		memset(head,0,sizeof(head));
		memset(head_,0,sizeof(head_));
		memset(nx,0,sizeof(nx));
		memset(nx_,0,sizeof(nx));
		cnt=0,cnt_=0;
		int a,b,c;
		for(int i=1; i<=m; ++i) {
			scanf("%d%d%d",&a,&b,&c);
			cost[++cnt]=c;
			cost_[++cnt_]=c;
			to[cnt]=b;
			to_[cnt_]=a;
			nx[cnt]=head[a];
			nx_[cnt_]=head_[b];
			head[a]=cnt;
			head_[b]=cnt_;
		}
		spfa(0);
		spfa(1);
		for(int i=1; i<=n; ++i)
			if(dis[i]!=1e16&&dis_[i]!=1e16)printf("%lld ",dis[i]+dis_[i]);
			else printf("-1 ");
		printf("\n");
	}
	return 0;
}
