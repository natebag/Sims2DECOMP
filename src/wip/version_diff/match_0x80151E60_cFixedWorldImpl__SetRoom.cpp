// VERSION_DIFF: sthx register allocation (r11 vs r9)
typedef unsigned char u8;
typedef unsigned short u16;

int tileConv4(void*);

void cFixedWorldImpl_SetRoom(u8* self, void* tile, u16 room) {
    u8* grid = *(u8**)(self + 0x30);
    int gx = tileConv4(tile);
    int gy = tileConv4(tile);
    int* arr = *(int**)(grid + 0x0C);
    *(u16*)(arr[gx] + gy * 2) = room;
}
