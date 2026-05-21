// 0x80074F2C SimsMemCardWrap::InitPolling (80b)

extern int SimsMemCardWrap_IsCardInSlot(int, int*);

int SimsMemCardWrap_InitPolling() {
    int ret = 1;
    int i = 0;
    while (i <= 1) {
        int local;
        ret = SimsMemCardWrap_IsCardInSlot(i, &local);
        if (ret != 1) {
            break;
        }
        i++;
    }
    return ret;
}
