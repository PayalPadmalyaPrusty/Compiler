#include <graphics.h>
#include <stdio.h>

void bresenham(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int p = 2 * dy - dx;
    int x, y;

    /* Ensure x0 <= x1 */
    if (x0 > x1) {
        x = x1;
        y = y1;
        x1 = x0;
    } else {
        x = x0;
        y = y0;
    }

    putpixel(x, y, WHITE);

    while (x < x1) {
        x++;
        if (p < 0) {
            p += 2 * dy;
        } else {
            y++;
            p += 2 * (dy - dx);
        }
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gdriver = DETECT, gmode, error, x0, y0, x1, y1;

    /* Initialize graphics mode */
    initgraph(&gdriver, &gmode, (char*)"");

    /* Get user input for coordinates */
    printf("Enter coordinates of first point (x0, y0): ");
    scanf("%d%d", &x0, &y0);
    printf("Enter coordinates of second point (x1, y1): ");
    scanf("%d%d", &x1, &y1);

    bresenham(x0, y0, x1, y1);

    getch();
    closegraph();
    return 0;
}

