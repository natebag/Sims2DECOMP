/* 0x80078DAC (12 bytes) - CUnlockDisplay::RemoveAllDirectLights(void) */
class CUnlockDisplay {
public:
    char pad[0x440];
    int m_field_440;
    void RemoveAllDirectLights(void);
};

void CUnlockDisplay::RemoveAllDirectLights(void) {
    m_field_440 = 0;
}
