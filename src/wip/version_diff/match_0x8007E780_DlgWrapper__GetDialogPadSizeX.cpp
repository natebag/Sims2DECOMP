/* 0x8007E780 (16 bytes) - DlgWrapper::GetDialogPadSizeX(void) const */
class DlgWrapper {
public:
    char pad[0xAC];
    int *m_ptr_AC;
    float GetDialogPadSizeX(void) const;
};

float DlgWrapper::GetDialogPadSizeX(void) const {
    int *p = m_ptr_AC;
    int *q = *(int**)((char*)p + 0x64);
    return *(float*)((char*)q + 0x34);
}
