#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;
    int r = 100;

    // Set different colors for the cycle
    for (int i = 1; i <= 15; i++) {
        setcolor(i);
        circle(xc, yc, r);
        r -= 5; // Decrease radius for each subsequent circle
    }

    getch();
    closegraph();
    return 0;
}

