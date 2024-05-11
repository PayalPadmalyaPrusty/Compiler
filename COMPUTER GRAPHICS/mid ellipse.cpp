#include <graphics.h>
#include <stdio.h>

void midPointEllipseDraw(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    float p = ry * ry - rx * rx * ry + (rx * rx) / 4;

    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);

    while (2 * ry * ry * x <= 2 * rx * rx * y) {
        x++;
        if (p < 0) {
            p += 2 * ry * ry * x + ry * ry;
        } else {
            y--;
            p += 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
        }

        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }

    p = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;

    while (y >= 0) {
        y--;
        if (p > 0) {
            p += rx * rx - 2 * rx * rx * y;
        } else {
            x++;
            p += rx * rx - 2 * rx * rx * y + 2 * ry * ry * x;
        }

        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }
}

int main() {
    int gdriver = DETECT, gmode, error, xc, yc, rx, ry;

    initgraph(&gdriver, &gmode, (char*)"");

    printf("Enter center coordinates (xc, yc): ");
    scanf("%d%d", &xc, &yc);
    printf("Enter major and minor radius (rx, ry): ");
    scanf("%d%d", &rx, &ry);

    midPointEllipseDraw(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}

