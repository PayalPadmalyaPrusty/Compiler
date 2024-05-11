#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw walls
    rectangle(100, 200, 300, 400);

    // Draw roof
    line(100, 200, 200, 100);
    line(200, 100, 300, 200);

    // Draw door
    rectangle(180, 300, 220, 400);

    // Draw windows
    rectangle(120, 250, 160, 290);
    rectangle(240, 250, 280, 290);

    // Draw rain
    for (int i = 0; i < 100; ++i) {
        line(50 + i * 10, 50, 30 + i * 10, 150);
    }

    delay(5000); // Delay to show the window
    closegraph();
    return 0;
}
