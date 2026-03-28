/* 0x80079C20 (12 bytes) - CUnlockDisplayObject::SetTrigger(void) */
class CUnlockDisplayObject {
public:
    char pad[0x70];
    int m_field_070;
    void SetTrigger(void);
};

void CUnlockDisplayObject::SetTrigger(void) {
    m_field_070 = 1;
}
