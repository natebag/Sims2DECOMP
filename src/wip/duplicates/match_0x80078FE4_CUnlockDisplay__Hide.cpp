/* 0x80078FE4 (12 bytes) - CUnlockDisplay::Hide(void) */
class CUnlockDisplay {
public:
    char pad[0x458];
    int m_field_458;
    void Hide(void);
};

void CUnlockDisplay::Hide(void) {
    m_field_458 = 1;
}
