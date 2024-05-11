#include <stdio.h>
#include <graphics.h>

#define MAX_VERTICES 20

typedef struct {
    int x, y;
} Point;

void drawWindow(int xmin, int ymin, int xmax, int ymax) {
    rectangle(xmin, ymin, xmax, ymax);
}

void drawPolygon(Point polygon[], int n) {
    for (int i = 0; i < n; i++)
        line(polygon[i].x, polygon[i].y, polygon[(i + 1) % n].x, polygon[(i + 1) % n].y);
}

void clipPolygon(Point subjectPolygon[], int &n, int xmin, int ymin, int xmax, int ymax) {
    Point out[MAX_VERTICES];
    int outVertices = 0;

    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        Point p1 = subjectPolygon[i];
        Point p2 = subjectPolygon[next];

        int code1 = 0, code2 = 0;

        if (p1.x < xmin)
            code1 |= 1;
        else if (p1.x > xmax)
            code1 |= 2;
        if (p1.y < ymin)
            code1 |= 4;
        else if (p1.y > ymax)
            code1 |= 8;

        if (p2.x < xmin)
            code2 |= 1;
        else if (p2.x > xmax)
            code2 |= 2;
        if (p2.y < ymin)
            code2 |= 4;
        else if (p2.y > ymax)
            code2 |= 8;

        if ((code1 & code2) == 0) {
            if (code1 == 0)
                out[outVertices++] = p1;
            else if (code2 == 0)
                out[outVertices++] = p2;
            else {
                Point intersect;
                if (code1 & 1) {
                    intersect.x = xmin;
                    intersect.y = p1.y + (p2.y - p1.y) * (xmin - p1.x) / (p2.x - p1.x);
                } else if (code1 & 2) {
                    intersect.x = xmax;
                    intersect.y = p1.y + (p2.y - p1.y) * (xmax - p1.x) / (p2.x - p1.x);
                } else if (code1 & 4) {
                    intersect.x = p1.x + (p2.x - p1.x) * (ymin - p1.y) / (p2.y - p1.y);
                    intersect.y = ymin;
                } else if (code1 & 8) {
                    intersect.x = p1.x + (p2.x - p1.x) * (ymax - p1.y) / (p2.y - p1.y);
                    intersect.y = ymax;
                }
                out[outVertices++] = intersect;
            }
        }
    }

    n = outVertices;
    for (int i = 0; i < n; i++)
        subjectPolygon[i] = out[i];
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xmin, ymin, xmax, ymax;
    printf("Enter clipping window (xmin, ymin, xmax, ymax): ");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

    drawWindow(xmin, ymin, xmax, ymax);

    int n;
    printf("Enter number of vertices for subject polygon: ");
    scanf("%d", &n);

    Point subjectPolygon[MAX_VERTICES];

    printf("Enter vertices of subject polygon (x y): ");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &subjectPolygon[i].x, &subjectPolygon[i].y);

    drawPolygon(subjectPolygon, n);

    clipPolygon(subjectPolygon, n, xmin, ymin, xmax, ymax);

    setcolor(RED);
    drawPolygon(subjectPolygon, n);

    getch();
    closegraph();

    return 0;
}
