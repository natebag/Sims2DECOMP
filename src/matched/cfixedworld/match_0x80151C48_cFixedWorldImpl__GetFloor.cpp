/* cFixedWorldImpl::GetFloor(CTilePt &) - 0x80151C48 (80B) */

class CTilePt {
public:
    int GetX(void) const;
    int GetY(void) const;
};

struct FloorGrid {
    char pad[12];
    int* m_rows;
};

class cFixedWorldImpl {
public:
    char pad[44];
    FloorGrid* m_floorGrid;

    int GetFloor(CTilePt& tile);
};

int cFixedWorldImpl::GetFloor(CTilePt& tile) {
    FloorGrid* grid = m_floorGrid;
    int x = tile.GetX();
    int y = tile.GetY();
    int* rows = grid->m_rows;
    char* row = (char*)rows[x];
    return (unsigned char)row[y];
}
