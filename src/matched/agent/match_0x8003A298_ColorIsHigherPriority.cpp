// 0x8003A298 ColorIsHigherPriority(Interaction::tColor, Interaction::tColor) (72B)
// Final a>b uses mfcr/rlwinm on CR7 set by cmpw cr7,r3,r4 at top

int ColorIsHigherPriority(int a, int b) {
    if (a == b) return 0;
    if (a == 4) return 1;
    if (b == 4) return 0;
    if (a == 0) return 1;
    if (b == 0) return 0;
    return a > b;
}
