#include<stdio.h>
#include<math.h>
int check(int m)
{
    if(m==1)return 0;
    int p=floor(sqrt(m+0.5));
    for(int i=2;i<=p;i++)
        if(m%i==0)return 0;
    return 1;
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,flag=1;
        scanf("%d",&n);
        int k=floor(sqrt(n+0.5));
        for(int i=2;i<=k;i++)
        {
            if(n%i==0&&n/i!=i)
            {
                if(check(n/i))
                {
                    printf("Yes\n");
                    flag=0;
                }
                break;
            }
        }
        if(flag)printf("No\n");
    }
    return 0;

}
