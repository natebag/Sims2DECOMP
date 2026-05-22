// 0x801D4F88 filter_wallpaper(WallTile*) (64B)
// DOL: mr. r3,r3; bne+0xc; li r3,0; blr
//      lis r9,-32697; lwz r0,24972(r9); cmpwi r0,0
//      bne+0xc; li r3,1; blr
//      lbz r0,16(r3); li r3,1; cmpwi r0,0; bnelr; li r3,0; blr
// Logic: !tile→0; !global→1; filterFlag!=0→1; →0
// Global @ 0x8047618C, filterFlag @ offset 0x10

struct WallTile {
    char _pad[0x10];
    char m_filterFlag;
};
extern int g_filterWallpaper_801D4F88[4];

int filter_wallpaper(WallTile* tile) {
    if (!tile) return 0;
    if (!g_filterWallpaper_801D4F88[0]) return 1;
    char flag = tile->m_filterFlag;
    if (flag) return 1;
    return 0;
}
