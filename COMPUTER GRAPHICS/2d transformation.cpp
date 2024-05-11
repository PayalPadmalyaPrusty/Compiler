#include <graphics.h>
#include <stdio.h>
#include <math.h>

// Function prototypes
void translate(float points[][2], int n, float tx, float ty);
void scale(float points[][2], int n, float sx, float sy);
void rotate(float points[][2], int n, float angle);
void shear(float points[][2], int n, float shx, float shy);
void reflect(float points[][2], int n, char axis);
void drawObject(float points[][2], int n);

int main() {
    int gd = DETECT, gm, n, i, choice;
    float points[20][2], tx, ty, sx, sy, angle, shx, shy;
    char axis;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    printf("Enter number of vertices of object: ");
    scanf("%d", &n);

    printf("Enter coordinates of vertices:\n");
    for (i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%f %f", &points[i][0], &points[i][1]);
    }

    printf("\n1. Translate\n2. Scale\n3. Rotate\n4. Shear\n5. Reflect\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter translation factors (tx ty): ");
            scanf("%f %f", &tx, &ty);
            translate(points, n, tx, ty);
            break;
        case 2:
            printf("Enter scaling factors (sx sy): ");
            scanf("%f %f", &sx, &sy);
            scale(points, n, sx, sy);
            break;
        case 3:
            printf("Enter angle of rotation (in degrees): ");
            scanf("%f", &angle);
            rotate(points, n, angle);
            break;
        case 4:
            printf("Enter shearing factors (shx shy): ");
            scanf("%f %f", &shx, &shy);
            shear(points, n, shx, shy);
            break;
        case 5:
            printf("Enter axis of reflection (x or y): ");
            scanf(" %c", &axis);
            reflect(points, n, axis);
            break;
        default:
            printf("Invalid choice\n");
    }

    // Draw original object
    drawObject(points, n);

    getch(); // Wait for a key press before closing the graphics window
    closegraph(); // Close graphics mode
    return 0;
}

void translate(float points[][2], int n, float tx, float ty) {
    int i;
    for (i = 0; i < n; i++) {
        points[i][0] += tx;
        points[i][1] += ty;
    }
}

void scale(float points[][2], int n, float sx, float sy) {
    int i;
    for (i = 0; i < n; i++) {
        points[i][0] *= sx;
        points[i][1] *= sy;
    }
}

void rotate(float points[][2], int n, float angle) {
    int i;
    float rad = angle * M_PI / 180.0;
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);
    float x, y;

    for (i = 0; i < n; i++) {
        x = points[i][0];
        y = points[i][1];
        points[i][0] = x * cosTheta - y * sinTheta;
        points[i][1] = x * sinTheta + y * cosTheta;
    }
}

void shear(float points[][2], int n, float shx, float shy) {
    int i;
    for (i = 0; i < n; i++) {
        float x = points[i][0];
        float y = points[i][1];
        points[i][0] = x + shx * y;
        points[i][1] = y + shy * x;
    }
}

void reflect(float points[][2], int n, char axis) {
    int i;
    switch(axis) {
        case 'x':
            for (i = 0; i < n; i++) {
                points[i][1] = -points[i][1];
            }
            break;
        case 'y':
            for (i = 0; i < n; i++) {
                points[i][0] = -points[i][0];
            }
            break;
        default:
            printf("Invalid axis\n");
    }
}

void drawObject(float points[][2], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        line(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
    }
    line(points[n - 1][0], points[n - 1][1], points[0][0], points[0][1]); // Connect last point to first point
}

