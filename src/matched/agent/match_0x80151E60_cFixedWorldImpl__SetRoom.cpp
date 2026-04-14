// 0x80151E60 cFixedWorldImpl::SetRoom (88B)

struct CTilePt;
extern int tileConv7(CTilePt*);
extern int tileConv8(CTilePt*);

struct cFixedWorldImpl {
    char pad[0x30];
    void* m_roomGrid;
    void SetRoom(CTilePt& tile, unsigned short room);
};

void cFixedWorldImpl::SetRoom(CTilePt& tile, unsigned short room) {
    void* grid = m_roomGrid;
    int gx = tileConv7(&tile);
    int gy = tileConv8(&tile);
    int* arr = *(int**)((char*)grid + 0x0C);
    unsigned short* row = (unsigned short*)(arr[gx] + gy * 2);
    *row = room;
}
