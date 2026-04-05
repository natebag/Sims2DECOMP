typedef unsigned char u8;
u8* getHeap_ERMovie__op_new_unsigned_int(void);
u8* allocHeap_ERMovie__op_new_unsigned_int(u8*, u8*, int);
u8* ERMovie__op_new_unsigned_int(unsigned int size) {
    u8* heap = getHeap_ERMovie__op_new_unsigned_int();
    return allocHeap_ERMovie__op_new_unsigned_int(heap, (u8*)(int)size, 0);
}
