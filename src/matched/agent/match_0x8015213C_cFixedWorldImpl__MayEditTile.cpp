// 0x8015213C cFixedWorldImpl::MayEditTile(CTilePt&) const (112B)

struct CTilePt;
extern int tileConv17(CTilePt*);
extern int tileConv18(CTilePt*);
extern void* g_pBuildModeData;

struct cFixedWorldImpl {
    char pad[0x34];
    void* m_wallGrid;
    int MayEditTile(CTilePt& tile) const;
};

int cFixedWorldImpl::MayEditTile(CTilePt& tile) const {
    if (*(int*)((char*)g_pBuildModeData + 0x3DC) != 0) return 1;
    void* grid = m_wallGrid;
    int gx = tileConv17(&tile);
    int gy = tileConv18(&tile);
    int* arr = *(int**)((char*)grid + 0x0C);
    void* row = (void*)(arr[gx]);
    unsigned char byte = ((unsigned char*)row)[gy];
    return (byte & 0x20) == 0;
}
