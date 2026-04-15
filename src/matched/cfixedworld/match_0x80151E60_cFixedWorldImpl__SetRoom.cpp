/* cFixedWorldImpl::SetRoom(CTilePt &, unsigned short) - 0x80151E60 (88B) */

class CTilePt {
public:
    int GetX(void) const;
    int GetY(void) const;
};

struct RoomGrid {
    char pad[12];
    int* m_rows;
};

class cFixedWorldImpl {
public:
    char pad[48];
    RoomGrid* m_roomGrid;

    void SetRoom(CTilePt& tile, unsigned short val);
};

void cFixedWorldImpl::SetRoom(CTilePt& tile, unsigned short val) {
    RoomGrid* grid = m_roomGrid;
    int x = tile.GetX();
    int y = tile.GetY();
    int* rows = grid->m_rows;
    short* row = (short*)rows[x];
    int off = y * 2;
    *(short*)((char*)row + off) = val;
}
