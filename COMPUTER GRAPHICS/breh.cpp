//Bresenham line drawing algorithm
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

void bresenham(int x1, int y1, int x2, int y2)
{
	int dx, dy , di ,xi , yi;
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	di = (2*dy)-dx;
	xi =x1; yi=y1;
	putpixel(xi,yi,WHITE);
	for(int i =0 ;i<dx ; i++)
	{
		if(di<0)
		{
			putpixel(xi,yi,WHITE);
			di = di + (2*dy);
			x1 += 1;
			delay(100);
		}
		else if(di>=0)
		{
			putpixel(xi,yi,WHITE);
			di = di + (2*dy) - (2*dx);
			x1 += 1;
			y1 += 1;
			delay(100);
		}
	}
}
int main()
{
	int gd =DETECT, gm;
	int x1,y1,x2,y2;
	printf("Enter the coorinates of the first point(x1,y1):");
	scanf("%d %d",&x1,&y1);
	printf("Enter the coordinates of the second point(x2,y2):");
	scanf("%d %d",&x2,&y2);
	initgraph(&gd,&gm,NULL);
	bresenham(x1,y1,x2,y2);
	getch();
	closegraph();
	return 0;
	
}
