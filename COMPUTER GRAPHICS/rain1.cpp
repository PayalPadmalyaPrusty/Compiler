#include <graphics.h>
#include <stdlib.h>
#include <time.h>`

#define NUM_RAIN_DROPS 200 // Number of raindrops

void drawHouse() {
    // House body
    rectangle(200, 200, 400, 400);
    // Door
    rectangle(250, 300, 350, 400);
    // Left roof line
    line(200, 200, 300, 100);
    // Right roof line
    line(300, 100, 400, 200);
    // Windows
    rectangle(270, 250, 290, 280);
    rectangle(310, 250, 330, 280);
}

void drawRain(int x[], int y[]) {
    int i;
    for (i = 0; i < NUM_RAIN_DROPS; i++) {
        putpixel(x[i], y[i], WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    int x[NUM_RAIN_DROPS], y[NUM_RAIN_DROPS];
    int i;

    // Initialize random number generator
    srand(time(NULL));

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Draw the house
    drawHouse();

    // Generate random positions for raindrops
    for (i = 0; i < NUM_RAIN_DROPS; i++) {
        x[i] = rand() % 600; // Random x-coordinate within window width
        y[i] = rand() % 200; // Random y-coordinate above the house
    }

    // Draw the rain
    while (!kbhit()) {
        drawRain(x, y);
        delay(100); // Adjust the speed of raindrops falling
        cleardevice(); // Clear the screen to redraw raindrops
        drawHouse(); // Redraw the house
        // Update y-coordinate of raindrops for next frame
        for (i = 0; i < NUM_RAIN_DROPS; i++) {
            y[i] += 10; // Move raindrops downward
            // Reset raindrops to top if they fall below the bottom of the window
            if (y[i] > 400) {
                y[i] = rand() % 200; // Reset to random y-coordinate above the house
                x[i] = rand() % 600; // Reset to random x-coordinate within window width
            }
        }
    }

    closegraph();
    return 0;
}
