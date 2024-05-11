#include <stdio.h>
#include <graphics.h>

#define SQUARE_SIZE 60
#define BOARD_SIZE 8

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x, y;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            x = j * SQUARE_SIZE;
            y = i * SQUARE_SIZE;
            if ((i + j) % 2 == 0) {
                // Set white color
                setfillstyle(SOLID_FILL, WHITE);
            } else {
                // Set black color
                setfillstyle(SOLID_FILL, BLACK);
            }
            // Draw square
            bar(x, y, x + SQUARE_SIZE, y + SQUARE_SIZE);
        }
    }

    getch();
    closegraph();
    return 0;
}

