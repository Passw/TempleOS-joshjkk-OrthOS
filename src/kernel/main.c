#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_DEPTH 4 /* 16 colors, each represented by a nibble */

#define VIDEO_ADDRESS (unsigned char *)0xA0000

int main(void) {
    int pitch = (SCREEN_WIDTH * SCREEN_DEPTH + 7) / 8;
    pitch = (pitch + 3) & ~3; /* round up to nearest multiple of 4 */

    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            unsigned char *address = VIDEO_ADDRESS + y * pitch + x / 2;

            /* fill white screen */
            if (x % 2 == 0)
                *address = (*address & 0xF0) | 0x0F;
            else
                *address = (*address & 0x0F) | 0xF0;
        }
    }
    return 0;
}
