#include <stdio.h>
#include <graphics.h>

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

#define xmin 100
#define xmax 300
#define ymin 100
#define ymax 300

#define true 1
#define false 0

int computeCode(int x, int y) {
    int code = 0;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

void cohenSutherlandLineClip(int x1, int y1, int x2, int y2, int color) {
    int code1, code2;
    int done = false;

    while (!done) {
        code1 = computeCode(x1, y1);
        code2 = computeCode(x2, y2);

        if (!(code1 | code2)) { // Inside
            setcolor(color);
            line(x1, y1, x2, y2);
            done = true;
        } else if (code1 & code2) { // Outside
            done = true;
        } else { // Clipping
            int x, y;
            int code_out = code1 ? code1 : code2;

            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else { // LEFT
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code_out == code1) {
                x1 = x;
                y1 = y;
            } else {
                x2 = x;
                y2 = y;
            }
        }
    }
}

void sutherlandHodgmanPolygonClip(int n, int poly[][2]) {
    int i, j;
    int out[20][2], outn;

    for (i = 0; i < n; i++) {
        int k = (i + 1) % n;
        cohenSutherlandLineClip(poly[i][0], poly[i][1], poly[k][0], poly[k][1], RED);
    }

    outn = 0;
    for (i = 0; i < n; i++) {
        int k = (i + 1) % n;

        int code1 = computeCode(poly[i][0], poly[i][1]);
        int code2 = computeCode(poly[k][0], poly[k][1]);

        if (!(code1 & code2)) { // Inside
            out[outn][0] = poly[k][0];
            out[outn][1] = poly[k][1];
            outn++;
        } else if (code1 & code2) { // Outside
            if (!(code1 & LEFT) && (code2 & LEFT)) {
                out[outn][0] = xmin;
                out[outn][1] = poly[i][1] + (xmin - poly[i][0]) * (poly[k][1] - poly[i][1]) / (poly[k][0] - poly[i][0]);
                outn++;
            } else if (!(code1 & RIGHT) && (code2 & RIGHT)) {
                out[outn][0] = xmax;
                out[outn][1] = poly[i][1] + (xmax - poly[i][0]) * (poly[k][1] - poly[i][1]) / (poly[k][0] - poly[i][0]);
                outn++;
            } else if (!(code1 & TOP) && (code2 & TOP)) {
                out[outn][0] = poly[i][0] + (ymax - poly[i][1]) * (poly[k][0] - poly[i][0]) / (poly[k][1] - poly[i][1]);
                out[outn][1] = ymax;
                outn++;
            } else if (!(code1 & BOTTOM) && (code2 & BOTTOM)) {
                out[outn][0] = poly[i][0] + (ymin - poly[i][1]) * (poly[k][0] - poly[i][0]) / (poly[k][1] - poly[i][1]);
                out[outn][1] = ymin;
                outn++;
            }
        }
    }

    if (outn > 0) {
        for (i = 0; i < outn; i++) {
            int k = (i + 1) % outn;
            cohenSutherlandLineClip(out[i][0], out[i][1], out[k][0], out[k][1], BLUE);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int poly[4][2] = {{50, 200}, {200, 50}, {350, 200}, {200, 350}};

    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    sutherlandHodgmanPolygonClip(4, poly);

    getch();
    closegraph();
    return 0;
}
