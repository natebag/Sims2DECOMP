typedef unsigned char u8;

void EResource_DelRef(void*);
void memset_func(void*, int, int);

void SimImageMaker_Shutdown(u8* pThis) {
    void* pRes = *(void**)(pThis + 0x21C);
    if (pRes != 0) {
        EResource_DelRef(pRes);
        *(void**)(pThis + 0x21C) = 0;
    }
    memset_func(pThis + 0x90, 0, 0x68);
}
