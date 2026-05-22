// 0x801D4F88 filter_wallpaper(WallTile*) (64B)
// FLAGS: -msdata=eabi -G 8
// goto forces: beq-to-filterFlag + li-r3-1-blr layout BEFORE filterFlag block
// anti_tail_merge splits the merged null/filterFlag-miss return0 into two

struct WallTile {
    char _pad[0x10];
    char m_filterFlag;
};
extern int g_filterWallpaper_801D4F88[4];

int filter_wallpaper(WallTile* tile) {
    if (!tile) return 0;
    if (!g_filterWallpaper_801D4F88[0]) goto filterFlag;
    return 1;
filterFlag:
    char flag = tile->m_filterFlag;
    if (flag) return 1;
    return 0;
}
