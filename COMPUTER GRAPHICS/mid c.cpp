#include <stdio.h>
#include <graphics.h>
void drawCircle(int radius) {
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    printf("(%d, %d)\n", x, y);
    
    while (y > x) {
        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;

        printf("(%d, %d)\n", x, y);
        printf("(%d, %d)\n", -x, y);
        printf("(%d, %d)\n", x, -y);
        printf("(%d, %d)\n", -x, -y);
        printf("(%d, %d)\n", y, x);
        printf("(%d, %d)\n", -y, x);
        printf("(%d, %d)\n", y, -x);
        printf("(%d, %d)\n", -y, -x);
    }
}

int main() {
    int radius;
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);
    printf("\nCircle with radius %d using Midpoint Circle Drawing Algorithm:\n\n", radius);
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i*i + j*j == radius*radius)
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
    getch();
    closegraph();
    return 0;
}
