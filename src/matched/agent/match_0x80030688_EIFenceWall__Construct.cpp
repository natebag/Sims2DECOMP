typedef unsigned char u8;
u8* allocObj(int, u8*);
u8* initObj(u8*);
u8* EIFenceWall_Construct(u8* ptr) {
    u8* obj = allocObj(952, ptr);
    return initObj(obj);
}
