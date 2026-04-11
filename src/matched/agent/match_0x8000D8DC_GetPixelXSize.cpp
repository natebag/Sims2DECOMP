/* GetPixelXSize(void) at 0x8000D8DC (12B) */
// lis r9, 0x803D; lfs f1, -0x28F4(r9); blr

extern float g_pixelXSize[3];  /* 3-elem forces lis+lfs (not sda21) */

float GetPixelXSize(void) {
    return g_pixelXSize[0];
}
