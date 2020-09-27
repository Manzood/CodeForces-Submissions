#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int xo,yo,ax,ay,bx,by;
	scanf("%d %d %d %d %d %d",&xo,&yo,&ax,&ay,&bx,&by);
	int xs,ys,t;
	scanf("%d %d %d",&xs,&ys,&t);
	int ans=0;
	int dist;
	int x,y;
	x=1;
	y=1;
	//determine the closest nodes, then start from there
	//should not take too long
	//greedy not recommended
	while(t>=0)
	{
		printf("%d %d %d\n",x,y,t);
		t=t-abs(x-xs)-abs(y-ys);
		if(t>=0)
		{
			ans+=1;
		}
		xs=x;
		ys=y;
		x=ax*x+bx;
		y=ay*y+by;
	}
	printf("%d\n",ans);
}