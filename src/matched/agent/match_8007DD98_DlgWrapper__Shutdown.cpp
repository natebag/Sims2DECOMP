typedef unsigned char u8;

void DlgWrapper_DialogPaneHide(u8*);
void Wrapper_WrapperShutdown(u8*);
void EResource_DelRef(void*);

void DlgWrapper_Shutdown(u8* pThis) {
    DlgWrapper_DialogPaneHide(pThis);
    Wrapper_WrapperShutdown(pThis);
    void* pRes = *(void**)(pThis + 0xA8);
    if (pRes != 0) {
        EResource_DelRef(pRes);
        *(void**)(pThis + 0xA8) = 0;
    }
    *(int*)(pThis + 0xB0) = 0;
}
