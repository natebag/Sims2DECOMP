typedef unsigned char u8;

extern int CTGFileImpl_vtable[];

void StringBuffer_StringBuffer(void*, void*, unsigned int);

u8* CTGFileImpl_CTGFileImpl(u8* pThis) {
    *(int**)(pThis + 0x00) = CTGFileImpl_vtable;
    StringBuffer_StringBuffer(pThis + 0x04, pThis + 0x0C, 260);
    *(int*)(pThis + 0x110) = 0;
    return pThis;
}
