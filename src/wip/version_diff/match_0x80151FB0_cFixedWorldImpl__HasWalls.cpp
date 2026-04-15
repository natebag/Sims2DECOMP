// 0x80151FB0 cFixedWorldImpl::HasWalls(CTilePt&, TileWallsSegment) (104B)

struct CTilePt;
extern int tileConv15(CTilePt*);
extern int tileConv16(CTilePt*);

struct cFixedWorldImpl {
    char pad[0x38];
    void* m_wallGrid;
    int HasWalls(CTilePt& tile, int segment);
};

int cFixedWorldImpl::HasWalls(CTilePt& tile, int segment) {
    void* grid = m_wallGrid;
    int gx = tileConv15(&tile);
    int gy = tileConv16(&tile);
    int* rows = *(int**)((char*)grid + 0x0C);
    void* row = (void*)rows[gx];
    unsigned char byte = *(unsigned char*)((int)row + gy * 8);
    return (byte & segment) == segment;
}
