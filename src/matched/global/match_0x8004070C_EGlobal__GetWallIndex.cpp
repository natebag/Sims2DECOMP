/* EGlobal::GetWallIndex(WallTile *) at 0x8004070C (72B) */

struct WallTile;

struct WallArray {
    int *m_data;
};

struct EGlobal {
    char pad[0xD8];
    WallArray *m_wallArray;
    int GetWallIndex(WallTile *tile);
};

int EGlobal::GetWallIndex(WallTile *tile) {
    int *arr = m_wallArray->m_data;
    int count = 0;
    if (arr != 0) {
        count = *(arr - 1);
    }
    for (int i = 0; i < count; i++) {
        if (arr[i] == (int)tile) {
            return i;
        }
    }
    return 0;
}
