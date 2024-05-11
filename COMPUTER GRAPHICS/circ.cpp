#include<graphics.h>
#include<conio.h>
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd, &gm, (char*)"");
	circle(200,200,80);
	line(200,200,400,400);
	rectangle(100,200,300,400);
	getch();
	closegraph();
	return 0;
}
