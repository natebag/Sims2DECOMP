// 0x800406C4 EGlobal::GetFloorIndex(FloorTile*) (72B)

struct IntList {
    int* m_data;
};

struct EGlobal {
    char _pad[212];
    IntList* m_floor;  // at 0xD4
    IntList* m_wall;   // at 0xD8
    IntList* m_fence;  // at 0xDC
    int GetFloorIndex(int* p) const;
};

int EGlobal::GetFloorIndex(int* p) const {
    int count = 0;
    int* data = m_floor->m_data;
    if (data) count = data[-1];
    for (int i = 0; i < count; i++) {
        if (data[i] == (int)p) return i;
    }
    return 0;
}
