typedef unsigned char u8;

int tileConv(void*);

int cFixedWorldImpl_GetFloor(u8* self, void* tile) {
    u8* grid = *(u8**)(self + 0x2C);
    int gx = tileConv(tile);
    int gy = tileConv(tile);
    int* arr = *(int**)(grid + 0x0C);
    return *(u8*)(arr[gx] + gy);
}
