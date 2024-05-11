#include <stdio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set color for the ship body
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    // Draw the ship body
    line(100, 300, 300, 300);
    line(300, 300, 250, 250);
    line(250, 250, 150, 250);
    line(150, 250, 100, 300);
    floodfill(200, 275, YELLOW);

    // Set color for the ship windows
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    // Draw windows
    rectangle(175, 265, 225, 290);
    rectangle(225, 265, 275, 290);
    floodfill(200, 280, BLUE);
    floodfill(250, 280, BLUE);

    // Set color for the ship chimney
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    // Draw chimney
    rectangle(175, 240, 225, 250);
    floodfill(200, 245, RED);

    // Set color for the ship flag
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    // Draw flag
    rectangle(160, 225, 170, 240);
    rectangle(170, 225, 180, 235);
    line(180, 230, 200, 230);
    line(200, 230, 180, 220);
    floodfill(165, 230, GREEN);
    floodfill(175, 230, GREEN);
    floodfill(190, 225, GREEN);

    getch();
    closegraph();
    return 0;
}

