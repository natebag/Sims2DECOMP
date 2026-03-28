typedef unsigned char u8;

void SimImageMaker_Shutdown(u8*);
void EAnimController_dtor(u8*, int);
void __builtin_delete_func(void*);

void SimImageMaker_dtor(u8* pThis, int flags) {
    SimImageMaker_Shutdown(pThis);
    EAnimController_dtor(pThis + 0x10, 2);
    if (flags & 1) {
        __builtin_delete_func(pThis);
    }
}
