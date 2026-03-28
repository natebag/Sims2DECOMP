/* 0x8007E790 (16 bytes) - DlgWrapper::GetDialogPadSizeY(void) const */
class DlgWrapper {
public:
    char pad[0xAC];
    int *m_ptr_AC;
    float GetDialogPadSizeY(void) const;
};

float DlgWrapper::GetDialogPadSizeY(void) const {
    int *p = m_ptr_AC;
    int *q = *(int**)((char*)p + 0x64);
    return *(float*)((char*)q + 0x38);
}
