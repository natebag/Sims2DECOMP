/* 0x80151FB0 cFixedWorldImpl::HasWalls(CTilePt&, TileWallsSegment) (104B) */

class CTilePt {
public:
    int GetX(void) const;
    int GetY(void) const;
};

struct WallGrid {
    char pad[12];
    int* m_rows;
};

class cFixedWorldImpl {
public:
    char pad[56];
    WallGrid* m_wallGrid;

    int HasWalls(CTilePt& tile, int segment);
};

int cFixedWorldImpl::HasWalls(CTilePt& tile, int segment) {
    WallGrid* grid = m_wallGrid;
    int x = tile.GetX();
    int y = tile.GetY();
    int* rows = grid->m_rows;
    char* row = (char*)rows[x];
    int off = y * 8;
    unsigned char byte = (unsigned char)row[off];
    return (byte & segment) == segment;
}
