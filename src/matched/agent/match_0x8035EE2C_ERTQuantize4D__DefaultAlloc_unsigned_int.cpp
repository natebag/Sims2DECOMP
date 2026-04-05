typedef unsigned char u8;
u8* getHeap_ERTQuantize4D__DefaultAlloc_unsigned_int(void);
u8* allocHeap_ERTQuantize4D__DefaultAlloc_unsigned_int(u8*, u8*, int);
u8* ERTQuantize4D__DefaultAlloc_unsigned_int(unsigned int size) {
    u8* heap = getHeap_ERTQuantize4D__DefaultAlloc_unsigned_int();
    return allocHeap_ERTQuantize4D__DefaultAlloc_unsigned_int(heap, (u8*)(int)size, 0);
}
