#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set color for different parts of the bicycle
    setcolor(YELLOW); // Frame color
    setfillstyle(SOLID_FILL, YELLOW);
    // Drawing the frame of the bicycle
    line(100, 100, 200, 100); // Top horizontal bar
    line(200, 100, 250, 150); // Right slanting bar
    line(250, 150, 150, 150); // Bottom horizontal bar
    line(150, 150, 100, 100); // Left slanting bar

    setcolor(BLUE); // Wheel color
    setfillstyle(SOLID_FILL, BLUE);
    // Drawing the rear wheel
    circle(125, 150, 25); // Rear wheel
    floodfill(125, 150, BLUE);

    // Drawing the front wheel
    circle(225, 150, 25); // Front wheel
    floodfill(225, 150, BLUE);

    setcolor(RED); // Pedals color
    setfillstyle(SOLID_FILL, RED);
    // Drawing the pedals
    circle(155, 150, 5); // Left pedal
    floodfill(155, 150, RED);
    circle(195, 150, 5); // Right pedal
    floodfill(195, 150, RED);

    getch();
    closegraph();
    return 0;
}

