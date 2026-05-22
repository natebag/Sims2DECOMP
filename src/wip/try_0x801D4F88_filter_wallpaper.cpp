// 0x801D4F88 filter_wallpaper(WallTile*) (64B)
// DOL: beq(filter==null)→flag-body / li r3,1;blr / lbz r0+li r3,1+cmpwi+beqlr+li r3,0+blr
// int ok=1 before load forces lbz r0,16(r3) first (r3=tile needed), then li r3,1 (r3 freed)
struct WallTile {
    char _pad[0x10];
    char m_filterFlag;
};
extern char g_wallpaperFilter[16];

int filter_wallpaper(WallTile* tile) {
    if (!tile) return 0;
    if (!*(void**)g_wallpaperFilter) {
        int ok = 1;
        char flag = tile->m_filterFlag;
        if (flag) ok = 0;
        return ok;
    }
    return 1;
}
