// FLAGS: -fno-schedule-insns
// 0x8007E6D8 (64B) DlgWrapper::SetDialogSizeX(float)
// Store size to self[+196], push to inner->helper[+48/+44], call TextBlock::SetDirty.

class TB_DW {
public:
    void SetDirty(void);
};

class DlgWrapper_DW {
public:
    void SetDialogSizeX(float x);
};

void DlgWrapper_DW::SetDialogSizeX(float x) {
    char* self = (char*)this;
    *(float*)(self + 196) = x;
    void* p = *(void**)(self + 172);
    register int companion asm("r0") = *(int*)(self + 200);
    char* helper = (char*)*(void**)((char*)p + 100);
    register int newSize asm("r10") = *(int*)(self + 196);
    *(int*)(helper + 48) = companion;
    *(int*)(helper + 44) = newSize;
    TB_DW* tb = (TB_DW*)(helper + 32);
    tb->SetDirty();
}
