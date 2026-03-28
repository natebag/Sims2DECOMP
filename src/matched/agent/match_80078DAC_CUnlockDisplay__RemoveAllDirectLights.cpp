typedef unsigned char u8;

class CUnlockDisplay {
    u8 _pad0[0x440];
    int m_nNumDirectLights;
public:
    void RemoveAllDirectLights();
};

void CUnlockDisplay::RemoveAllDirectLights() {
    m_nNumDirectLights = 0;
}
