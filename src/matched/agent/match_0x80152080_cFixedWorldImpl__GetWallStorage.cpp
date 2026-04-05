// FLAGS: -fno-elide-constructors
typedef unsigned char u8;

int tileConv6(void*);

u8* cFixedWorldImpl_GetWallStorage(u8* self, void* tile) {
    u8* grid = *(u8**)(self + 0x38);
    int gx = tileConv6(tile);
    int gy = tileConv6(tile);
    int* arr = *(int**)(grid + 0x0C);
    return (u8*)(arr[gx] + gy * 8);
}
