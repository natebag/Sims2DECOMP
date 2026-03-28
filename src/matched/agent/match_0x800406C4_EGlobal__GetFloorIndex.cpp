/* EGlobal::GetFloorIndex(FloorTile *) at 0x800406C4 (72B) */

struct FloorTile;

struct FloorArray {
    int *m_data;
};

struct EGlobal {
    char pad[0xD4];
    FloorArray *m_floorArray;
    int GetFloorIndex(FloorTile *tile);
};

int EGlobal::GetFloorIndex(FloorTile *tile) {
    int *arr = m_floorArray->m_data;
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
