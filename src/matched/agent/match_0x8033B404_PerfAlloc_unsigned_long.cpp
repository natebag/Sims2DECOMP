typedef unsigned char u8;
u8* getHeap_PerfAlloc_unsigned_long(void);
u8* allocHeap_PerfAlloc_unsigned_long(u8*, u8*, int);
u8* PerfAlloc_unsigned_long(unsigned int size) {
    u8* heap = getHeap_PerfAlloc_unsigned_long();
    return allocHeap_PerfAlloc_unsigned_long(heap, (u8*)(int)size, 0);
}
