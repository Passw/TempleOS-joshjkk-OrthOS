#define WIDTH 640
#define HEIGHT 480
#define DEPTH 4

typedef unsigned char uint8_t;

#define VIDEO_ADDRESS (uint8_t *)0xA0000

void set_pixel(int x, int y) {
    int pitch = (((WIDTH * DEPTH + 7) / 8) + 3) & ~3;
    uint8_t *address = VIDEO_ADDRESS + (y * pitch + x / 2);

    if (x % 2 == 0)
        *address = (*address & 0xF0) | 0x0F;
    else
        *address = (*address & 0x0F) | 0xF0;
}

void clear() {
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            set_pixel(x, y);
}

int main(void) {
    clear();
    return 0;
}
