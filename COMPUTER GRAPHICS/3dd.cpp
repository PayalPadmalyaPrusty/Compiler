#include <stdio.h>
#include <graphics.h>
#include <math.h>

void translate(int points[][3], int n, int tx, int ty, int tz);
void scale(int points[][3], int n, float sx, float sy, float sz);
void rotateX(int points[][3], int n, float angle);
void rotateY(int points[][3], int n, float angle);
void rotateZ(int points[][3], int n, float angle);
void shear(int points[][3], int n, float shx, float shy, float shz);
void reflect(int points[][3], int n, char axis);

void drawObject(int points[][3], int edges[][2], int n);

int main() {
    int gd = DETECT, gm, n, i, choice;
    int points[20][3], edges[20][2];
    int tx, ty, tz;
    float sx, sy, sz, angle, shx, shy, shz;
    char axis;

    initgraph(&gd, &gm, NULL);

    printf("Enter number of vertices of object: ");
    scanf("%d", &n);

    printf("Enter coordinates of vertices:\n");
    for (i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d %d", &points[i][0], &points[i][1], &points[i][2]);
    }

    printf("\n1. Translate\n2. Scale\n3. Rotate X\n4. Rotate Y\n5. Rotate Z\n6. Shear\n7. Reflect\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter translation factors (tx ty tz): ");
            scanf("%d %d %d", &tx, &ty, &tz);
            translate(points, n, tx, ty, tz);
            break;
        case 2:
            printf("Enter scaling factors (sx sy sz): ");
            scanf("%f %f %f", &sx, &sy, &sz);
            scale(points, n, sx, sy, sz);
            break;
        case 3:
            printf("Enter angle of rotation around X axis (in degrees): ");
            scanf("%f", &angle);
            rotateX(points, n, angle);
            break;
        case 4:
            printf("Enter angle of rotation around Y axis (in degrees): ");
            scanf("%f", &angle);
            rotateY(points, n, angle);
            break;
        case 5:
            printf("Enter angle of rotation around Z axis (in degrees): ");
            scanf("%f", &angle);
            rotateZ(points, n, angle);
            break;
        case 6:
            printf("Enter shearing factors (shx shy shz): ");
            scanf("%f %f %f", &shx, &shy, &shz);
            shear(points, n, shx, shy, shz);
            break;
        case 7:
            printf("Enter axis of reflection (x, y, or z): ");
            scanf(" %c", &axis);
            reflect(points, n, axis);
            break;
        default:
            printf("Invalid choice\n");
    }

    // Drawing edges between vertices
    for (i = 0; i < n; i++) {
        edges[i][0] = i;
        edges[i][1] = (i + 1) % n;
    }

    // Drawing original object
    drawObject(points, edges, n);

    getch(); // Wait for a key press before closing the graphics window
    closegraph(); // Close graphics mode

    return 0;
}

void translate(int points[][3], int n, int tx, int ty, int tz) {
    int i;
    for (i = 0; i < n; i++) {
        points[i][0] += tx;
        points[i][1] += ty;
        points[i][2] += tz;
    }
}

void scale(int points[][3], int n, float sx, float sy, float sz) {
    int i;
    for (i = 0; i < n; i++) {
        points[i][0] *= sx;
        points[i][1] *= sy;
        points[i][2] *= sz;
    }
}

void rotateX(int points[][3], int n, float angle) {
    int i;
    float rad = angle * M_PI / 180.0;
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);
    float y, z;

    for (i = 0; i < n; i++) {
        y = points[i][1];
        z = points[i][2];
        points[i][1] = y * cosTheta - z * sinTheta;
        points[i][2] = y * sinTheta + z * cosTheta;
    }
}

void rotateY(int points[][3], int n, float angle) {
    int i;
    float rad = angle * M_PI / 180.0;
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);
    float x, z;

    for (i = 0; i < n; i++) {
        x = points[i][0];
        z = points[i][2];
        points[i][0] = x * cosTheta + z * sinTheta;
        points[i][2] = -x * sinTheta + z * cosTheta;
    }
}

void rotateZ(int points[][3], int n, float angle) {
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

void shear(int points[][3], int n, float shx, float shy, float shz) {
    int i;
    for (i = 0; i < n; i++) {
        points[i][0] += shx * points[i][2];
        points[i][1] += shy * points[i][2];
        points[i][2] += shz * points[i][0];
    }
}

void reflect(int points[][3], int n, char axis) {
    int i;
    switch (axis) {
        case 'x':
            for (i = 0; i < n; i++) {
                points[i][0] = -points[i][0];
            }
            break;
        case 'y':
            for (i = 0; i < n; i++){
			    points[i][1] = -points[i][1];
            }
            break;
        case 'z':
            for (i = 0; i < n; i++) {
                points[i][2] = -points[i][2];
            }
            break;
        default:
            printf("Invalid axis\n");
    }
}

void drawObject(int points[][3], int edges[][2], int n) {
    int i;
    for (i = 0; i < n; i++) {
        line(points[edges[i][0]][0], points[edges[i][0]][1], points[edges[i][1]][0], points[edges[i][1]][1]);
    }
    line(points[edges[n - 1][1]][0], points[edges[n - 1][1]][1], points[edges[0][0]][0], points[edges[0][0]][1]); // Connect last point to first point
}
