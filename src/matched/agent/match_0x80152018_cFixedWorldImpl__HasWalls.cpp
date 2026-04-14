// 0x80152018 cFixedWorldImpl::HasWalls(CTilePt &) (104B)

struct CTilePt {
    int GetX(void) const;
    int GetY(void) const;
};

struct cFixedWorldImpl {
    char pad[0x38];
    void* m_wallGrid;
    int HasWalls(CTilePt& tile);
};

int cFixedWorldImpl::HasWalls(CTilePt& tile) {
    void* grid = m_wallGrid;
    int gx = tile.GetX();
    int gy = tile.GetY();
    int* rows = *(int**)((char*)grid + 0x0C);
    unsigned char* p = (unsigned char*)rows[gx] + gy * 8;
    unsigned char byte = *p;
    return byte != 0;
}
