/* 0x80078FF0 (12 bytes) - CUnlockDisplay::UnHide(void) */
class CUnlockDisplay {
public:
    char pad[0x458];
    int m_field_458;
    void UnHide(void);
};

void CUnlockDisplay::UnHide(void) {
    m_field_458 = 0;
}
