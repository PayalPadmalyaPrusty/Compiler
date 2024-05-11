#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	rectangle(200, 100, 600, 500); 
	rectangle(220, 120, 580, 480);
	circle(560,140,20);
	circle(240, 460, 20);
	circle(560,460,20);
	circle(240,140,20);
	setfillstyle(SOLID_FILL,BROWN); 
    floodfill(300, 170, 15);
	line(300, 170, 500, 170); 
	line(300, 184, 500, 184); 
	circle(300, 177, 7); 
	circle(500, 177, 7); 
	line(300, 430, 500, 430);
	line(300, 416, 500, 416); 
	circle(300, 423, 7); 
	circle(500, 423, 7); 
	line(270, 200, 270, 400); 
	line(284, 200, 284, 400); 
	circle(277, 200, 7); 
	circle(277, 400, 7); 
	line(530,200,530,400);line(530, 200, 530, 400); 
    line(516, 200, 516, 400); 
    circle(523, 200, 7); 
    circle(523, 400, 7); 
    line(270, 170, 350, 250); 
    line(530, 170, 450, 250); 
    line(270, 430, 350, 350); 
    line(530, 430, 450, 350); 
    circle(400, 300, 40);	 
    circle(400, 300, 15);
    setfillstyle(SOLID_FILL, RED); 
    floodfill(303, 180, 15); 
    floodfill(497, 180, 15); 
    floodfill(303, 420, 15); 
    floodfill(497, 420, 15); 
    floodfill(280, 203, 15); 
    floodfill(280, 403, 15); 
    floodfill(520, 203, 15); 
    floodfill(520, 403, 15); 
    floodfill(405, 305, 15); 
    setfillstyle(SOLID_FILL, DARKGRAY); 
    floodfill(243, 143, 15); 
    floodfill(563, 143, 15); 
    floodfill(243, 463, 15); 
    floodfill(563, 463, 15); 


	getch();
	closegraph();
	return 0;
}
