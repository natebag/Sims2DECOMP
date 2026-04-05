typedef unsigned char u8;

int tileConv3(void*);

int cFixedWorldImpl_IsOutside(u8* self, void* tile) {
    u8* grid = *(u8**)(self + 0x34);
    int gx = tileConv3(tile);
    int gy = tileConv3(tile);
    int* arr = *(int**)(grid + 0x0C);
    int val = *(u8*)(arr[gx] + gy);
    return (val >> 2) & 1;
}
