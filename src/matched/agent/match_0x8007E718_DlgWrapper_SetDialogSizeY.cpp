// PRAGMA_STUB: DlgWrapper::SetDialogSizeY(float)
// FLAGS: -fno-schedule-insns
// 0x8007E718 (64B) DlgWrapper::SetDialogSizeY(float)
// Store size to self[+200], push self[+200]/[+196] to helper[+48/+44], SetDirty.

class TB_DY {
public:
    void SetDirty(void);
};

class DlgWrapper_DY {
public:
    void SetDialogSizeY(float y);
};

void DlgWrapper_DY::SetDialogSizeY(float y) {
    char* self = (char*)this;
    *(float*)(self + 200) = y;
    void* p = *(void**)(self + 172);
    register int newY asm("r0") = *(int*)(self + 200);
    char* helper = (char*)*(void**)((char*)p + 100);
    register int xVal asm("r10") = *(int*)(self + 196);
    *(int*)(helper + 48) = newY;
    *(int*)(helper + 44) = xVal;
    TB_DY* tb = (TB_DY*)(helper + 32);
    tb->SetDirty();
}
