typedef unsigned char u8;

int tileConv2(void*);

int cFixedWorldImpl_GetFlags(u8* self, void* tile) {
    u8* grid = *(u8**)(self + 0x34);
    int gx = tileConv2(tile);
    int gy = tileConv2(tile);
    int* arr = *(int**)(grid + 0x0C);
    return *(u8*)(arr[gx] + gy);
}
