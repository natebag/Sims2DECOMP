typedef unsigned char u8;

int tileConv5(void*);

void cFixedWorldImpl_SetFlags(u8* self, void* tile, u8 flags) {
    u8* grid = *(u8**)(self + 0x34);
    int gx = tileConv5(tile);
    int gy = tileConv5(tile);
    int* arr = *(int**)(grid + 0x0C);
    *(u8*)(arr[gx] + gy) = flags;
}
