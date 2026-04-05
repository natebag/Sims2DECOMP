typedef unsigned char u8;

u8* getMainHeap(void);
u8* allocFromHeap(u8*, u8*, int);

u8* Default2dArrayAlloc(unsigned int size) {
    u8* heap = getMainHeap();
    return allocFromHeap(heap, (u8*)(int)size, 0);
}
