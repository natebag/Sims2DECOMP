/* cFixedWorldImpl::GetFlags(CTilePt &) - 0x80151EB8 (80B) */

class CTilePt {
public:
    int GetX(void) const;
    int GetY(void) const;
};

struct FlagsGrid {
    char pad[12];
    int* m_rows;
};

class cFixedWorldImpl {
public:
    char pad[52];
    FlagsGrid* m_flagsGrid;

    int GetFlags(CTilePt& tile);
};

int cFixedWorldImpl::GetFlags(CTilePt& tile) {
    FlagsGrid* grid = m_flagsGrid;
    int x = tile.GetX();
    int y = tile.GetY();
    int* rows = grid->m_rows;
    char* row = (char*)rows[x];
    return (unsigned char)row[y];
}
