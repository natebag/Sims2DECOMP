// 0x801D4F88 filter_wallpaper(WallTile*) (64B)

extern int g_filter_force[16];  // at 0x8047618C — forces non-SDA (lis+lwz)

class WallTile {
public:
    char pad[0x10];
    unsigned char m_10;
};

int filter_wallpaper(WallTile* tile) {
    int result;
    if (tile == 0) {
        result = 0;
        goto end;
    }
    if (g_filter_force[0] != 0) {
        result = 1;
        goto end;
    }
    {
        unsigned char v = tile->m_10;
        result = 1;
        if (v != 0) goto end;
    }
    result = 0;
end:
    return result;
}
