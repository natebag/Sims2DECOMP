// 0x801D4F88 filter_wallpaper(WallTile*) (64B)
// DOL logic: null→0; g_flag!=0→1 (beq-to-filterFlag when ==0); filterFlag!=0→1; →0
// DOL branches: bne(null) over return0; beq(flag==0) over return1 to filterFlag check
// Instr 8 = 4182000c = beq (BO=12): flag==0 → branch to filterFlag check; flag!=0 fall-through → return1

struct WallTile {
    char _pad[0x10];
    char m_filterFlag;
};
extern int g_filterWallpaper_801D4F88[4];

int filter_wallpaper(WallTile* tile) {
    if (!tile) return 0;
    if (g_filterWallpaper_801D4F88[0]) return 1;
    char flag = tile->m_filterFlag;
    if (flag) return 1;
    return 0;
}
