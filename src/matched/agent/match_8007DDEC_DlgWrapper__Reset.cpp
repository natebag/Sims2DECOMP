typedef unsigned char u8;

void Wrapper_WrapperReset();
void DlgWrapper_ResetBody(u8*);

void DlgWrapper_Reset(u8* pThis) {
    int zero = 0;
    u8* pInner = *(u8**)(pThis + 0xAC);
    *(int*)(pThis + 0xB8) = zero;
    *(int*)(pInner + 0x34) = zero;
    Wrapper_WrapperReset();
    DlgWrapper_ResetBody(pThis);
}
