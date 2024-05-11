#include <graphics.h>  
#include <conio.h> 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() 
{
	int gd= DETECT, gm; 
    initgraph(&gd, &gm, (char*)""); 
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;
    float x = x1;
    float y = y1;
    printf("DDA Line Drawing Algorithm:\n");
    for (int i = 0; i < steps; i++) {
    	 putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
    getch();
    closegraph();
    return 0;
}
