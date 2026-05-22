// 0x801D4F88 filter_wallpaper(WallTile*) (64B)
// DOL uses bne-OVER-return layout (not beq-TO-return):
//   mr. r3,r3; bne→global; return0; global: cmpwi; bne→filterFlag; return1; filterFlag: ...
// goto forces the bne-over form for both null and global checks.

struct WallTile {
    char _pad[0x10];
    char m_filterFlag;
};
extern int g_filterWallpaper_801D4F88[4];

int filter_wallpaper(WallTile* tile) {
    if (tile) goto global_check;
    return 0;
global_check:
    if (g_filterWallpaper_801D4F88[0]) goto filterFlag_check;
    return 1;
filterFlag_check:
    {
        char flag = tile->m_filterFlag;
        if (flag) return 1;
        return 0;
    }
}
