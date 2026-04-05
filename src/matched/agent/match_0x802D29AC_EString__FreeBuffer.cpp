typedef unsigned char u8;
u8* getHeapStr(void);
void freeStr(u8*, u8*);
void EString_FreeBuffer(u8* self, u8* buf) {
    u8* heap = getHeapStr();
    freeStr(heap, buf);
}
