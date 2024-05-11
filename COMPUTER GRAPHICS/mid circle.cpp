#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void midPointCircleDraw(int x_center, int y_center, int radius) {
    int x = 0, y = radius;
    int p = 1 - radius;

    putpixel(x_center + x, y_center + y, WHITE);
    putpixel(x_center - x, y_center + y, WHITE);
    putpixel(x_center + x, y_center - y, WHITE);
    putpixel(x_center - x, y_center - y, WHITE);
    putpixel(x_center + y, y_center + x, WHITE);
    putpixel(x_center - y, y_center + x, WHITE);
    putpixel(x_center + y, y_center - x, WHITE);
    putpixel(x_center - y, y_center - x, WHITE);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }

        // Plot 8 symmetrical points
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);
        putpixel(x_center + y, y_center + x, WHITE);
        putpixel(x_center - y, y_center + x, WHITE);
        putpixel(x_center + y, y_center - x, WHITE);
        putpixel(x_center - y, y_center - x, WHITE);
    }
}

int main() {
    int gdriver = DETECT, gmode, error, x_center, y_center, radius;

    initgraph(&gdriver, &gmode, (char*)"");

    printf("Enter center coordinates (x_center, y_center): ");
    scanf("%d%d", &x_center, &y_center);
    printf("Enter radius: ");
    scanf("%d", &radius);

    midPointCircleDraw(x_center, y_center, radius);

    getch();
    closegraph();
    return 0;
}

