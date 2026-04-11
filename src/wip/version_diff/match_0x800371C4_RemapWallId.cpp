extern int s_wallConfigIdMap[6];

int RemapWallId(int segment) {
    for (int i = 0; i < 6; i++) {
        if (s_wallConfigIdMap[i] == segment) {
            return i;
        }
    }
    return -1;
}
