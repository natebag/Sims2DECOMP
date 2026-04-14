// 0x801520d4 cFixedWorldImpl::SetWallStorage(CTilePt &, TileWallStorage &) (104B)

struct CTilePt {
    int GetX(void) const;
    int GetY(void) const;
};

struct TileWallStorage {
    int m_a;
    int m_b;
};

struct cFixedWorldImpl {
    char pad[0x38];
    void* m_wallGrid;
    void SetWallStorage(CTilePt& tile, TileWallStorage& storage);
};

void cFixedWorldImpl::SetWallStorage(CTilePt& tile, TileWallStorage& storage) {
    void* grid = m_wallGrid;
    int gx = tile.GetX();
    int gy = tile.GetY();
    int* rows = *(int**)((char*)grid + 0x0C);
    TileWallStorage* dest = (TileWallStorage*)((char*)rows[gx] + gy * 8);
    *dest = storage;
}
