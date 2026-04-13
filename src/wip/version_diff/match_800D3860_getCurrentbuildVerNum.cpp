/* getCurrentbuildVerNum(int, int, int, int) - 0x800D3860 (32 bytes) */

int getCurrentbuildVerNum(int a, int b, int c, int d) {
    return ((a & 0xFF) << 24) | ((b & 0xFF) << 16) | ((c & 0xFF) << 8) | (d & 0xFF);
}
