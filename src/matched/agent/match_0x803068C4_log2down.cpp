// 0x803068C4 (24B) log2down(int)
// Integer log2 via arithmetic right-shift loop.

int log2down(int x) {
    int count = -1;
    do {
        count++;
        x >>= 1;
    } while (x != 0);
    return count;
}
